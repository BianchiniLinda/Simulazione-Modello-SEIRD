#ifndef PERSONA_H
#define PERSONA_H

#include "TObject.h"

class Persona : public TObject {
public :
  Persona();
  Persona(int id, int stato, int home, int work, int order, int age, int locazione, int loctype);
  Persona(const Persona& source);
  virtual ~Persona();

  Persona& operator=(const Persona& source);

  //dichiarazione funzioni per simulazione
  void ChangeStatus(int z){fStatus = z;}; //z è un intero che indica il nuovo stato
  void ChangeBuildingMorning();
  void ChangeBuildingAfternoon();
  void ChangeLocation() {++fLocation;}; //incrementa di uno il l'ID del locale in cui si trova la persona
  void Backhome();
  void ChangeParametersBeginning(int id, int age, int status, int home, int work, int order, int type, int locazione);
  void InitializeLocation(int NumPopulation);
  void InitializeWork();
  void InitializeLocationW(int NumPopulation);
  void SetWorkID();
  void SetOrder(int order){fOrder = order;} //viene inserito l'ordine all'interno dell'edificio

  int GetID() const {return fID;}
  int GetAge() const {return fAge;}
  int GetLoc() {return fLocation;}
  int GetType() {return fLocType;}
  int GetStatus() {return fStatus;}
  int GetWorkID() {return fWork_id;}
  int GetOrder() {return fOrder;}

protected :
  int fID;// ID persona
  int fStatus; // Stato di salute della perosna (S=0, E=1, I=2, R=3, D=4)
  int fHome_id; // numero civico della casa
  int fWork_id;// numero civico del luogo di lavoro/scuola
  int fOrder;// ordine allinterno dell'edificio di lavoro o scuola
  int fAge; // Età: Children=1; Young Adult=2; Adult=3; Elderly=4
  int fLocation; // civico dell'edificio
  int fLocType; // tipo di edificio (Doctor, Park, Church...)


ClassDef(Persona, 1)
};

#endif
