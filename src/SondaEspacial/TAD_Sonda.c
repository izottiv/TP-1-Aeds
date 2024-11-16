#include <stdio.h>
#include <stdlib.h>
#include "TAD_Sonda.h"

void InicializarSonda(Sonda* NovaSonda, int Identificador){
    NovaSonda->EstaLigada = 0;
    NovaSonda->IdentificadorSonda = Identificador;
    NovaSonda->LocalizacaoSonda.Latitude = 0.0;
    NovaSonda->LocalizacaoSonda.Longitude = 0.0;
    InicaliazadorCompartimento(&(NovaSonda->CompartimentoSonda));
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
    printf("Sonda movida para:\n");
    printf("Latitude: %.2f\nLongitude: %.2f", NovaSonda->LocalizacaoSonda.Latitude, NovaSonda->LocalizacaoSonda.Longitude);
}  