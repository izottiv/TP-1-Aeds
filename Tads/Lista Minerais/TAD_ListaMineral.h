#ifndef TAD_LISTAMINERAL_H
#define TAD_LISTAMINERAL_H
#include "./Mineral/TAD_Mineral.h"

#define InicioArranjo 0
#define MaxTam  5

typedef int Apontador;

// Struct
typedef struct 
{
    Mineral Mineral[MaxTam];
    Apontador Primeiro, Ultimo;
} ListaMineral;

void EsvaziaLM(ListaMineral* Lista);
int LerLM(ListaMineral* Lista);
void InsereLM(ListaMineral* Lista, Mineral Mineral);
void RetiraLM(ListaMineral* LIsta, Mineral Mineral, Apontador p);
void ImprimeLM(ListaMineral* Lista);


#endif