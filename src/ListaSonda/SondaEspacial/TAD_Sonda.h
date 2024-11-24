#ifndef TAD_SONDA_H_
#define TAD_SONDA_H_
#include "Compartimento/TAD_Compartimento.h"

typedef struct{
    int IdentificadorSonda;
    float CapacidadeMaximaSonda;
    float VelocidadeSonda;
    float NivelIncialCombustivel;
    GerenciadorCompartimento CompartimentoSonda;
    Localizacao LocalizacaoSonda;
    int EstaLigada; //0 = desligada, 1 = ligada
} Sonda;

void InicializarSonda(Sonda* NovaSonda);
void ModificarValoresSonda(Sonda* NovaSonda, Localizacao local, float Capacidade, float velocidade, float compustivel);
void LigarSonda(Sonda* NovaSonda);
void DesligarSonda(Sonda* NovaSonda);
void MoverSonda(Sonda* NovaSonda, float latitude, float longitude);
void EditarValores(Sonda* NovaSonda, float capacidade, float velocidade, float combustivel);

#endif