#ifndef SISTEMADECONTROLE_H
#define SISTEMADECONTROLE_H
#include "ListaSonda/TAD_ListaSonda.h"


ListaSondas Inicializacao();
void ColetaDeNovaRocha(ListaSondas *FrotadeSondas);

double CalcularDistancia(Sonda venus,RochaMineral Rocha);
int ProcurasIDSondaMaisproxima(ListaSondas *FrotadeSondas,RochaMineral *RochaS);

void ImprimeStatusSondas(ListaSondas *Frotasdesondas);

void RedistribuicaoDeRochas(ListaSondas *Frotadesondas);
void RetornaBase(ListaSondas *Frotadesondas);
double RetornaMediadePesoFrota(ListaSondas *Frotadesondas);


void SelecaoDeModos(ListaSondas *FrotadeSondas);


#endif 