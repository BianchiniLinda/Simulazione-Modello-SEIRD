#include "Edificio.h"
#include <iostream>
using namespace std;


ClassImp(Edificio);

Edificio::Edificio() : TObject(),
fIDEdif(0),
fTypeEdif(0),
fNumMax(0.),
fCounter()
{
//Default constructor
}

//_________________________________________________________________
Edificio::Edificio(int idEdificio, int typeEdificio, double numMax, int counter) : TObject(),
fIDEdif(idEdificio),
fTypeEdif(typeEdificio),
fNumMax(numMax),
fCounter(counter)
{
//Standard constructor
}

//_________________________________________________________________
Edificio::Edificio(const Edificio &source):
TObject(source),
fIDEdif(source.fIDEdif),
fTypeEdif(source.fTypeEdif),
fCounter(source.fCounter)
{
// copy constructor
}

//_________________________________________________________________
Edificio::~Edificio() {
// Default destructor
  // cout<<"DESTRUCTOR EDIFICIO\n";
}
//_________________________________________________________________
// consente di settare ID, tipo e numero massimo di persone dell'edificio
void Edificio::ChangeBuildingsBeginning(int id, int type, int max){
      fIDEdif = id;
      fTypeEdif = type;
      fNumMax = max;
}

//____________________________________________________________
//restituisce il numero di edifici dei diversi tipi di edifici in base al numero di individui della popolazione
int Edificio :: NumBuildings(int NumPopulation){
    if(fTypeEdif == 0) {return NumPopulation/4;}
    else if(fTypeEdif == 1) {return NumPopulation/160;}
    else if(fTypeEdif == 2) {return NumPopulation/160;}
    else if(fTypeEdif == 3) {return NumPopulation/160;}
    else if(fTypeEdif == 4) {return NumPopulation/300;}
    else if(fTypeEdif == 5) {return NumPopulation/200;}
    else if(fTypeEdif == 6) {return NumPopulation/300;}
    else if(fTypeEdif == 7) {return NumPopulation/200;}
    else{return 1;}
  }
