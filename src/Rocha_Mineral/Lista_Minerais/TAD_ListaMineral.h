#ifndef TAD_LISTAMINERAL_H
#define TAD_LISTAMINERAL_H

#include "Mineral/TAD_Mineral.h"

#define InicioArranjo 0
#define MaxTam  5

typedef int Apontador;

//Struct da ListaMineral
typedef struct 
{
    Mineral _Mineral[MaxTam];
    Apontador _Primeiro, _Ultimo;
} ListaMineral;

//Funções da ListaMineral
void    EsvaziaListaMineral(ListaMineral* Lista);                               //Retira todos os itens
int     LerListaMineral(ListaMineral* Lista);                                   //Verifica se o primeiro e ultimo valor são os mesmos
void    InsereListaMineral(ListaMineral* Lista, Mineral Mineral);               //Insere um novo valor na lista
int     RetiraListaMineral(ListaMineral* Lista, Mineral* Mineral, Apontador p); //Retira um valor específico da lista
void    ImprimeListaMineral(ListaMineral* Lista);                               //Imprime todos os valores da lista


#endif