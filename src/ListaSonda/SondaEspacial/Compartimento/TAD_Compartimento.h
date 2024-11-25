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

// Inicializa um Compartimento
void InicializadorCompartimento(GerenciadorCompartimento *Comp);

// Retorna A quantidade de rocha que estao no compartimento
int RetornaTamanho(GerenciadorCompartimento *comp);

// Verifica se o compartimento esta vazio
int VerificaSeVazia(GerenciadorCompartimento *comp);

// Imprime as informaçoes do Compartimento
void ImprimeConteudoCompartimento(GerenciadorCompartimento *comp);

// Retorna o peso atual do compartimento
float PesoAtualCompartimento(GerenciadorCompartimento *comp);

// Troca uma rocha por outra no compartimento 
void TrocaRocha(GerenciadorCompartimento *comp, RochaMineral *Rocha);

// Insere uma rocha em um compartimento
void InserirRocha(GerenciadorCompartimento *comp, RochaMineral *Rocha, float PESOTOTAL);

// Retorna valores que simbolizam alguns caso de entrada
int VerificasePodeInserirRocha(GerenciadorCompartimento *comp, RochaMineral *Rocha, float PESOTOTAL,int Categoria);

// Remove uma rocha de uma categoria e retorna a mesma para ser usada
void RemoverRochaPorCategoria(GerenciadorCompartimento *comp, RochaMineral *RochaRetirada, Categorias Categoria);

// Imprime as categorias e pesos de um compartimento
void ImprimeCategoriaPeso(GerenciadorCompartimento* comp);

// Insere uma rocha sem nenhuma limitacao
void InserirRochaMedia(GerenciadorCompartimento *comp, RochaMineral *Rocha);

// Retorna quantas rocha tem em um compartimento 
int QuantasRochasEmCompartimento(GerenciadorCompartimento *comp);

#endif