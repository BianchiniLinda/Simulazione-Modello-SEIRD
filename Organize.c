#include "Organize.h"
#include <iostream>
#include "TRandom3.h"
// #include "Persona.h"
// #include "Edificio.h"


ClassImp(Organize);


//inizializzazione dei puntatori e dei vettori static dichiarati come data members
Organize* Organize::fgPopInstance = 0x0;
Organize* Organize::fgCityInstance = 0x0;
Organize* Organize::fgV0Instance = 0x0;
Organize* Organize::fgV1Instance = 0x0;
Organize* Organize::fgV2Instance = 0x0;
Organize* Organize::fgV3Instance = 0x0;
Organize* Organize::fgV4Instance = 0x0;
Organize* Organize::fgV5Instance = 0x0;
Organize* Organize::fgV6Instance = 0x0;
Organize* Organize::fgV7Instance = 0x0;
Organize* Organize::fgV8Instance = 0x0;
Organize* Organize::fgSEIRDInstance = 0x0;
Organize* Organize::fgSEIRDcounterInstance = 0x0;


int Organize::fMaxPersons[9]={4, 150, 50, 30, 150, 200, 300, 30, fNumPopulation};
int Organize::fMaxNumBuildings[9]={fNumPopulation/4, fNumPopulation/160, fNumPopulation/160, fNumPopulation/160, fNumPopulation/300, fNumPopulation/200, fNumPopulation/300, fNumPopulation/200, fNumPopulation};

Persona* Organize::fPop = 0x0;
Edificio* Organize::fCity = 0x0;
int* Organize::fv_0 = 0x0;
int* Organize::fv_1 = 0x0;
int* Organize::fv_2 = 0x0;
int* Organize::fv_3 = 0x0;
int* Organize::fv_4 = 0x0;
int* Organize::fv_5 = 0x0;
int* Organize::fv_6 = 0x0;
int* Organize::fv_7 = 0x0;
int* Organize::fv_8 = 0x0;
int* Organize::fS0 = 0x0;
int* Organize::fE0 = 0x0;
int* Organize::fI0 = 0x0;
int* Organize::fR0 = 0x0;
int* Organize::fD0 = 0x0;
int* Organize::fSEIRD = 0x0;
//______________________________________________________________________
Organize::Organize():TObject(){
  // Default constructor
}


//______________________________________________________________________
Organize::~Organize(){
  // Destructor
}

