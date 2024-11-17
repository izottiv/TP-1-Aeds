#ifndef TAD_COMPARTIMENTO_H
#define TAD_COMPARTIMENTO_H
#include "Rocha_Mineral/TAD_RochaMineral.h"

typedef struct PreCelulaMineral{
    RochaMineral _RochaMineral;
    struct PreCelulaMineral *Prox;
} Compartimento;

typedef struct {
    Compartimento *PrimeiroRocha;
    Compartimento *UltimoRocha;
} GerenciadorCompartimento;

void InicializadorCompartimento(GerenciadorCompartimento *Comp);
int RetornaTamanho(GerenciadorCompartimento *comp);
int VerificaSeVazia(GerenciadorCompartimento *comp);
void ImprimeConteudoCompartimento(GerenciadorCompartimento *comp);
float PesoAtualCompartimento(GerenciadorCompartimento *comp);

void TrocaRocha(GerenciadorCompartimento *comp, RochaMineral *Rocha);
void InserirRocha(GerenciadorCompartimento *comp, RochaMineral *Rocha, float PESOTOTAL);
int VerificasePodeInserirRocha(GerenciadorCompartimento *comp, RochaMineral *Rocha, float PESOTOTAL);

void RemoverRochaPorCategoria(GerenciadorCompartimento*comp, RochaMineral *RochaRetirada, Categorias Categoria);
void ImprimeCategoriaPeso(GerenciadorCompartimento* comp);

#endif