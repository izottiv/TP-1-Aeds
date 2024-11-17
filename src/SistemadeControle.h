#ifndef SISTEMADECONTROLE_H
#define SISTEMADECONTROLE_H
#include "ListaSonda/TAD_ListaSonda.h"


ListaSondas Inicializacao();
void ColetaDeNovaRocha(ListaSondas *FrotadeSondas);
double CalcularDistancia(Sonda venus,RochaMineral Rocha);
CelulaSonda *Procurasondamaisproxima(ListaSondas *FrotadeSondas,RochaMineral *RochaS);
void ImprimeStatusSondas();
void RedistribuicaoDeRochas();
void SelecaoDeModos(ListaSondas *FrotadeSondas);


#endif 