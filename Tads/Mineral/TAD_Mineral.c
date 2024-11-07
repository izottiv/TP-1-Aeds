#include <stdio.h>
#include <string.h>
#include "TAD_Mineral.h"

//Definindo os sets
void setNome(Mineral* amostra, char* nome){
    strcpy(amostra->nome, nome);
}
void setDureza(Mineral* amostra, float dureza){
    amostra->dureza = dureza;
}
void setReatividade(Mineral* amostra, float reatividade){
    amostra->reatividade = reatividade;
}
void setCor(Mineral* amostra, Cores cor){
    amostra->Cor = cor;
}

//Definindo os gets
char* getNome(Mineral* amostra){
    return (amostra->nome);
}
float getDureza(Mineral* amostra){
    return amostra->dureza;
}
float getReatividade(Mineral* amostra){
    return amostra->reatividade;
}
Cores getCor(Mineral* amostra){
    return amostra->Cor;
}

//Definindo a inicialização
void inicializacao(Mineral* amostra, char* nome, float dureza, float reatividade, Cores cor){
    setNome(amostra, nome);
    setDureza(amostra, dureza);
    setReatividade(amostra, reatividade);
    setCor(amostra, cor);
}