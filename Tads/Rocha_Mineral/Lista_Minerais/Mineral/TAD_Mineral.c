#include <stdio.h>
#include <string.h>
#include "TAD_Mineral.h"

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
    return(amostra->_cor);
}

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
    amostra->_cor = cor;
}

//Definindo a inicialização
void InicializaMineral(Mineral* amostra, char* mineral){
    if(strcmp(mineral, "Ferrolita") == 0){
        setNome(amostra, "Ferrolita");
        setDureza(amostra, 0.5);
        setReatividade(amostra, 0.7);
        setCor(amostra, 0);
    }
    if(strcmp(mineral, "Solarium") == 0){
        setNome(amostra, "Solarium");
        setDureza(amostra, 0.9);
        setReatividade(amostra, 0.2);
        setCor(amostra, 1);
    }
    if(strcmp(mineral, "Aquavitae") == 0){
        setNome(amostra, "Aquavitae");
        setDureza(amostra, 0.5);
        setReatividade(amostra, 0.8);
        setCor(amostra, 2);
    }
    if(strcmp(mineral, "Terranita") == 0){
        setNome(amostra, "Terranita");
        setDureza(amostra, 0.7);
        setReatividade(amostra, 0.6);
        setCor(amostra, 3);
    }
    if(strcmp(mineral, "Calaris") == 0){
        setNome(amostra, "Calaris");
        setDureza(amostra, 0.6);
        setReatividade(amostra, 0.5);
        setCor(amostra, 4);
    }
}

//Definindo o imprimir
void ImprimeMineral(Mineral* amostra){
    char tipo[50];
    switch (amostra->_cor)
    {
    case Acinzentado:
        strcpy(tipo, "Acinzentado");
        break;
    case Amarelo:
        strcpy(tipo, "Amarelo");
        break;
    case Azulado:
        strcpy(tipo, "Azulado");
        break;
    case Marrom:
        strcpy(tipo, "Marrom");
        break;
    case Vermelho:
        strcpy(tipo, "Vermelho");
        break;
    default:
        break;
    }
    printf("Nome: %s\nDureza: %f\nReatividade: %f\nCor: %s", getNome(amostra), 
    getDureza(amostra), getReatividade(amostra), tipo);
}
