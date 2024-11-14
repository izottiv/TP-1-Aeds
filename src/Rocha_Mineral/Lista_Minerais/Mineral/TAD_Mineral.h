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
char* getNome(Mineral* amostra);
float getDureza(Mineral* amostra);
float getReatividade(Mineral* amostra);
Cores getCor(Mineral* amostra);

//Sets
void setNome(Mineral* amostra, char* nome);
void setDureza(Mineral* amostra, float dureza);
void setReatividade(Mineral* amostra, float reatividade);
void setCor(Mineral* amostra, Cores cor);

//Inicialização do Mineral
void InicializaMineral(Mineral* amostra, char* mineral);
void ImprimeMineral(Mineral* amostra);

#endif