#include <stdio.h>
#include <stdlib.h>
#include "src/ListaSonda/TAD_ListaSonda.h"

int main(){

    Localizacao loc;
    loc.Latitude = 7777;
    loc.Longitude = 8888;
    ListaMineral mineralp;
    RochaMineral Batata,cenoura,beterraba,rabanete;
    GerenciadorCompartimento pedro;
    InicializaRochaMineral(&Batata,10,mineralp,Ferrom,loc);
    InicializaRochaMineral(&cenoura,15,mineralp,Terrasol,loc);
    InicializaRochaMineral(&rabanete,20,mineralp,Calquer,loc);
    InicializadorCompartimento(&pedro);
    InserirRocha(&pedro,&Batata,500);
    InserirRocha(&pedro,&cenoura,500);
    InserirRocha(&pedro,&rabanete,500);
    ImprimeConteudoCompartimento(&pedro);
    printf("---------------------------------------------\n");
    RemoverRochaPorCategoria(&pedro,&beterraba,Ferrom);
    RemoverRochaPorCategoria(&pedro,&beterraba,Terrasol);

    ImprimeConteudoCompartimento(&pedro);
    return 0;
}