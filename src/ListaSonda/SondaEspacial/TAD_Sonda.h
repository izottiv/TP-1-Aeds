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

// Inicializa a Sonda com valores padrões
void InicializarSonda(Sonda* NovaSonda);

// Modifica os valores da sonda
void ModificarValoresSonda(Sonda* NovaSonda, Localizacao local, float Capacidade, float velocidade, float compustivel);

//Liga a sonda
void LigarSonda(Sonda* NovaSonda);

//Desliga a sonda
void DesligarSonda(Sonda* NovaSonda);

//Move a sonda de posição
void MoverSonda(Sonda* NovaSonda, float latitude, float longitude);

#endif