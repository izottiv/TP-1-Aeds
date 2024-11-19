#include <stdio.h>
#include <string.h>

#define MAX_ROCHAS 100
#define MAX_sondas 10
#define MAX_Categoria 20

typedef struct {
    char Categoria[MAX_Categoria];
    float peso;
} Rocha;

typedef struct {
    Rocha Rochas[MAX_ROCHAS];
    int qtdRochas;
    float pesoTotal;
} Sonda;

while(_ListaDeSonda.Sondas.Prox != NULL){

}


void distribuirRochas(Rocha Rochas[], int n, Sonda sondas[], int numsondas) {
    for (int i = 0; i < numsondas; i++) {
        sondas[i].qtdRochas = 0;
        sondas[i].pesoTotal = 0;
    }

    for (int i = 0; i < n; i++) {
        int melhorSonda = -1;
        float menorDiferencaPeso = __FLT_MAX__;
        
        for (int j = 0; j < numsondas; j++) {
            int CategoriaRepetida = 0;

            // Verifica se a Categoria já está no galpão
            for (int k = 0; k < sondas[j].qtdRochas; k++) {
                if (strcmp(sondas[j].Rochas[k].Categoria, Rochas[i].Categoria) == 0) {
                    CategoriaRepetida = 1;
                    break;
                }
            }

            if (!CategoriaRepetida) {
                float diferencaPeso = sondas[j].pesoTotal + Rochas[i].peso;
                if (diferencaPeso < menorDiferencaPeso) {
                    menorDiferencaPeso = diferencaPeso;
                    melhorSonda = j;
                }
            }
        }

        if (melhorSonda != -1) {
            // Adiciona o Rocha ao melhor galpão
            sondas[melhorSonda].Rochas[sondas[melhorSonda].qtdRochas] = Rochas[i];
            sondas[melhorSonda].qtdRochas++;
            sondas[melhorSonda].pesoTotal += Rochas[i].peso;
        }
    }
}

int main() {
    distribuirRochas();

    return 0;
}
