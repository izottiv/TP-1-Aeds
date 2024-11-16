#ifndef TAD_LISTASONDA_H_
#define TAD_LISTASONDA_H_
#include "SondaEspacial/TAD_Sonda.h"

typedef struct celApontador{
    Sonda sonda;
    struct celApontador *prox;
}CelulaSonda;

typedef struct{
    CelulaSonda* Primeiro;
    CelulaSonda* Ultimo;
}ListaSondas;

void InicializaListaSondas(ListaSondas* lista);
void InserirListaSondas(ListaSondas* lista, Sonda* sonda);
void RemoverListaSondas(ListaSondas* lista, int identificador, Sonda* Sondaremovida);
void ImprimirListaSondas(ListaSondas* lista);

#endif