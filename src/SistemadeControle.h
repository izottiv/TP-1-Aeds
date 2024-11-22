#ifndef SISTEMADECONTROLE_H
#define SISTEMADECONTROLE_H
#include "ListaSonda/TAD_ListaSonda.h"


void Inicializacao();
void ColetaDeNovaRocha(ListaSondas *FrotadeSondas);

double CalcularDistancia(Sonda venus,RochaMineral Rocha);
int ProcurasIDSondaMaisproxima(ListaSondas *FrotadeSondas,RochaMineral *RochaS);

void ImprimeStatusSondasADMIN(ListaSondas *Frotasdesondas);

void RedistribuicaoDeRochas(ListaSondas *Frotadesondas);
void RetornaBase(ListaSondas *Frotadesondas);

double RetornaMediadePesoFrota(ListaSondas *Frotadesondas);
int RetornaQuantasSonda(ListaSondas *Frotadesondas);
int RetornaQuantidadeDeRochasFrota(ListaSondas *Frotadesondas);
void AlocaOrganizaRochaSonda(ListaSondas *Frotadesondas,RochaMineral *Lista[]);


void SelecaoDeModos(ListaSondas *FrotadeSondas);


#endif 