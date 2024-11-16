#include <stdio.h>
#include <stdlib.h>
#include "TAD_Compartimento.h"

 // Inicializa um compartimento
void InicializadorCompartimento(GerenciadorCompartimento *Comp){
    Comp->PrimeiroRocha = (Compartimento*) malloc(sizeof(Compartimento));
    Comp->UltimoRocha = Comp->PrimeiroRocha;
    Comp->PrimeiroRocha->Prox = NULL;
    printf("Lista criada\n");
}

int RetornaTamanho(GerenciadorCompartimento *comp){
    if (VerificaSeVazia(comp) == 0){ // Conta Quantas rochas tem no compartimento E retorna esse valor
        Compartimento *aux;
        int x = 1;
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
    if(comp->PrimeiroRocha == comp->UltimoRocha){
        printf("Compartimento Vazio!\n");
        return(comp->PrimeiroRocha == comp->UltimoRocha);
    }
    else{
        return(comp->PrimeiroRocha == comp->UltimoRocha);
    }
}

void ImprimeConteudoCompartimento(GerenciadorCompartimento *comp){
     if(VerificaSeVazia(comp) == 1){
        Compartimento *aux;
        aux = comp->PrimeiroRocha->Prox;
        while (aux->Prox != NULL){
            printf("Indentificador: %d\n",aux->_RochaMineral.Identificador);
            printf("Peso: %lf\n",aux->_RochaMineral.Peso);
            printf("Minerais: \n"); //TERMINAR DEPOIS
            printf("Categoria: \n"); // TERMINAR DEPOIS
            printf("Latitude %lf Longitude: %lf\n",aux->_RochaMineral._Localizacao.Latitude,aux->_RochaMineral._Localizacao.Longitude);
            printf("Data De Coleta:\n");
            printf("%d/%d/%d as %d:%d:%d",aux->_RochaMineral._DataColeta.dia, aux->_RochaMineral._DataColeta.mes, aux->_RochaMineral._DataColeta.ano, aux->_RochaMineral._DataColeta.hora, aux->_RochaMineral._DataColeta.minuto, aux->_RochaMineral._DataColeta.segundo);
            printf("\n");
            aux = aux->Prox; 
        }
    }
}

float PesoAtualCompartimento(GerenciadorCompartimento *comp){
    if(VerificaSeVazia(comp) == 0){ // Verifica se o comparitmento é vazio
        float peso = 0; // Soma o peso de todas as rochas no compartimento
        Compartimento *aux;
        aux = comp->PrimeiroRocha->Prox;
            while (aux->Prox != NULL){
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
    if(PesoAtualCompartimento(comp) + Rocha->Peso <= PESOTOTAL){ // verificando se o peso da nova rocha é maior do que a sonda suporta
        int aux = 0;
        Compartimento *Compartimentoaux;
        Compartimentoaux = comp->PrimeiroRocha->Prox;        
        while (Compartimentoaux->Prox != NULL){// verificando se a rochas repetidas
            if(Compartimentoaux->_RochaMineral._Categorias == Rocha->_Categorias){ // Mudar _categotias para outra coisa se nao for esse identificasao
                aux++;
            }
            Compartimentoaux = Compartimentoaux->Prox;
        }
        if(aux > 0){ // adicionando a rocha no final da lista
            comp->UltimoRocha->Prox = (Compartimento*) malloc(sizeof(Compartimento));
            comp->UltimoRocha = comp->UltimoRocha->Prox;
            comp->UltimoRocha->_RochaMineral = *Rocha;
            comp->UltimoRocha->Prox = NULL;
            }   
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
    Compartimento *aux, *AuxCont;
    if (VerificaSeVazia(comp) == 0){
        return;
    }
    int possicaosecundaria;
    int pos = 1;
    AuxCont = comp->PrimeiroRocha->Prox;
    while (AuxCont->Prox != NULL){  // Procura a primeira rocha que tem a mesma categoria dada tira ela da lista e aloca ela em RochaRetirada
        if (AuxCont->_RochaMineral._Categorias == Categoria){
            *RochaRetirada = AuxCont->_RochaMineral;    
            if(pos == 1){ // No caso do primeiro elemento da lista ser da mesma categoria
                aux = comp->PrimeiroRocha;
                comp->PrimeiroRocha = comp->PrimeiroRocha->Prox;
                free(aux);
                break;
                }
            }
            else if(pos == RetornaTamanho(comp)){   // No caso do ultimo elemento da lista ser da mesma categoria
                pos = 1;
                AuxCont = comp->PrimeiroRocha->Prox;
                while (AuxCont->Prox != NULL){
                    if (pos == RetornaTamanho(comp)-1){
                        aux = AuxCont->Prox;
                        AuxCont->Prox == NULL;
                        free(aux);
                        break;
                    }
                    pos++;
                }
                break;
            }
            else{ // Se o elemento da lista ser da mesma categoria estja no meio
                aux = AuxCont;
                possicaosecundaria = pos;
                pos = 0;
                AuxCont = comp->PrimeiroRocha->Prox;
                while (AuxCont->Prox != NULL){
                    if(pos == possicaosecundaria-1){
                        AuxCont->Prox = aux->Prox;
                        free(aux);
                        break;
                    }
                    pos++;
                    AuxCont = AuxCont->Prox;
                }
            }
        pos++;
        AuxCont = AuxCont->Prox;
    }
    
}

