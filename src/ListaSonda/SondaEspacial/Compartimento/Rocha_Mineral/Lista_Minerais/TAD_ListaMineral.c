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
    // printf("A lista está cheia!");
    }

    else{
        Lista->_Mineral[Lista->_Ultimo++] = Mineral;

        // printf("Adicionado com sucesso!\n");

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
        switch (Lista->_Mineral[i]._cor)
        {
        case 0:
            printf("Acinzentado");
            break;

        case 1:
            printf("Amarelo");
            break;

        case 2:
            printf("Azulado");
            break;

        case 3:
            printf("Marrom");
            break;

        case 4:
            printf("Vermelho");
            break;

        default:
            break;
        }
        printf("\n");
    }
}

//Imprime apenas os nomes dos minerais da lista
void ImprimeNomesDosMineraisDaLista(ListaMineral* lista){
    for(int i=0; i < lista->_Ultimo; i++){
        printf("%s ", lista->_Mineral[i].nome);
    }
    printf("\n");
} 