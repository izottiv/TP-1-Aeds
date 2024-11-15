#ifndef TAD_COMPARTIMENTO
#define TAD_COMPARTIMENTO

typedef struct PreCelulaMineral{
    RochaMineral _RochaMineral;
    struct PreCelulaMineral *Prox;
} Compartimento;

typedef struct {
    Compartimento *PrimeiroRocha;
    Compartimento *UltimoRocha;
}GerenciadorCompartimento;

void InicaliazadorCompartimento(GerenciadorCompartimento *Comp);
int RetornaTamanho(GerenciadorCompartimento *comp);
int VerificaSeVazia(GerenciadorCompartimento *comp);
void ImprimeConteudoCompartimento(GerenciadorCompartimento *comp);
float PesoAtualCompartimento(GerenciadorCompartimento *comp);
void TrocaRocha(GerenciadorCompartimento *comp, RochaMineral *Rocha);
void InserirRocha(GerenciadorCompartimento *comp, RochaMineral *Rocha, float PESOTOTAL);
void RemoverRochaPorCategoria(GerenciadorCompartimento*comp, RochaMineral *RochaRetirada);

#endif