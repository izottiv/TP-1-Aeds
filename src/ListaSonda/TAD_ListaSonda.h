#ifndef TAD_LISTASONDA_H_
#define TAD_LISTASONDA_H_
#include "SondaEspacial/TAD_Sonda.h"

typedef struct cel* Apontador;
typedef struct cel{
    Sonda sonda;
    Apontador prox;
}CelulaSonda;

typedef struct{
    Apontador Primeiro;
    Apontador Ultimo;
}ListaSondas;

void InicializaListaSondas(ListaSondas* lista);
void InserirListaSondas(ListaSondas* lista, Sonda* sonda);
void RemoverListaSondas(ListaSondas* lista, int identificador, Sonda* Sondaremovida);
void ImprimirListaSondas(ListaSondas* lista);

#endif