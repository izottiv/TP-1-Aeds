#include <stdio.h>
#include "TAD_ListaMineral.h"

//Retira todos os itens
void EsvaziaListaMineral(ListaMineral* Lista){
    Lista->_Primeiro = InicioArranjo;
    Lista->_Ultimo = Lista->_Primeiro;
}

//Verifica se o primeiro e ultimo valor são os mesmos
int LerListaMineral(ListaMineral* Lista){
    return (Lista->_Ultimo == Lista->_Primeiro);
}

//Insere um novo valor na lista
void InsereListaMineral(ListaMineral* Lista, Mineral Mineral){
    if (Lista->_Ultimo == MaxTam)
    printf("A lista está cheia!");

    Lista->_Mineral[Lista->_Ultimo++] = Mineral;
    printf("Adicionado com sucesso!");
}

//Retira um valor específico da lista
int RetiraListaMineral(ListaMineral* Lista, Mineral* Mineral, Apontador p){

    int cont;
    if (LerLM(Lista) || p >= Lista->_Ultimo || p < 0)
        return 0;

    *Mineral = Lista->_Mineral[p];
    Lista->_Ultimo--;

    for (cont = p+1; cont <= Lista->_Ultimo; cont++)
        Lista->_Mineral[cont - 1] = Lista->_Mineral[cont];
    return 1;
}

//Imprime todos os valores da lista
void ImprimeListaMineral(ListaMineral* Lista){
    int i;
    for (i = Lista->_Primeiro; i < Lista->_Ultimo; i++)
        printf("%s\n", Lista->_Mineral[i].nome);
}