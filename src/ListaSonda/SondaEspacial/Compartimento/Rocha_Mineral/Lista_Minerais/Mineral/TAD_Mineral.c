#include <stdio.h>
#include <string.h>
#include "TAD_Mineral.h"

//Definindo os gets
char* GetNome(Mineral* amostra){
    return (amostra->nome);
}
float GetDureza(Mineral* amostra){
    return amostra->dureza;
}
float GetReatividade(Mineral* amostra){
    return amostra->reatividade;
}
Cores GetCor(Mineral* amostra){
    return(amostra->_cor);
}

//Definindo os sets
void SetNome(Mineral* amostra, char* nome){
    strcpy(amostra->nome, nome);
}
void SetDureza(Mineral* amostra, float dureza){
    amostra->dureza = dureza;
}
void SetReatividade(Mineral* amostra, float reatividade){
    amostra->reatividade = reatividade;
}
void SetCor(Mineral* amostra, Cores cor){
    amostra->_cor = cor;
}

//Definindo a inicialização
void InicializaMineral(Mineral* amostra, char* mineral){
    if(strcmp(mineral, "Ferrolita") == 0){
        SetNome(amostra, "Ferrolita");
        SetDureza(amostra, 0.5);
        SetReatividade(amostra, 0.7);
        SetCor(amostra, 0);
    }
    if(strcmp(mineral, "Solarium") == 0){
        SetNome(amostra, "Solarium");
        SetDureza(amostra, 0.9);
        SetReatividade(amostra, 0.2);
        SetCor(amostra, 1);
    }
    if(strcmp(mineral, "Aquavitae") == 0){
        SetNome(amostra, "Aquavitae");
        SetDureza(amostra, 0.5);
        SetReatividade(amostra, 0.8);
        SetCor(amostra, 2);
    }
    if(strcmp(mineral, "Terranita") == 0){
        SetNome(amostra, "Terranita");
        SetDureza(amostra, 0.7);
        SetReatividade(amostra, 0.6);
        SetCor(amostra, 3);
    }
    if(strcmp(mineral, "Calaris") == 0){
        SetNome(amostra, "Calaris");
        SetDureza(amostra, 0.6);
        SetReatividade(amostra, 0.5);
        SetCor(amostra, 4);
    }
}

