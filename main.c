#include <stdio.h>
#include <stdlib.h>
#include "src/SistemadeControle.h"
#include "src/EntradaDeArquivo.h"

int main(){
    int x;
    printf("Digite algo:");
    scanf("%d",&x);
    if (x == 1){
        Inicializacao();
    }
    else{
        EntradaDeArquivo("src/Entradas/Entrada.txt");
    }
    return 0;
}