//___________________________________________________________________
void Organize::SetPop(int InfectPopulation)
{
   Persona* pp;
   int j=0;
   int a[InfectPopulation];
   int b;
   while(j<InfectPopulation){
       a[j]=int(round(gRandom->Rndm()*fNumPopulation));
       j++;
   }

   int i=1;
   while(i <= fNumPopulation){
     pp=&fPop[i-1];
       if(i <= fNumPopulation/4){
          pp->ChangeParametersBeginning(i, 1, 0, i, 0, 0, 0, i);// int id, int age, int status, int home, int work, int order, int type, int locazione
       }
       else if(i > fNumPopulation/4 && i <= fNumPopulation/2){
         pp->ChangeParametersBeginning(i, 2, 0, i-fNumPopulation/4, 0, 0, 0, i-fNumPopulation/4);
       }
       else if(i > fNumPopulation/2 && i <= 3*(fNumPopulation/4)){
         pp->ChangeParametersBeginning(i, 3, 0, i-fNumPopulation/2, 0, 0, 0, i-fNumPopulation/2);
       }
       else{
         pp->ChangeParametersBeginning(i, 4, 0, i-3*(fNumPopulation/4), 0, 0, 0, i-3*(fNumPopulation/4));
       }
       // cout<<pp->GetLoc()<<endl;
       for(int k=0; k<InfectPopulation; k++){
           if(pp->GetID() == a[k]){pp->ChangeStatus(2);}
       }
       i++;
   }
   cout<<"Popolazione creata"<<endl;
}
//______________________________________________________________________
Organize* Organize::PopInstance(int InfectPopulation){
  if(!fgPopInstance){
    fgPopInstance = new Organize();
    fPop = new Persona[fNumPopulation];
    fgPopInstance->SetPop(InfectPopulation);
  }
  return fgPopInstance;
}
//___________________________________________________________________
void Organize::SetCity(){
  // fCity = new Edificio[fM];
  Edificio *pe;
  int n;
  for (int i=1; i<=fNumPopulation/4; i++) {
      pe=&fCity[i-1];
      pe->ChangeBuildingsBeginning(i, 0, 4);
  }
  n = fNumPopulation/4;
  for (int i=1; i<=fNumPopulation/160; i++) {
    pe=&fCity[i+n-1];
    pe->ChangeBuildingsBeginning(i+n, 1, 150);
  }
  n = n + fNumPopulation/160;
  for (int i=1; i<=fNumPopulation/160; i++) {
    pe=&fCity[i+n-1];
    pe->ChangeBuildingsBeginning(i+n, 2, 50);
  }
  n = n + fNumPopulation/160;
  for (int i=1; i<=fNumPopulation/160; i++) {
    pe=&fCity[i+n-1];
    pe->ChangeBuildingsBeginning(i+n, 3, 30);
  }
  n = n + fNumPopulation/160;
  for (int i=1; i<=fNumPopulation/300; i++) {
    pe=&fCity[i+n-1];
    pe->ChangeBuildingsBeginning(i+n, 4, 150);
  }
  n = n + fNumPopulation/300;
  for (int i=1; i<=fNumPopulation/200; i++) {
    pe=&fCity[i+n-1];
    pe->ChangeBuildingsBeginning(i+n, 5, 200);
  }
  n = n + fNumPopulation/200;
  for (int i=1; i<=fNumPopulation/300; i++) {
    pe=&fCity[i+n-1];
    pe->ChangeBuildingsBeginning(i+n, 6, 300);
  }
  n = n + fNumPopulation/300;
  for (int i=1; i<=fNumPopulation/200; i++) {
    pe=&fCity[i+n-1];
    pe->ChangeBuildingsBeginning(i+n, 7, 30);
  }
  n = n + fNumPopulation/200;
  pe=&fCity[n];
  pe->ChangeBuildingsBeginning(n+1, 8, fNumPopulation);

  cout << "Numero totale di edifici creati:" << n+1 << "\n";
}
//________________________________________________________________
Organize* Organize::CityInstance(){
  if(!fgCityInstance){
    fgCityInstance = new Organize();
    fCity = new Edificio[fM];
    fgCityInstance->SetCity();
  }
  return fgCityInstance;
}
//________________________________________________________________
void Organize::SetSEIRD(){
  int *stat;
  for(int i=0; i<5; i++){
    for(int j=0; j<4; j++){
      if(i == 0){stat=&fS0[j];}
      else if(i == 1){stat=&fE0[j];}
      else if(i == 2){stat=&fI0[j];}
      else if(i == 3){stat=&fR0[j];}
      else{stat=&fD0[j];}
      *stat=0;
    }
  }
}
//________________________________________________________________
Organize* Organize::SEIRDInstance(){
  if(!fgSEIRDInstance){
    fgSEIRDInstance = new Organize();
    fS0 = new int[4];
    fE0 = new int[4];
    fI0 = new int[4];
    fR0 = new int[4];
    fD0 = new int[4];
    fgSEIRDInstance->SetSEIRD();
  }
  return fgSEIRDInstance;
}
//_______________________________________________________________
void Organize::SetSEIRDcounter(){
  int *stat;
  for(int i=0; i<5; i++){
      stat = &fSEIRD[i];
      *stat=0;
  }
}
//________________________________________________________________
Organize* Organize::SEIRDcounterInstance(){
  if(!fgSEIRDcounterInstance){
    fgSEIRDcounterInstance = new Organize();
    fSEIRD = new int[5];
    fgSEIRDcounterInstance->SetSEIRDcounter();
  }
  return fgSEIRDcounterInstance;
}
//________________________________________________________________
void Organize::SetV(int k){ //k è il tipo di edificio
  int *v;
  for(int i=0; i<fMaxPersons[k]; i++){
      for(int j=0; j<fMaxNumBuildings[k]; j++){
        if(k == 0){v = &fv_0[i*fMaxNumBuildings[0]+j];}
        else if(k == 1){v = &fv_1[i*fMaxNumBuildings[1]+j];}
        else if(k == 2){v = &fv_2[i*fMaxNumBuildings[2]+j];}
        else if(k == 3){v = &fv_3[i*fMaxNumBuildings[3]+j];}
        else if(k == 4){v = &fv_4[i*fMaxNumBuildings[4]+j];}
        else if(k == 5){v = &fv_5[i*fMaxNumBuildings[5]+j];}
        else if(k == 6){v = &fv_6[i*fMaxNumBuildings[6]+j];}
        else if(k == 7){v = &fv_7[i*fMaxNumBuildings[7]+j];}
        else{v = &fv_8[i*fMaxNumBuildings[8]+j];}
        *v = 0;
      }
    }
}
//___________________________________________________________________
Organize* Organize::VInstance(int k){
  if(k == 0){
    if(!fgV0Instance){
    fgV0Instance = new Organize();
    fv_0 = new int[fMaxPersons[0] * fMaxNumBuildings[0]];
    fgV0Instance->SetV(0);
    }
  return fgV0Instance;
  }
  else if(k == 1){
    if(!fgV1Instance){
      fgV1Instance = new Organize();
      fv_1 = new int[fMaxPersons[1] * fMaxNumBuildings[1]];
      fgV1Instance->SetV(1);
    }
    return fgV1Instance;
  }
  else if(k == 2){
    if(!fgV2Instance){
      fgV2Instance = new Organize();
      fv_2 = new int[fMaxPersons[2] * fMaxNumBuildings[2]];
      fgV2Instance->SetV(2);
    }
    return fgV2Instance;
  }
  else if(k == 3){
    if(!fgV3Instance){
      fgV3Instance = new Organize();
      fv_3 = new int[fMaxPersons[3] * fMaxNumBuildings[3]];
      fgV3Instance->SetV(3);
    }
    return fgV3Instance;
  }
  else if(k == 4){
    if(!fgV4Instance){
      fgV4Instance = new Organize();
      fv_4 = new int[fMaxPersons[4] * fMaxNumBuildings[4]];
      fgV4Instance->SetV(4);
    }
    return fgV4Instance;
  }
  else if(k == 5){
    if(!fgV5Instance){
      fgV5Instance = new Organize();
      fv_5 = new int[fMaxPersons[5] * fMaxNumBuildings[5]];
      fgV5Instance->SetV(5);
    }
    return fgV5Instance;
  }
  else if(k == 6){
    if(!fgV6Instance){
      fgV6Instance = new Organize();
      fv_6 = new int[fMaxPersons[6] * fMaxNumBuildings[6]];
      fgV6Instance->SetV(6);
    }
    return fgV6Instance;
  }
  else if(k == 7){
    if(!fgV7Instance){
      fgV7Instance = new Organize();
      fv_7 = new int[fMaxPersons[7] * fMaxNumBuildings[7]];
      fgV7Instance->SetV(7);
    }
    return fgV7Instance;
  }
  else{
    if(!fgV8Instance){
      fgV8Instance = new Organize();
      fv_8 = new int[fMaxPersons[8] * fMaxNumBuildings[8]];
      fgV8Instance->SetV(8);
    }
    return fgV8Instance;
  }
}

