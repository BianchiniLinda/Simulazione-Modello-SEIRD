#ifndef FUNZIONI_H
#define FUNZIONI_H

#include "TObject.h"
#include "Edificio.h"
#include "Persona.h"
#include "Organize.h"
#include "TRandom3.h"



void CreateCity(int NumPopulation, Edificio *pe);
void CreatePopulation(int NumPopulation, int InfectPopulation, Persona *pp);
void ClearArray();
void ClearSEIRD();
int GetAgeFromID(int id, int N, int InfectPopulation);
int GetStatusFromID(int id, int N, int InfectPopulation);
void CompStatus(int typeLoc, int NumPopulation, int tmax, int InfectPopulation);
void FillSEIRD(int *c, int typeLoc, int civico, int NumPopulation, int InfectPopulation);
void ChangeStatusPersons(int *N, int typeLoc, int civico, int NumPopulation, int InfectPopulation);
void FillforHists(int NumPopulation, int InfectPopulation);
void ClearHists();
void AddToList(Persona *p, Edificio *e, int NumBuildings);

#endif
