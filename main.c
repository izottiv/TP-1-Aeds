#include <stdio.h>
#include <stdlib.h>
#include "src/EntradaDeArquivo.h"
#include "src/SistemadeControle.h"

int main(){
    int escolha, escolha2;
    printf("Gostaria de fazer a entrada por:\n1-Arquivo\n2-Terminal\n");
    scanf("%d", &escolha);
    if (escolha == 1){
        printf("Deseja utilizar qual arquivo de teste?\n1-Aquivo 1\n2-Arquivo 2\n");
        scanf("%d", &escolha2);
        if(escolha2 == 1){
            EntradaDeArquivo("src/Entradas/Entrada.txt");
        }
        if(escolha2 == 2){
            EntradaDeArquivo("src/Entradas/Entrada2.txt");
        }
        
        }
    if(escolha == 2){
        Inicializacao();
    }

    return 0;
}