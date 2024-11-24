#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TAD_Sonda.h"

void InicializarSonda(Sonda* NovaSonda){
    NovaSonda->EstaLigada = 0;
    NovaSonda->CapacidadeMaximaSonda = 0.0;
    NovaSonda->VelocidadeSonda = 0.0;
    NovaSonda->NivelIncialCombustivel = 0.0;
    NovaSonda->IdentificadorSonda = 1 + rand() % 100;
    NovaSonda->LocalizacaoSonda.Latitude = 0.0;
    NovaSonda->LocalizacaoSonda.Longitude = 0.0;
    InicializadorCompartimento(&(NovaSonda->CompartimentoSonda));
}
void ModificarValoresSonda(Sonda* NovaSonda, Localizacao local, float Capacidade, float velocidade, float compustivel){
    NovaSonda->LocalizacaoSonda = local;
    NovaSonda->CapacidadeMaximaSonda = Capacidade;
    NovaSonda->VelocidadeSonda = velocidade;
    NovaSonda->NivelIncialCombustivel = compustivel;
}
void LigarSonda(Sonda* NovaSonda){
    NovaSonda->EstaLigada = 1;
    printf("Sonda Ligada\n");
}
void DesligarSonda(Sonda* NovaSonda){
    NovaSonda->EstaLigada = 0;
    printf("Sonda Desligada\n");
}
void MoverSonda(Sonda* NovaSonda, float latitude, float longitude){
    NovaSonda->LocalizacaoSonda.Latitude = latitude;
    NovaSonda->LocalizacaoSonda.Longitude = longitude;
}
void EditarValores(Sonda* NovaSonda, float capacidade, float velocidade, float combustivel){
    NovaSonda->CapacidadeMaximaSonda = capacidade;
    NovaSonda->VelocidadeSonda = velocidade;
    NovaSonda->NivelIncialCombustivel = combustivel;
}  