#ifndef TAD_MINERAL_H
#define TAD_MINERAL_H

#include "Cores/TAD_Cores.h"

//Struct do Mineral
typedef struct{
    char nome[10];
    float dureza;
    float reatividade;
    Cores _cor;
} Mineral;

//Gets
char* GetNome(Mineral* amostra);
float GetDureza(Mineral* amostra);
float GetReatividade(Mineral* amostra);
Cores GetCor(Mineral* amostra);

//Sets
void SetNome(Mineral* amostra, char* nome);
void SetDureza(Mineral* amostra, float dureza);
void SetReatividade(Mineral* amostra, float reatividade);
void SetCor(Mineral* amostra, Cores cor);

//Inicialização do Mineral
void InicializaMineral(Mineral* amostra, char* mineral);

#endif