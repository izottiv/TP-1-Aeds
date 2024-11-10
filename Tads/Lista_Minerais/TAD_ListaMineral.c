#include <stdio.h>
#include "TAD_ListaMineral.h"

void EsvaziaLM(ListaMineral* Lista){
    Lista->Primeiro = InicioArranjo;
    Lista->Ultimo = Lista->Primeiro;
}

int LerLM(ListaMineral* Lista){
    return (Lista->Ultimo == Lista->Primeiro);
}

void InsereLM(ListaMineral* Lista, Mineral Mineral){
    if (Lista->Ultimo == MaxTam)
    printf("A lista está cheia!");

    Lista->Mineral[Lista->Ultimo++] = Mineral;
    printf("Adicionado com sucesso!");
}

int RetiraLM(ListaMineral* Lista, Mineral* Mineral, Apontador p){

    int cont;
    if (LerLM(Lista) || p >= Lista->Ultimo || p < 0)
        return 0;

    *Mineral = Lista->Mineral[p];
    Lista->Ultimo--;

    for (cont = p+1; cont <= Lista->Ultimo; cont++)
        Lista->Mineral[cont - 1] = Lista->Mineral[cont];
    return 1;
}

void ImprimeLM(ListaMineral* Lista){
    int i;
    for (i = Lista->Primeiro; i < Lista->Ultimo; i++)
        printf("%s\n", Lista->Mineral[i].nome);
}