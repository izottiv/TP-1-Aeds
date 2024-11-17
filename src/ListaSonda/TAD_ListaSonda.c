#include <stdio.h>
#include <stdlib.h>
#include "TAD_ListaSonda.h"

void InicializaListaSondas(ListaSondas* lista){
    lista->Primeiro = (CelulaSonda*)malloc(sizeof(CelulaSonda));
    lista->Ultimo = lista->Primeiro;
    lista->Primeiro->prox = NULL;
}

void InserirListaSondas(ListaSondas* lista, Sonda* sonda){
    lista->Ultimo->prox = (CelulaSonda*)malloc(sizeof(CelulaSonda));
    lista->Ultimo = lista->Ultimo->prox;
    lista->Ultimo->sonda = *sonda;
    lista->Ultimo->prox = NULL;
}

//tem q fzr
void RemoverListaSondas(ListaSondas* lista, int identificador, Sonda* Sondaremovida){
    CelulaSonda* aux = lista->Primeiro;
    CelulaSonda* Remover = NULL;
    while (aux && aux->prox && aux->prox->sonda.IdentificadorSonda != identificador)
    {
        aux = aux->prox; 
    }
    if(aux && aux->prox){
        Remover = aux->prox;
        aux->prox =Remover->prox;
        *Sondaremovida = Remover->sonda;
    }
    if(Remover){
        free(Remover);
    }
    
}

void ImprimirListaSondas(ListaSondas* lista){
    CelulaSonda* aux;
    aux = lista->Primeiro->prox;
    while(aux){
        printf("Identificador: %d\n", aux->sonda.IdentificadorSonda);
        printf("Capacidade Maxima: %.2f\n", aux->sonda.CapacidadeMaximaSonda);
        printf("Velocidade da Sonda: %.2f\n", aux->sonda.VelocidadeSonda);
        printf("Nivel de Combustivel: %.2f\n", aux->sonda.NivelIncialCombustivel);
        ImprimeConteudoCompartimento(&(aux->sonda.CompartimentoSonda));
        printf("Localizacao: Latitude = %.6f Longitude = %.6f\n", aux->sonda.LocalizacaoSonda.Latitude,aux->sonda.LocalizacaoSonda.Longitude);
        printf("Esta Ligada: ");
        if(aux->sonda.EstaLigada == 1){
            printf("Sim\n");
        }
        else{
            printf("Nao\n");
        }
        aux = aux->prox;
    }
}