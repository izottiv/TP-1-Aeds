#include <stdio.h>
#include <stdlib.h>
#include "TAD_Compartimento.h"

 // Inicializa um compartimento
void InicializadorCompartimento(GerenciadorCompartimento *Comp){
    Comp->PrimeiroRocha = (Compartimento*) malloc(sizeof(Compartimento));
    Comp->UltimoRocha = Comp->PrimeiroRocha;
    Comp->PrimeiroRocha->Prox = NULL;
}

int RetornaTamanho(GerenciadorCompartimento *comp){
    Compartimento *aux;
    int x = 1;
    if (VerificaSeVazia(comp) == 0){ // Conta Quantas rochas tem no compartimento E retorna esse valor
        aux = comp->PrimeiroRocha->Prox;
        while (aux->Prox != NULL){
            aux = aux->Prox; 
            x++;
        }
        return x;
    }
    else{
        return 0;
    }   
}

int VerificaSeVazia(GerenciadorCompartimento *comp){
    return(comp->PrimeiroRocha == comp->UltimoRocha);

}

void ImprimeConteudoCompartimento(GerenciadorCompartimento *comp){
     if(VerificaSeVazia(comp )== 0){
        Compartimento *aux;   
        aux = comp->PrimeiroRocha->Prox;
        while(aux != NULL){
            printf("=================================\n");
            printf("Indentificador: %d\n",aux->_RochaMineral.Identificador);
            printf("Peso: %.2f\n",aux->_RochaMineral.Peso);
            printf("Minerais: ");
            ImprimeNomesDosMineraisDaLista(&aux->_RochaMineral._ListaMineral);
            printf("Categoria: ");
            TransformarCategoria(&aux->_RochaMineral);
            printf("\n");
            printf("Latitude %.6f Longitude: %.6f\n",aux->_RochaMineral._Localizacao.Latitude,aux->_RochaMineral._Localizacao.Longitude);
            printf("Data De Coleta:\n");
            printf("%d/%d/%d as %d:%d:%d\n",aux->_RochaMineral._DataColeta.dia, aux->_RochaMineral._DataColeta.mes, aux->_RochaMineral._DataColeta.ano, aux->_RochaMineral._DataColeta.hora, aux->_RochaMineral._DataColeta.minuto, aux->_RochaMineral._DataColeta.segundo);
            aux = aux->Prox; 
        }
    }
}

float PesoAtualCompartimento(GerenciadorCompartimento *comp){
    if(VerificaSeVazia(comp) == 0){ // Verifica se o comparitmento é vazio
        float peso = 0; // Soma o peso de todas as rochas no compartimento
        Compartimento *aux;
        aux = comp->PrimeiroRocha->Prox;
            while (aux != NULL){
                peso = peso + aux->_RochaMineral.Peso;
                aux = aux->Prox; 
        }
        return peso;
    }
    else{
        return 0;
    }
}



void InserirRocha(GerenciadorCompartimento *comp, RochaMineral *Rocha, float PESOTOTAL){ //Informar o peso total que a sonda espacial suporta
    if(PESOTOTAL >= (PesoAtualCompartimento(comp) + Rocha->Peso)){//Verifica se o peso maximo e ecedido
        if (VerificaSeVazia(comp) == 1){// caso a lista esteja vazia coloca na ultima/primeira posicao da lista
            comp->UltimoRocha->Prox = (Compartimento*) malloc(sizeof(Compartimento));
            comp->UltimoRocha = comp->UltimoRocha->Prox;
            comp->UltimoRocha->_RochaMineral = *Rocha;
            comp->UltimoRocha->Prox = NULL;
        }
        else{// Caso nao esteja vazia procura uma rocha da mesma categoria
            Compartimento *ContadorLista;
            ContadorLista = comp->PrimeiroRocha;
            int repitidos = 0;
            while (ContadorLista->Prox != NULL){    
                    if(Rocha->_Categorias == ContadorLista->_RochaMineral._Categorias){ // caso tenha uma rocha da mesma categoria ela subistitui essa rocha pela recebida
                        if (Rocha->Peso < ContadorLista->_RochaMineral.Peso){ // verifica se a rocha e mais leve doq ja esta no compartimento
                            ContadorLista->_RochaMineral = *Rocha;
                        }
                        repitidos = 1;
                    }
                ContadorLista = ContadorLista->Prox;
            }
            if(repitidos == 0){// caso a lista nao tenha uma rocha de categoria iqual a recebida coloca a recebida na ultima possicao
                comp->UltimoRocha->Prox = (Compartimento*) malloc(sizeof(Compartimento));
                comp->UltimoRocha = comp->UltimoRocha->Prox;
                comp->UltimoRocha->_RochaMineral = *Rocha;   
                comp->UltimoRocha->Prox = NULL;
            }
        }

    }
}


