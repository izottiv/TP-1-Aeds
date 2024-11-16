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

//Inicializa a lista vazia
void InicializaListaMineral(ListaMineral* Lista);   
//Insere um novo valor na lista                             
void InsereListaMineral(ListaMineral* Lista, Mineral Mineral);               
//Retira um valor específico da lista
int RetiraListaMineral(ListaMineral* Lista, Mineral* Mineral, char* nome); 
//Imprime todos os valores da lista
void ImprimeListaMineral(ListaMineral* Lista);                               

#endif