#include "Funzioni.h"
#include <stdio.h>

// aggiunge la persona p nel vettore di interi a cui puntano i v_i, sono vettori ma si visualizzano come matrici con MaxNumBuildings colonne e MaxPersons righe
void AddToList(Persona *p, Edificio *e, int NumBuildings){
    Organize *OV;
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

    int id = p->GetID();
    int civico = p->GetLoc() - 1;
    int *v;
    int fNumMax = e->GetNumMax();
    if(e->GetTypeEdif() == p->GetType() && e->GetIDEdif() == p->GetLoc()){
      if(p->GetType() == 0 ){
        int j;
        if(p->GetAge() == 1){j = 0;}
        else if(p->GetAge() == 2){j = 1;}
        else if(p->GetAge() == 3){j = 2;}
        else{j = 3;}
        v=&v_0[j*NumBuildings+civico];
        *v = id;
      }
      if(p->GetType() == 1){
        civico = civico - MaxNumBuildings[0];
        int j=p->GetOrder();
        v=&v_1[j*NumBuildings+civico];
        *v = id;
      }
      if(p->GetType() == 2){
        for(int i=0; i<2; i++){
          civico = civico - MaxNumBuildings[i];
        }
        int j=p->GetOrder();
        v=&v_2[j*NumBuildings+civico];
        *v = id;
      }
      if(p->GetType() == 3){
        for(int i=0; i<3; i++){
          civico = civico - MaxNumBuildings[i];
        }
        for(int j=0; j<fNumMax; j++){
          v=&v_3[j*NumBuildings+civico];
          if(*v == 0){*v = id; break;}
          }
      }
      if(p->GetType() == 4){
        for(int i=0; i<4; i++){
          civico = civico - MaxNumBuildings[i];
        }
        for(int j=0; j<fNumMax; j++){
          v=&v_4[j*NumBuildings+civico];
          if(*v == 0){*v = id; break;}
          }
      }
      if(p->GetType() == 5){
        for(int i=0; i<5; i++){
          civico = civico - MaxNumBuildings[i];
        }
        for(int j=0; j<fNumMax; j++){
          v=&v_5[j*NumBuildings+civico];
          if(*v == 0){*v = id; break;}
          }
      }
      if(p->GetType() == 6){
        for(int i=0; i<6; i++){
          civico = civico - MaxNumBuildings[i];
        }
        for(int j=0; j<fNumMax; j++){
          v=&v_6[j*NumBuildings+civico];
          if(*v == 0){*v = id; break;}
          }
      }
      if(p->GetType() == 7){
        for(int i=0; i<7; i++){
          civico = civico - MaxNumBuildings[i];
        }
        for(int j=0; j<fNumMax; j++){
          v=&v_7[j*NumBuildings+civico];
          if(*v == 0){*v = id; break;}
          }
      }
      if(p->GetType() == 8){
        for(int i=0; i<8; i++){
          civico = civico - MaxNumBuildings[i];
        }
        for(int j=0; j<fNumMax; j++){
          v=&v_8[j*NumBuildings+civico];
          if(*v == 0){*v = id; break;}
          }
      }
    }
  }
