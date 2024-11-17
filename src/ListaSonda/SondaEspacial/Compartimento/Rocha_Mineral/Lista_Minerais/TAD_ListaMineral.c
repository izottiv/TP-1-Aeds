#include <stdio.h>
#include <string.h>
#include "TAD_ListaMineral.h"

//Inicializa a lista vazia
void InicializaListaMineral(ListaMineral* Lista){
    Lista->_Primeiro = InicioArranjo;
    Lista->_Ultimo = Lista->_Primeiro;
}

//Insere um novo valor na lista
void InsereListaMineral(ListaMineral* Lista, Mineral Mineral){
    if (Lista->_Ultimo == MaxTam){
    printf("A lista está cheia!");
    }

    else{
        Lista->_Mineral[Lista->_Ultimo++] = Mineral;
        printf("Adicionado com sucesso!");
    }
}

//Retira um valor específico da lista
int RetiraListaMineral(ListaMineral* Lista, Mineral* Mineral, char* nome){
    int cont = -1;
    if (Lista->_Primeiro == Lista->_Ultimo){
        return 0;
    }
    else{
        for(int i=Lista->_Primeiro;i<Lista->_Ultimo;i++){
            if(strcmp(Lista->_Mineral[i].nome, nome)){
                *Mineral = Lista->_Mineral[i];
                int cont = i;  
                break;
            }
        }
        if(cont == -1){
            return 0;
        }
        for(int j=cont;j<Lista->_Ultimo;j++){
            Lista->_Mineral[j] = Lista->_Mineral[j+1];
            }
        Lista->_Ultimo--;
        return 1;
    }
}

//Imprime todos os valores da lista
void ImprimeListaMineral(ListaMineral* Lista){
    int i;
    for (i = Lista->_Primeiro; i < Lista->_Ultimo; i++){
        printf("%s\n", Lista->_Mineral[i].nome);
        printf("%.2f\n", Lista->_Mineral[i].dureza);
        printf("%.2f\n", Lista->_Mineral[i].reatividade);
        RetornarCores(&(Lista->_Mineral[i]._cor));
        printf("\n");
    }
}