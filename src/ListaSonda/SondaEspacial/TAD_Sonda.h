#ifndef TAD_SONDA_H_
#define TAD_SONDA_H_
#include "Compartimento/TAD_Compartimento.h"

typedef struct{
    int IdentificadorSonda;
    GerenciadorCompartimento CompartimentoSonda;
    Localizacao LocalizacaoSonda;
    int EstaLigada; //0 = desligada, 1 = ligada
} Sonda;

void InicializarSonda(Sonda* NovaSonda);
void LigarSonda(Sonda* NovaSonda);
void DesligarSonda(Sonda* NovaSonda);
void MoverSonda(Sonda* NovaSonda, float latitude, float longitude);

#endif