//________________________________________________________________
//pulisce array di ID di persone (interi) associato ad ogni tipo di locale
void ClearArray(){
  int *v;
  Organize *OV;
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

  for(int k=0; k<9; k++){
    for(int i=0; i<MaxPersons[k]; i++){
      for(int j=0; j<MaxNumBuildings[k]; j++){
        if(k == 0){v = &v_0[i*MaxNumBuildings[0]+j];}
        else if(k == 1){v = &v_1[i*MaxNumBuildings[1]+j];}
        else if(k == 2){v = &v_2[i*MaxNumBuildings[2]+j];}
        else if(k == 3){v = &v_3[i*MaxNumBuildings[3]+j];}
        else if(k == 4){v = &v_4[i*MaxNumBuildings[4]+j];}
        else if(k == 5){v = &v_5[i*MaxNumBuildings[5]+j];}
        else if(k == 6){v = &v_6[i*MaxNumBuildings[6]+j];}
        else if(k == 7){v = &v_7[i*MaxNumBuildings[7]+j];}
        else{v = &v_8[i*MaxNumBuildings[8]+j];}
        *v = 0;
      }
    }
  }
}
//_________________________________________________________________
//azzera i SEIRD[i]
void ClearSEIRD(){
  Organize *OSEIRDc = Organize::SEIRDcounterInstance();
  int *SEIRD = OSEIRDc->GetSEIRD();

  for(int i=0; i<5; i++){
    SEIRD[i] = 0;
  }
}
//_________________________________________________________________
//azzera i vettori S0, E0, I0, R0, D0
void ClearHists(){
  Organize *OSEIRD = Organize::SEIRDInstance();

  int *S0=OSEIRD->GetS0();
  int *E0=OSEIRD->GetE0();
  int *I0=OSEIRD->GetI0();
  int *R0=OSEIRD->GetR0();
  int *D0=OSEIRD->GetD0();
  for(int i=0; i<4; i++){
    S0[i] = 0 ;
    E0[i] = 0 ;
    I0[i] = 0 ;
    R0[i] = 0 ;
    D0[i] = 0 ;
  }
}
//_________________________________________________________________
//ricerca tra tutta la popolazione creata, la persona con uno specifico ID e restituisce l'età
int GetAgeFromID(int id, int N, int InfectPopulation){
  Organize *Opop = Organize::PopInstance(InfectPopulation);
  Persona *pop = Opop->GetPop();

  int i=0;
  Persona *pp;
  do{
    pp = &pop[i];
    ++i;
  }while(pp->GetID() != id && i<N);
  return pp->GetAge();
}
//_________________________________________________________________
//ricerca tra tutta la popolazione creata, la persona con uno specifico ID e restituisce lo stato
int GetStatusFromID(int id, int N, int InfectPopulation){
  Organize *Opop = Organize::PopInstance(InfectPopulation);
  Persona *pop = Opop->GetPop();

  int i=0;
  Persona *pp;
  do{
    pp = &pop[i];
    ++i;
  }while(pp->GetID() != id && i<N);
  return pp->GetStatus();
}
//__________________________________________________________________________
//cambia lo stato di una persona in base
void ChangeStatusPersons(int *N, int typeLoc, int civico, int NumPopulation, int InfectPopulation){
  int *v;
  Organize *Opop = Organize::PopInstance(InfectPopulation);
  Persona *pop = Opop->GetPop();
  Organize *OV;
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

  Organize *OSEIRDc = Organize::SEIRDcounterInstance();
  int *SEIRD = OSEIRDc->GetSEIRD();

//costanti del modello
  static const double inverse_delta = 0.285;
  static const double R_0 = 2.6;
  double beta;
  double d;

  int age;
  int status;
  int id;
  Persona *pp;

  double s0 = double(SEIRD[0])/double(*N);
  double e0 = double(SEIRD[1])/double(*N);
  double i0 = double(SEIRD[2])/double(*N);
  double r0 = double(SEIRD[3])/double(*N);
  double d0 = double(SEIRD[4])/double(*N);

  //ciclo su tutte le celle degli array di interi in base al tipo di locale considerato che contengono gli ID delle persone che si trovano in quel locale
  for(int i=0; i<MaxPersons[typeLoc]; i++){
    if(typeLoc == 0){v = &v_0[i*MaxNumBuildings[0]+civico];}
    else if(typeLoc == 1){v = &v_1[i*MaxNumBuildings[1]+civico];}
    else if(typeLoc == 2){v = &v_2[i*MaxNumBuildings[2]+civico];}
    else if(typeLoc == 3){v = &v_3[i*MaxNumBuildings[3]+civico];}
    else if(typeLoc == 4){v = &v_4[i*MaxNumBuildings[4]+civico];}
    else if(typeLoc == 5){v = &v_5[i*MaxNumBuildings[5]+civico];}
    else if(typeLoc == 6){v = &v_6[i*MaxNumBuildings[6]+civico];}
    else{v = &v_7[i*MaxNumBuildings[7]+civico];}

    //se il contenuto della cella non è nullo, a partire dall'ID si ricava l'età e lo stato della persona
    if(*v != 0){
      id = *v;
      age = GetAgeFromID(id, NumPopulation, InfectPopulation);
      status = GetStatusFromID(id, NumPopulation, InfectPopulation);
      if(age == 1){d = 0.001;}
      else if(age == 2){d = 0.0025;}
      else if(age == 3){d = 0.02;}
      else{d = 0.06;}

      //dipendenza di beta da età e da tipo di locale
      double arrayBeta[4][8] = {
          {0.08, 0.2,  0.2,  0.2,  0.2,  0.2, 0.1, 0.3},
          {0.08, 0.15, 0.15, 0.15, 0.15, 0.1, 0.1, 0.3},
          {0.08, 0.15, 0.15, 0.15, 0.15, 0.1, 0.1, 0.3},
          {0.08, 0.1,  0.1,  0.1,  0.1,  0.1, 0.1, 0.2}};

      beta = arrayBeta[age-1][typeLoc];
      double gamma = beta/R_0;

      int tmin = 1; //in unità di 30 minuti
      double a = gRandom->Rndm();
      //variazione dello stato dovuto solo agli altri stati
      double percE = beta*s0*i0;
      double percI = e0 * inverse_delta;
      double percR = i0 * gamma * (1-d);
      double percD = i0 * gamma * d;

      switch(status){
        case(0):
        for(int k=0; k<NumPopulation; k++){
          pp = &pop[k];
          if(pp->GetID() == id){
            if(a<=percE){pp->ChangeStatus(1);}
          }
        }
        break;

        case(1):
        for(int k=0; k<NumPopulation; k++){
          pp = &pop[k];
          if(pp->GetID() == id){
            if(a<=percI){pp->ChangeStatus(2);}
          }
        }
        break;

        case(2):
        for(int k=0; k<NumPopulation; k++){
          pp = &pop[k];
          if(pp->GetID() == id){
            if(a<=percR){pp->ChangeStatus(3);}
            else if(a>percR && a<= percR+percD){pp->ChangeStatus(4);}
          }
        }
        break;
      }
    }
  }
  *N = 0;
}
//__________________________________________________________________________
// cicla su tutti gli ID di persone all'interno dei vettori di interi v_i e incrementa di 1 SEIRD[0] se la persona è Susceptible, oppure SEIRD[1] se la persona è Exposed, oppure SEIRD[2] se la persona è Infected e così via ... in modo da conoscere quante persone per ogni stato ci sono all'interno di ogni locale
void FillSEIRD(int *c, int typeLoc, int civico, int NumPopulation, int InfectPopulation){
  int *v;
  Organize *OV;
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

  Organize *OSEIRDc = Organize::SEIRDcounterInstance();
  int *SEIRD = OSEIRDc->GetSEIRD();

  for(int i=0; i<MaxPersons[typeLoc]; i++){
    if(typeLoc == 0){v = &v_0[i*MaxNumBuildings[0]+civico];}
    else if(typeLoc == 1){v = &v_1[i*MaxNumBuildings[1]+civico];}
    else if(typeLoc == 2){v = &v_2[i*MaxNumBuildings[2]+civico];}
    else if(typeLoc == 3){v = &v_3[i*MaxNumBuildings[3]+civico];}
    else if(typeLoc == 4){v = &v_4[i*MaxNumBuildings[4]+civico];}
    else if(typeLoc == 5){v = &v_5[i*MaxNumBuildings[5]+civico];}
    else if(typeLoc == 6){v = &v_6[i*MaxNumBuildings[6]+civico];}
    else if(typeLoc == 7){v = &v_7[i*MaxNumBuildings[7]+civico];}
    else{v = &v_8[i*MaxNumBuildings[8]+civico];}

    if(*v != 0){
      ++*c;
      int id = *v;
      int age = GetAgeFromID(id, NumPopulation, InfectPopulation);
      int status = GetStatusFromID(id, NumPopulation, InfectPopulation);

      if(status == 0){++SEIRD[0];}
      else if(status == 1){++SEIRD[1];}
      else if(status == 2){++SEIRD[2];}
      else if(status == 3){++SEIRD[3];}
      else{++SEIRD[4];}

    }
  }
}
//__________________________________________________________________________
//cicla su tutti gli edifici dello stesso tipo, riempie i SEIRD, cambia lo stato delle persone e azzera i SEIRD
    void CompStatus(int typeLoc, int NumPopulation, int tmax, int InfectPopulation){
      Organize *Ocity = Organize::CityInstance();
      int MaxNumBuildings[9];
      for(int i=0; i<9; i++){
        MaxNumBuildings[i] = Ocity->GetMaxNumBuildings(i);
      }

        int count = 0;
        int *c;
        c = &count;
        for(int time=1; time<=tmax; time++){
          for(int civico=0; civico<MaxNumBuildings[typeLoc]; civico++){
              FillSEIRD(c, typeLoc, civico, NumPopulation, InfectPopulation);
              ChangeStatusPersons(c, typeLoc, civico, NumPopulation, InfectPopulation);
              ClearSEIRD();
            }
        }
      }
//________________________________________________________________________
//cicla su tulla la popolazione e incrementa i vettori S0, E0, I0, R0, D0 in base all'età e allo stato delle persone
void FillforHists(int NumPopulation, int InfectPopulation){
  Persona *pp;
  Organize *OSEIRD = Organize::SEIRDInstance();
  int *S0=OSEIRD->GetS0();
  int *E0=OSEIRD->GetE0();
  int *I0=OSEIRD->GetI0();
  int *R0=OSEIRD->GetR0();
  int *D0=OSEIRD->GetD0();
  Organize *Opop = Organize::PopInstance(InfectPopulation);
  Persona *pop = Opop->GetPop();
      for(int i=0; i<NumPopulation; i++){
        pp = &pop[i];
        int age = pp->GetAge();
        int status = pp->GetStatus();

          if(status == 0){++S0[age-1];}
          else if(status == 1){++E0[age-1];}
          else if(status == 2){++I0[age-1];}
          else if(status == 3){++R0[age-1];}
          else{++D0[age-1];}
        }
}
