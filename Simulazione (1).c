#include <stdio.h>
#include <iostream>
#include "TObject.h"
#include "Funzioni.h"
#include <TCanvas.h>
#include <TFile.h>
#include <TH1I.h>
#include <TStyle.h>
using namespace std;

/*Per la simulazione è stato usato il modello SEIRD per descrivere la diffusione di Covid-19 in base a 4 differenti età:
Bambini, Giovani, Adulti e Anziani*/

void Simulazione(int InfectPopulation, int NumDays) {
//Viene creata la città e la popolazione e vengono istanziati i vettori degli edifici e degli stati
    Organize *Opop = Organize::PopInstance(InfectPopulation);
    Organize *OEdif = Organize::CityInstance();
    Organize *OSEIRD = Organize::SEIRDInstance();
    Organize *OSEIRDc = Organize::SEIRDcounterInstance();
    Organize *OV;

    Persona *pop = Opop->GetPop();
    Edificio *city = OEdif->GetCity();
    int NumPopulation = Opop->GetNumPopulation();
    int m = OEdif->GetM();

    int *S0=OSEIRD->GetS0();
    int *E0=OSEIRD->GetE0();
    int *I0=OSEIRD->GetI0();
    int *R0=OSEIRD->GetR0();
    int *D0=OSEIRD->GetD0();
    int *SEIRD = OSEIRDc->GetSEIRD();

    for(int i=0; i<9; i++){
      OV = Organize::VInstance(i);
    }

    int *v_0 = OV->GetV0();
    int *v_1 = OV->GetV1();
    int *v_2 = OV->GetV2();
    int *v_3 = OV->GetV3();
    int *v_4 = OV->GetV4();
    int *v_5 = OV->GetV5();
    int *v_6 = OV->GetV6();
    int *v_7 = OV->GetV7();
    int *v_8 = OV->GetV8();
    int MaxPersons[9];
    int MaxNumBuildings[9];
    for(int i=0; i<9; i++){
      MaxPersons[i] = OV-> GetMaxPersons(i);
      MaxNumBuildings[i] = OV->GetMaxNumBuildings(i);
    }


    Persona *pp;
    Edificio *pe;
    bool f;
    int *v;
    int tmax;
    int seed = 3227;
    gRandom->SetSeed(seed);

    for(int j=0; j<m; j++){
      pe=&city[j];
      pe->ClearCounter();
    }

    //Inizializzazione dei luoghi di lavoro per gli adulti, ci si è premurati di distribuirli equamente tra le scuole
    int c=0;
    for(int i=NumPopulation/2; i<3*(NumPopulation/4); i++){
      pp = &pop[i];
      pp->InitializeWork();
      pp->InitializeLocation(NumPopulation);
      if(pp->GetType()==1){
        for(int i=0; i<c; i++){
          pp->ChangeLocation();
        }
        c++;
        if(c==MaxNumBuildings[1]){c=0;}
        for(int j=0; j<m; j++){
            pe=&city[j];
            if(pe->GetIDEdif() == pp->GetLoc()){
              int NumBuildings = pe->NumBuildings(NumPopulation);
              pe->AddToList(pp);
              AddToList(pp, pe, NumBuildings);
              pp->SetWorkID();
              pp->SetOrder(pe->GetCounter()-1);
            }
          }
        }
      else{
        for(int j=0; j<m; j++){
            pe=&city[j];
            if(pe->GetIDEdif() == pp->GetLoc()){
                int NumBuildings = pe->NumBuildings(NumPopulation);
                f = pe->CheckAvailability();
                if(f == 0) {
                    pp->ChangeLocation();
                }
               else{
                 pe->AddToList(pp);
                 AddToList(pp, pe, NumBuildings);
                 pp->SetWorkID();
                 pp->SetOrder(pe->GetCounter()-1);
                 break;
               }
             }
        }
      }
    }
    //Inizializzazione dei luoghi di lavoro per i bambini e i giovani
    for(int i=0; i<NumPopulation/2; i++){
      pp = &pop[i];
      pp->InitializeWork();
      pp->InitializeLocation(NumPopulation);
      for(int j=0; j<m; j++){
          pe=&city[j];
          if(pe->GetIDEdif() == pp->GetLoc()){
              int NumBuildings = pe->NumBuildings(NumPopulation);
              f = pe->CheckAvailability();
              if(f == 0) {
                  pp->ChangeLocation();
              }
             else{
               pe->AddToList(pp);
               AddToList(pp, pe, NumBuildings);
               pp->SetWorkID();
               pp->SetOrder(pe->GetCounter()-1);
               break;
             }
           }
      }
    }

    //Vengono riinizializzate le persone nelle loro case.
    ClearArray();
    for(int j=0; j<m; j++){
      pe=&city[j];
      pe->ClearCounter();
    }

      for (int i=0; i<NumPopulation; i++) {
          pp=&pop[i];
          pp->Backhome();
          for(int j=0; j<m; j++){
            pe=&city[j];
            int NumBuildings = pe->NumBuildings(NumPopulation);
            AddToList(pp, pe, NumBuildings);
          }
        }


    TH1I *histCs = new TH1I("histCs","Susceptible Children ",  NumDays-0.5, -0.5, NumDays);
    TH1I *histCe = new TH1I("histCe","Exposed Children ",  NumDays-0.5, -0.5, NumDays);
    TH1I *histCi = new TH1I("histCi","Infected Children ",  NumDays-0.5, -0.5, NumDays);
    TH1I *histCr = new TH1I("histCr","Ricovered Children ",  NumDays-0.5, -0.5, NumDays);
    TH1I *histCd = new TH1I("histCd","Death Children ",  NumDays-0.5, -0.5, NumDays);

    TH1I *histYs = new TH1I("histYs","Susceptible Young Adults",  NumDays-0.5, -0.5, NumDays);
    TH1I *histYe = new TH1I("histYe","Exposed Young Adults ",  NumDays-0.5, -0.5, NumDays);
    TH1I *histYi = new TH1I("histYi","Infected Young Adults ",  NumDays-0.5, -0.5, NumDays);
    TH1I *histYr = new TH1I("histYr","Ricovered Young Adults ",  NumDays-0.5, -0.5, NumDays);
    TH1I *histYd = new TH1I("histYd","Death Young Adults ",  NumDays-0.5, -0.5, NumDays);

    TH1I *histAs = new TH1I("histAs","Susceptible Adults ",  NumDays-0.5, -0.5, NumDays);
    TH1I *histAe = new TH1I("histAe","Exposed Adults ",  NumDays-0.5, -0.5, NumDays);
    TH1I *histAi = new TH1I("histAi","Infected Adults ",  NumDays-0.5, -0.5, NumDays);
    TH1I *histAr = new TH1I("histAr","Ricovered Adults ",  NumDays-0.5, -0.5, NumDays);
    TH1I *histAd = new TH1I("histAd","Death Adults ",  NumDays-0.5, -0.5, NumDays);

    TH1I *histEs = new TH1I("histEs","Susceptible Elderly ",  NumDays-0.5, -0.5, NumDays);
    TH1I *histEe = new TH1I("histEe","Exposed Elderly ",  NumDays-0.5, -0.5, NumDays);
    TH1I *histEi = new TH1I("histEi","Infected Elderly ",  NumDays-0.5, -0.5, NumDays);
    TH1I *histEr = new TH1I("histEr","Ricovered Elderly ",  NumDays-0.5, -0.5, NumDays);
    TH1I *histEd = new TH1I("histEd","Death Elderly ",  NumDays-0.5, -0.5, NumDays);

    FillforHists( NumPopulation, InfectPopulation);
    //I vettori S0[4], E0[4], I0[4], R0[4], D0[4] sono creati per inserirli nei rispettivi istogrammi in base alle età

    //Riempimento delle condizioni iniziali
    histCs->AddBinContent(0, S0[0]);
    histCe->AddBinContent(0, E0[0]);
    histCi->AddBinContent(0, I0[0]);
    histCr->AddBinContent(0, R0[0]);
    histCd->AddBinContent(0, D0[0]);

    histYs->AddBinContent(0, S0[1]);
    histYe->AddBinContent(0, E0[1]);
    histYi->AddBinContent(0, I0[1]);
    histYr->AddBinContent(0, R0[1]);
    histYd->AddBinContent(0, D0[1]);

    histAs->AddBinContent(0, S0[2]);
    histAe->AddBinContent(0, E0[2]);
    histAi->AddBinContent(0, I0[2]);
    histAr->AddBinContent(0, R0[2]);
    histAd->AddBinContent(0, D0[2]);

    histEs->AddBinContent(0, S0[3]);
    histEe->AddBinContent(0, E0[3]);
    histEi->AddBinContent(0, I0[3]);
    histEr->AddBinContent(0, R0[3]);
    histEd->AddBinContent(0, D0[3]);

    ClearHists();

    for(int day=1; day<=NumDays; day++){
      cout<<"DAY  "<<day<<endl;
      //La giornata inizia alle 6 di mattina, vengono azzerati i vettori corrispondenti agli edifici (inizializzati in Organize.C insieme agli altri vettori utili alla simulazione)
      //e riempiti con AddToList() in base alla posizione delle persone
          ClearArray();
          for(int i=0; i<NumPopulation; i++){
            pp = &pop[i];
            for(int j=0; j<m; j++){
              pe = &city[j];
              int NumBuildings = pe->NumBuildings(NumPopulation);
              AddToList(pp, pe, NumBuildings);
            }
          }

          cout<<"Calcolo dei contagi in casa"<<endl;

          tmax = 4; //in unità di mezz'ora
          for(int k=0; k<=7; k++){
            CompStatus(k, NumPopulation, tmax, InfectPopulation);
          }


          //MATTINA : Le Persone scelgono un edificio in cui passare la mattina, dalle 8 alle 14, vengono prima riazzerati i vettori
          //degli edifici e riempiti nuovamente, si calcolano poi gli stati con la funzione CompStatus()
                ClearArray();
                for(int j=0; j<m; j++){
                    pe=&city[j];
                    pe->ClearCounter();
                }

                cout<<"Movimento di mattina"<<endl;

                for (int i=0; i<NumPopulation; i++) {
                  pp=&pop[i];
                  pp->ChangeBuildingMorning();
                  pp->InitializeLocationW(NumPopulation);
                  if(pp->GetType()==0 || pp->GetType()==1 || pp->GetType()==2 ){
                    for(int j=0; j<m; j++){
                        pe=&city[j];
                        int NumBuildings = pe->NumBuildings(NumPopulation);
                        AddToList(pp, pe, NumBuildings);
                      }
                  }
                  else{
                     for(int j=0; j<m; j++){
                         pe=&city[j];
                         if(pe->GetIDEdif() == pp->GetLoc()){
                             int NumBuildings = pe->NumBuildings(NumPopulation);
                             f = pe->CheckAvailability();
                             if(f == 0) {
                                 pp->ChangeLocation();
                             }
                            else{
                              pe->AddToList(pp);
                              AddToList(pp, pe, NumBuildings);
                              break;
                            }
                          }
                         }
                     }
                   }

                  cout<<"Calcolo dei contagi della mattina"<<endl;

                  tmax = 6;
                  for(int k=0; k<=7; k++){
                    CompStatus(k, NumPopulation, tmax, InfectPopulation);
                  }


                //POMERIGGIO : Le persone cambiano posizione ogni due ore tra le 14 e le 20, i passaggi sono analoghi a quelli della mattina
                for(int i=0; i<3; i++){
                    ClearArray();
                    for(int j=0; j<m; j++){
                          pe=&city[j];
                          pe->ClearCounter();
                    }

                    cout<<"Movimento di pomeriggio"<<endl;

                for (int i=0; i<NumPopulation; i++) {
                    pp=&pop[i];
                    pp->ChangeBuildingAfternoon();
                    pp->InitializeLocationW(NumPopulation);

                    if(pp->GetType()==0 || pp->GetType()==1 || pp->GetType()==2 ){
                      for(int j=0; j<m; j++){
                          pe=&city[j];
                          int NumBuildings = pe->NumBuildings(NumPopulation);
                          AddToList(pp, pe, NumBuildings);
                        }
                    }
                    else{
                       for(int j=0; j<m; j++){
                           pe=&city[j];
                           if(pe->GetIDEdif() == pp->GetLoc()){
                               int NumBuildings = pe->NumBuildings(NumPopulation);
                               f = pe->CheckAvailability();
                               if(f == 0) {
                                   pp->ChangeLocation();
                               }
                              else{
                                pe->AddToList(pp);
                                AddToList(pp, pe, NumBuildings);
                                break;
                              }
                            }
                           }
                       }
                }


                cout<<"Calcolo dei contagi di pomeriggio"<<endl;

                tmax = 4; //in unità di mezz'ora
                for(int k=0; k<=7; k++){
                  CompStatus(k, NumPopulation, tmax, InfectPopulation);
                }
              }

              //NOTTE: Le persone rientrano a casa e vi restano dalle 20 alle 6
                    ClearArray();
                    for(int j=0; j<m; j++){
                      pe=&city[j];
                      pe->ClearCounter();
                    }

                    cout<<"Ritorno a casa"<<endl;

                      for (int i=0; i<NumPopulation; i++) {
                          pp=&pop[i];
                          pp->Backhome();
                          for(int j=0; j<m; j++){
                            pe=&city[j];
                            int NumBuildings = pe->NumBuildings(NumPopulation);
                            AddToList(pp, pe, NumBuildings);
                          }
                        }

                        cout<<"Calcolo dei contagi in casa"<<endl;

                        tmax = 20; //in unità di mezz'ora
                        for(int k=0; k<=7; k++){
                          CompStatus(k, NumPopulation, tmax, InfectPopulation);
                        }



                  //CALCOLO SEIRD DELLA GIORNATA
                  int count = 0;
                  int *c;
                  c = &count;
                  for(int k=0; k<=8; k++){
                    for(int civico=0; civico<MaxNumBuildings[k]; civico++){
                        FillSEIRD(c, k, civico, NumPopulation, InfectPopulation);
                    }
                  }
                  cout<<"s "<<SEIRD[0]<<", e "<<SEIRD[1]<<", i "<<SEIRD[2]<<", r "<<SEIRD[3]<<", d "<<SEIRD[4]<<endl;

                  FillforHists( NumPopulation, InfectPopulation);
                  //I vettori S0[4], E0[4], I0[4], R0[4], D0[4] sono creati per inserirli nei rispettivi istogrammi in base alle età

                  //Vengono riempiti gli istogrammi per ogni età e per i vari stati
                  histCs->AddBinContent(day, S0[0]);
                  histCe->AddBinContent(day, E0[0]);
                  histCi->AddBinContent(day, I0[0]);
                  histCr->AddBinContent(day, R0[0]);
                  histCd->AddBinContent(day, D0[0]);

                  histYs->AddBinContent(day, S0[1]);
                  histYe->AddBinContent(day, E0[1]);
                  histYi->AddBinContent(day, I0[1]);
                  histYr->AddBinContent(day, R0[1]);
                  histYd->AddBinContent(day, D0[1]);

                  histAs->AddBinContent(day, S0[2]);
                  histAe->AddBinContent(day, E0[2]);
                  histAi->AddBinContent(day, I0[2]);
                  histAr->AddBinContent(day, R0[2]);
                  histAd->AddBinContent(day, D0[2]);

                  histEs->AddBinContent(day, S0[3]);
                  histEe->AddBinContent(day, E0[3]);
                  histEi->AddBinContent(day, I0[3]);
                  histEr->AddBinContent(day, R0[3]);
                  histEd->AddBinContent(day, D0[3]);

                  ClearHists();


}
//Tutti gli istogrammi sono salvati su file per essere graficati con la macro HistsSEIRD.C
TFile *file = new TFile("isto40000.root","recreate");
histCs->Write();
histCe->Write();
histCi->Write();
histCr->Write();
histCd->Write();

histYs->Write();
histYe->Write();
histYi->Write();
histYr->Write();
histYd->Write();

histAs->Write();
histAe->Write();
histAi->Write();
histAr->Write();
histAd->Write();

histEs->Write();
histEe->Write();
histEi->Write();
histEr->Write();
histEd->Write();

file->Close();
//Vengono distrutti tutti i vettori allocati sull'heap
delete[] pop;
delete[] city;
delete[] v_0;
delete[] v_1;
delete[] v_2;
delete[] v_3;
delete[] v_4;
delete[] v_5;
delete[] v_6;
delete[] v_7;
delete[] v_8;
Opop->Destroy();
OEdif->Destroy();
OSEIRD->Destroy();
OSEIRDc->Destroy();
OV->Destroy();
}
