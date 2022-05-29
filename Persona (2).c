
#include "Persona.h"
#include <iostream>
#include "TRandom3.h"
using namespace std;

ClassImp(Persona);

Persona::Persona() : TObject(),
fID(0),
fStatus(0),
fHome_id(0),
fWork_id(0),
fOrder(0),
fAge(0),
fLocation(1),
fLocType(0)
{
  // cout<<"Default constructor"<<endl;
//Default constructor
}

//_________________________________________________________________
Persona::Persona(int id, int status, int home, int work, int order, int age, int location, int loctype) : TObject(),
fID(id),
fStatus(status),
fHome_id(home),
fWork_id(work),
fOrder(order),
fAge(age),
fLocation(location),
fLocType(loctype)
{
// Standard constructor
}

//_________________________________________________________________
Persona::Persona(const Persona &source):
TObject(source),
fID(source.fID),
fStatus(source.fStatus),
fHome_id(source.fHome_id),
fWork_id(source.fWork_id),
fOrder(source.fOrder),
fAge(source.fAge),
fLocation(source.fLocation),
fLocType(source.fLocType)
{
    // copy constructor
}

//_________________________________________________________________
Persona::~Persona() {
// Default destructor
}

//_________________________________________________________________
//tipi di edifici: casa=0; scuola=1; lavoro=2; supermercato=3; ristorante=4; chiesa=5; parco=6; ospedale=7, università=8; cimitero=9;
// movimento delle persone in base allo stato stato e in base all'età con percentuali diverse
void Persona::ChangeBuildingMorning(){
  double a = gRandom->Rndm();
  switch(fAge)
  {
  case 1:
  if(fStatus == 2){
   if(a<0.20){fLocType=1;}
   else if(a>=0.2 && a<0.4){fLocType=7;}
   else if(a>=0.4 && a<0.5){fLocType=6;}
  }
  else if(fStatus == 4){fLocType = 8;}
  else {
    if(a<0.8){fLocType = 1;}
    else if(a >= 0.8  && a < 0.85){fLocType = 6;}
    else if(a >= 0.85 && a < 0.9){fLocType = 5;}
    else if(a >= 0.9  && a < 0.91){fLocType = 7;}
  }
  break;
  case 2:
  if(fStatus == 2){
   if(a<0.20){fLocType=1;}
   else if(a >= 0.2 && a < 0.4){fLocType = 7;}
   else if(a >= 0.4 && a < 0.5){fLocType = 3;}
  }
  else if(fStatus == 4){fLocType = 8; }
  else {
      if(a<0.8){fLocType=1;}
      else if(a>=0.8 && a<0.85){fLocType=3;}
      else if(a>=0.85 && a<0.9){fLocType=5;}
      else if(a>=0.9 && a<0.91){fLocType=7;}
  }
  break;
  case 3:
  if(fStatus == 2){
     if(a<0.30){fLocType=7;}
     else if(a>=0.3 && a<0.4){fLocType=3;}
     else if(a>=0.4 && a<0.5){fLocType=5;}
     else if(a>=0.5 && a<0.6){fLocType=2;}
     else if(a>=0.6 && a<0.65){fLocType=1;}
  }
  else if(fStatus == 4){fLocType=8;}
  else {
      if(a<0.7){fLocType=2;}
      else if(a>=0.7 && a<0.8){fLocType=1;}
      else if(a >= 0.8  && a < 0.85){fLocType=3;}
      else if(a >= 0.85 && a < 0.9){fLocType=5;}
      else if(a >= 0.9  && a < 0.92){fLocType=7;}
  }
  break;
  case 4:
  if(fStatus == 2){
       if(a<0.40){fLocType=7;}
     else if(a>=0.4 && a<0.5){fLocType=5;}
  }
  else if(fStatus == 4){fLocType=8;}
  else {
      if(a<0.1){fLocType=7;}
      else if(a<0.4 && a>=0.1){fLocType=5;}
      else if(a<0.5 && a>=0.4){fLocType=6;}
  }
  break;
  }
}
//------------------------------------------------------------------------------------------------------
// movimento delle persone in base allo stato e in base all'età con percentuali diverse. Rispetto al metodo ChangeBuildingMorning ha probabilità diverse per gli spostamenti, dovuti al fatto che al mattino i bambini i giovani e gli adulti rimangono con più probabilità nello stesso posto (scuola e lavoro)
void Persona::ChangeBuildingAfternoon(){
  double a = gRandom->Rndm();
  switch(fAge){
  case 1:
  if(fStatus == 2){
   if(a >= 0.2 && a < 0.4){fLocType = 7;}
   else if(a >= 0.4 && a < 0.5){fLocType = 6;}
   else if(a >= 0.4 && a < 0.45){fLocType = 4;}
   else{fLocType=0; fLocation = fHome_id;}
  }
  else if(fStatus == 4){fLocType = 8;}
  else {
      if(a < 0.1){fLocType = 1;}
    else if(a >= 0.1 && a < 0.6){fLocType = 6;}
    else if(a >= 0.65 && a < 0.7){fLocType = 5;}
    else if(a >= 0.7 && a < 0.71){fLocType = 7;}
    else if(a >= 0.71 && a < 0.81){fLocType = 4;}
    else{fLocType = 0; fLocation = fHome_id;}
  }
  break;
  case 2:
  if(fStatus == 2){
    if(a < 0.10){fLocType = 1;}
   else if(a >= 0.1 && a < 0.3){fLocType = 7;}
   else if(a >= 0.3 && a < 0.4){fLocType = 3;}
   else if(a >= 0.4 && a < 0.45){fLocType = 4;}
   else{fLocType = 0; fLocation = fHome_id;}
  }
  else if(fStatus == 4){fLocType = 8;}
  else {
      if(a < 0.5){fLocType = 0; fLocation = fHome_id;}
      else if(a >= 0.5 && a < 0.75){fLocType = 3;}
      else if(a >= 0.75 && a < 0.8){fLocType = 5;}
      else if(a >= 0.8 && a < 0.81){fLocType = 7;}
      else if(a >= 0.81){fLocType = 4;}
  }
  break;
  case 3:
  if(fStatus == 2){
     if(a < 0.30){fLocType = 7;}
     else if(a >= 0.3 && a < 0.4){fLocType = 3;}
     else if(a >= 0.4 && a < 0.5){fLocType = 5;}
     else if(a >= 0.65 && a < 0.7){fLocType = 4;}
     else{fLocType = 0; fLocation = fHome_id;}
  }
  else if(fStatus == 4){fLocType = 8;}
  else {
      if(a < 0.4){fLocType = 0; fLocation = fHome_id;}
      else if(a >= 0.4 && a < 0.65){fLocType = 3;}
      else if(a >= 0.65 && a < 0.7){fLocType = 5;}
      else if(a >= 0.7 && a < 0.72){fLocType = 7;}
      else if(a >= 0.72 && a < 0.82){fLocType = 2;}
      else if(a >= 0.82 && a < 0.9){fLocType = 1;}
      else if(a >= 0.9){fLocType = 4;}
  }
  break;
  case 4:
  if(fStatus == 2){
    if(a < 0.40){fLocType = 7;}
   else if(a >= 0.4 && a < 0.5){fLocType = 5;}
   else if(a >= 0.5 && a < 0.6){fLocType = 3;}
   else{fLocType = 0; fLocation = fHome_id;}
  }
  else if(fStatus == 4){fLocType = 8;}
  else {
      if(a < 0.1){fLocType = 7;}
      else if(a < 0.4 && a >= 0.1){fLocType = 5;}
      else if(a < 0.5 && a >= 0.4){fLocType = 6;}
    else if(a >= 0.5 && a < 0.55){fLocType = 4;}
    else{fLocType = 0;fLocation = fHome_id;}
  }
  break;
}
}