//_____________________________________________________________________
void Organize::Destroy(){
  // Deletes the objects
  if(fgPopInstance)delete fgPopInstance;
  fgPopInstance = NULL;
  if(fgCityInstance)delete fgCityInstance;
  fgCityInstance = NULL;
  if(fgV0Instance)delete fgV0Instance;
  fgV0Instance = NULL;
  if(fgV1Instance)delete fgV1Instance;
  fgV1Instance = NULL;
  if(fgV2Instance)delete fgV2Instance;
  fgV2Instance = NULL;
  if(fgV3Instance)delete fgV3Instance;
  fgV3Instance = NULL;
  if(fgV4Instance)delete fgV4Instance;
  fgV4Instance = NULL;
  if(fgV5Instance)delete fgV5Instance;
  fgV5Instance = NULL;
  if(fgV6Instance)delete fgV6Instance;
  fgV6Instance = NULL;
  if(fgV7Instance)delete fgV7Instance;
  fgV7Instance = NULL;
  if(fgV8Instance)delete fgV8Instance;
  fgV8Instance = NULL;
  if(fgSEIRDInstance)delete fgSEIRDInstance;
  fgSEIRDInstance = NULL;
  if(fgSEIRDcounterInstance)delete fgSEIRDcounterInstance;
  fgSEIRDcounterInstance = NULL;
}
