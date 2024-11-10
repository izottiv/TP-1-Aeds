#include "TAD_ListaMineral.h"

void EsvaziaLM(ListaMineral* Lista){
    Lista->Primeiro = InicioArranjo;
    Lista->Ultimo = Lista->Primeiro;
}

int LerLM(ListaMineral* Lista);
void InsereLM(ListaMineral* Lista, Mineral Mineral);
void RetiraLM(ListaMineral* LIsta, Mineral Mineral, Apontador p);
void ImprimeLM(ListaMineral* Lista);