int VerificasePodeInserirRocha(GerenciadorCompartimento *comp, RochaMineral *Rocha, float PESOTOTAL){ 
    if(PESOTOTAL >= (PesoAtualCompartimento(comp) + Rocha->Peso)){//Verifica se o peso maximo e ecedido caso eceda retorna 5
        if (VerificaSeVazia(comp) == 1){// caso a lista esteja vazia retorna zero onde vc precisa enserir a rocha
            return 0;
        }
        else{// Caso nao esteja vazia procura uma rocha da mesma categoria
            Compartimento *ContadorLista;
            ContadorLista = comp->PrimeiroRocha;
            int repitidos = 0;
            while (ContadorLista->Prox != NULL){    // verifica se tem uma mesma categoria
                    if(Rocha->_Categorias == ContadorLista->_RochaMineral._Categorias){ 
                        if (Rocha->Peso < ContadorLista->_RochaMineral.Peso){ // verifica se a rocha e mais leve doq ja esta no compartimento se sim retorna 1 e troca rocha
                            return 1;
                        }
                    else{
                        repitidos = 1;
                    }
                    }
                ContadorLista = ContadorLista->Prox;
            }
            if(repitidos == 1){// caso a lista nao esteja vazia e nao tenha uma rocha de categoria iqual a recebida coloca a recebida na ultima possicao retorna 2
                return 2;
            }
        }
    }
    else{// caso O peso e execido retorna 5 e a sonda é ignorada
        return 5;
    }
}


void TrocaRocha(GerenciadorCompartimento *comp, RochaMineral *Rocha){
    RochaMineral RochaAux;
    RochaAux.Peso = 0;
    int pos = 1;
    int posrocha;
    Compartimento *auxcomp;
    auxcomp = comp->PrimeiroRocha->Prox;
    while (auxcomp->Prox != NULL){ // Procura a Rocha mais pesada e da mesma categoria E quarda a possicao
        if(RochaAux.Peso < auxcomp->_RochaMineral.Peso && Rocha->_Categorias == auxcomp->_RochaMineral._Categorias){
            RochaAux.Peso = auxcomp->_RochaMineral.Peso;
            posrocha = pos;
        }
        pos++;
        auxcomp = auxcomp->Prox; 
    }
    pos = 1;
    auxcomp = comp->PrimeiroRocha->Prox;
    while (auxcomp->Prox != NULL){ // Procura a possicao da mais pessada e é subistiutida pela rocha enserida
        if (pos == posrocha){
            auxcomp->_RochaMineral.Identificador = Rocha->Identificador;
            auxcomp->_RochaMineral.Peso = Rocha->Peso;
            auxcomp->_RochaMineral._ListaMineral = Rocha->_ListaMineral;
            auxcomp->_RochaMineral._Localizacao= Rocha->_Localizacao;
            auxcomp->_RochaMineral._DataColeta = Rocha->_DataColeta;
        }
        pos++;
        auxcomp = auxcomp->Prox;
    }
}


void RemoverRochaPorCategoria(GerenciadorCompartimento*comp, RochaMineral *RochaRetirada, Categorias Categoria){
    Compartimento *aux, *AuxCont,*AuxContAnterior;
    if (VerificaSeVazia(comp) == 1){
        printf("LISTA VAZIA\n");
        return;
    }
    int possicaosecundaria;
    int pos = 1;
    int cancel = 0;
    AuxContAnterior = comp->PrimeiroRocha;
    AuxCont = comp->PrimeiroRocha->Prox;
    while (AuxCont != NULL){  // Procura a primeira rocha que tem a mesma categoria dada tira ela da lista e aloca ela em RochaRetirada
        if (AuxCont->_RochaMineral._Categorias == Categoria){
            *RochaRetirada = AuxCont->_RochaMineral;    
            if(pos == 1){ // No caso do primeiro elemento da lista ser da mesma categoria
                aux = comp->PrimeiroRocha;
                comp->PrimeiroRocha = comp->PrimeiroRocha->Prox;
                free(aux);
                break;
            }
            if(pos == RetornaTamanho(comp)){   // No caso do ultimo elemento da lista ser da mesma categoria
                    aux = AuxContAnterior->Prox;
                    AuxContAnterior->Prox = NULL;
                    free(aux);
                break;
            }
            if(pos < RetornaTamanho(comp) && pos > 1){ // Se o elemento da lista ser da mesma categoria estja no meio
                aux = AuxCont;
                AuxContAnterior->Prox = AuxCont->Prox;
                free(aux); 
                break;
            }
        }
    pos++;
    AuxContAnterior = AuxContAnterior->Prox;
    AuxCont = AuxCont->Prox;
    }
}

void ImprimeCategoriaPeso(GerenciadorCompartimento* comp){
    Compartimento *aux;   
        aux = comp->PrimeiroRocha->Prox;
        while(aux != NULL){
            TransformarCategoria(&(aux->_RochaMineral));
            printf(" ");
            printf("%.0f\n", aux->_RochaMineral.Peso);
            aux = aux->Prox; 
        }
}