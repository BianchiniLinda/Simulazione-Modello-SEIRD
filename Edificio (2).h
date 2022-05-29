#ifndef EDIFICIO_H
#define EDIFICIO_H

#include "TObject.h"
#include "Persona.h"

class Edificio : public TObject {
public :
  Edificio();
  Edificio(int idEdificio, int typeEdificio, double numMax, int counter);
  Edificio(const Edificio& source);
  virtual ~Edificio();

  Edificio& operator=(const Edificio& source);

  //dichiarazione funzioni per simulazione
  bool CheckAvailability() {return (fCounter < fNumMax) ? true : false;} //fa controllo che edificio non sia già pieno
  void AddToList(Persona *p){(fTypeEdif == p->GetType() && fIDEdif == p->GetLoc()) ? ++fCounter : fCounter;};
  void ClearCounter(){fCounter = 0;} //resetta il contatore
  void ChangeBuildingsBeginning(int id, int type, int max);
  int NumBuildings(int NumPopolation);

  int GetIDEdif() const {return fIDEdif;}
  int GetTypeEdif() const {return fTypeEdif;}
  double GetNumMax() const {return fNumMax;}
  int GetCounter() {return fCounter;}

private :
  int fIDEdif; // ID edificio
  int fTypeEdif; // Tipo di edificio
  double fNumMax; // numero massimo permesso di persone all'interno di un edificio
  int fCounter; // contatore di persone che si trovano nell'edificio


ClassDef(Edificio, 1)
};

#endif