//__________________________________________________________________________
//inizializza la variabile fLocation (=ID del locale in cui si trova la persona) al primo ID di quel tipo di locale
void Persona::InitializeLocation(int NumPopulation){
  int m;
  // if(fLocType == 0) {fLocation = fHome_id;}
  m = NumPopulation/4;
  if(fLocType == 1) {fLocation = m + 1;}
  m = m + NumPopulation/160;
  if(fLocType == 2) {fLocation = m + 1;}
  m = m + NumPopulation/160;
  if(fLocType == 3) {fLocation = m + 1;}
  m = m + NumPopulation/160;
  if(fLocType == 4) {fLocation = m + 1;}
  m = m + NumPopulation/300;
  if(fLocType == 5) {fLocation = m + 1;}
  m = m + NumPopulation/200;
  if(fLocType == 6) {fLocation = m + 1;}
  m = m + NumPopulation/300;
  if(fLocType == 7) {fLocation = m + 1;}
  m = m + NumPopulation/200;
  if(fLocType == 8) {fLocation = m + 1;}
}
//___________________________________________________________________________
void Persona::InitializeWork(){
  double a = gRandom->Rndm();
  switch(fAge){
  case 1:
  fLocType = 1;
  break;
  case 2:
  fLocType = 1;
  break;
  case 3:
  if(a < 0.10){fLocType = 1;}
  else{fLocType = 2;}
  break;
  }
}
//___________________________________________________________________________
void Persona::SetWorkID(){
  fWork_id =fLocation;
}
//____________________________________________________________________________
void Persona::InitializeLocationW(int NumPopulation){
  int m;
  // if(fLocType == 0) {fLocation = fHome_id;}
  m = NumPopulation/4;
  if(fLocType == 1) {fLocation = fWork_id;}
  m = m + NumPopulation/160;
  if(fLocType == 2) {fLocation = fWork_id;}
  m = m + NumPopulation/160;
  if(fLocType == 3) {fLocation = m + 1;}
  m = m + NumPopulation/160;
  if(fLocType == 4) {fLocation = m + 1;}
  m = m + NumPopulation/300;
  if(fLocType == 5) {fLocation = m + 1;}
  m = m + NumPopulation/200;
  if(fLocType == 6) {fLocation = m + 1;}
  m = m + NumPopulation/300;
  if(fLocType == 7) {fLocation = m + 1;}
  m = m + NumPopulation/200;
  if(fLocType == 8) {fLocation = m + 1;}
}
//__________________________________________________________________________
//setta le variabili fLocType e fLocation a quelle che sono state impostate quando sono state create le persone, e rappresentano la casa
  void Persona::Backhome(){
   fLocType = 0;
   fLocation = fHome_id;
   }
//____________________________________________________________________________
// consente di settare ID, età, stato, ID casa, tipo e ID locale in cui si trova
void Persona::ChangeParametersBeginning(int id, int age, int status, int home, int work, int order, int type, int locazione){
    fID = id;
    fAge = age;
    fStatus = status;
    fHome_id = home;
    fWork_id = work;
    fOrder = order;
    fLocType = type;
    fLocation = locazione;
}
