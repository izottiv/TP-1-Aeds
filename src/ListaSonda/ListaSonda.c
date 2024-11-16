#include <stdio.h>
#include <stdlib.h>
#include "ListaSonda.h"

void InicializaListaSondas(ListaSondas* lista){
    lista->Primeiro = (Apontador)malloc(sizeof(CelulaSonda));
    lista->Ultimo = lista->Primeiro;
    lista->Primeiro->prox = NULL;
}

void InserirListaSondas(ListaSondas* lista, Sonda* sonda){
    lista->Ultimo->prox = (Apontador)malloc(sizeof(CelulaSonda));
    lista->Ultimo = lista->Ultimo->prox;
    lista->Ultimo->sonda = *sonda;
    lista->Ultimo->prox = NULL;
}

//tem q fzr
void RemoverListaSondas(ListaSondas* lista, int identificador, Sonda* Sondaremovida);

void ImprimirListaSondas(ListaSondas* lista){
    Apontador aux;
    aux = lista->Primeiro->prox;
    while(aux){
        printf("Identificador: %d\n", aux->sonda.IdentificadorSonda);
        ImprimeConteudoCompartimento(&(aux->sonda.CompartimentoSonda));
        printf("Localização: Latitude = %.2f Longitude = %.2f", aux->sonda.LocalizacaoSonda.Latitude,aux->sonda.LocalizacaoSonda.Longitude);
        printf("Esta Ligada: ");
        if(aux->sonda.EstaLigada == 0){
            printf("Sim\n");
        }
        else{
            printf("Não\n");
        }
        aux = aux->prox;
    }
}