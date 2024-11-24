#ifndef TAD_LISTASONDA_H
#define TAD_LISTASONDA_H
#include "SondaEspacial/TAD_Sonda.h"

typedef struct celApontador{
    Sonda sonda;
    struct celApontador *prox;
}CelulaSonda;

typedef struct{
    CelulaSonda* Primeiro;
    CelulaSonda* Ultimo;
}ListaSondas;

//Inicializa a lista de Sondas
void InicializaListaSondas(ListaSondas* lista);

//Insere uma sonda na lista
void InserirListaSondas(ListaSondas* lista, Sonda* sonda);

//Remove uma sonda da lista com base no identificador
void RemoverListaSondas(ListaSondas* lista, int identificador, Sonda* Sondaremovida);

//Imprime a lista de Sondas
void ImprimirListaSondas(ListaSondas* lista);

#endif