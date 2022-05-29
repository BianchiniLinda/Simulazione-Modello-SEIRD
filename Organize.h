#ifndef ORGANIZE_H
#define ORGANIZE_H


#include <TObject.h>
#include "Persona.h"
#include "Edificio.h"


class Organize : public TObject {
public:
 void SetPop(int InfectPopulation); //viene istanziata la popolazione
 void SetCity();//vengono istanziati gli edifici
 void SetV(int k);//vengono istanziati i vettori per i vari tipi di edifici, contenenti gli ID delle persone
 void SetSEIRD();//vengono istanziati i vettori S0[4], E0[4], I0[4], R0[4], D0[4]
 void SetSEIRDcounter();//viene istanziato il vettore SEIRD[5]
 //funzioni che chiamano le varie istanze se l'oggetto non è istanziato oppure restituiscono l'oggetto stesso
 static Organize* CityInstance();
 static Organize* PopInstance(int InfectPopulation);
 static Organize* VInstance(int k);
 static Organize* SEIRDInstance();
 static Organize* SEIRDcounterInstance();
 //funzioni che permettono di ottenere i puntatori ai vari vettori creati sull'heap
 Persona* GetPop() const {return fPop;}
 Edificio* GetCity() const {return fCity;}
 int* GetV0() {return fv_0;}
 int* GetV1() {return fv_1;}
 int* GetV2() {return fv_2;}
 int* GetV3() {return fv_3;}
 int* GetV4() {return fv_4;}
 int* GetV5() {return fv_5;}
 int* GetV6() {return fv_6;}
 int* GetV7() {return fv_7;}
 int* GetV8() {return fv_8;}

 int GetNumPopulation() const {return fNumPopulation;}
 int GetM() const {return fM;}
 int GetMaxPersons(int k) const {return fMaxPersons[k];}
 int GetMaxNumBuildings(int k) const {return fMaxNumBuildings[k];}
 int* GetS0() const {return fS0;}
 int* GetE0() const {return fE0;}
 int* GetI0() const {return fI0;}
 int* GetR0() const {return fR0;}
 int* GetD0() const {return fD0;}
 int* GetSEIRD() const {return fSEIRD;}

 static void Destroy();

 private:
  // methods
  Organize();   // Default constructor
  Organize(const Organize& rec);   // Copy constructor - not implemented
  Organize& operator=(const Organize &source); // Assignment operator - not implemented
  virtual ~Organize();  //Destructor

  //Data members
  static const int fNumPopulation = 10000;
  static const int fM = fNumPopulation/4+3*(fNumPopulation/160)+2*(fNumPopulation/200)+2*(fNumPopulation/300)+1;
  static Persona *fPop;
  static Edificio *fCity;


  static int fMaxPersons[9];
  static int fMaxNumBuildings[9];

  //puntatori a vettori di interi di grandezza (numero massimo di persone che può contenere l'edificio) * (Numero di edifici di quel tipo), scrittura che permette in seguito di aggiungere
  //in questo vettore l'ID della persona che entra nell'edificio in questione
  //v_0 viene utilizzato per gli edifici di tipo 0 e così via ...
  static int *fv_0;
  static int *fv_1;
  static int *fv_2;
  static int *fv_3;
  static int *fv_4;
  static int *fv_5;
  static int *fv_6;
  static int *fv_7;
  static int *fv_8;

  //vettori degli stati
  static int *fS0;
  static int *fE0;
  static int *fI0;
  static int *fR0;
  static int *fD0;
  static int *fSEIRD;

  //Puntatori della classe che permettono di istanziare una sola volta i vettori
  static Organize* fgPopInstance;
  static Organize* fgCityInstance;
  static Organize* fgV0Instance;
  static Organize* fgV1Instance;
  static Organize* fgV2Instance;
  static Organize* fgV3Instance;
  static Organize* fgV4Instance;
  static Organize* fgV5Instance;
  static Organize* fgV6Instance;
  static Organize* fgV7Instance;
  static Organize* fgV8Instance;
  static Organize* fgSEIRDInstance;
  static Organize* fgSEIRDcounterInstance;

  ClassDef(Organize,1)
};

#endif
