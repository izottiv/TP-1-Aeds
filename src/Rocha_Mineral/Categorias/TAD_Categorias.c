#include "TAD_Categorias.h"
#include "./TAD_RochaMineral.h"

//Classifica as CATEGORIAS de uma rocha
void ClassificaCategoria(RochaMineral* Rocha){
    int Ferrolita = 0, Solarium = 0, Aquavitae = 0, Terranita = 0, Calaris = 0;

    Rocha->_ListaMineral._Mineral[0].nome;
    for (int i = 0; i < sizeof(Rocha->_ListaMineral._Mineral); i++)
    {
        if(strcmp(Rocha->_ListaMineral._Mineral[0].nome, "Ferrolita")){
            Ferrolita = 1;
        }
        if(strcmp(Rocha->_ListaMineral._Mineral[0].nome, "Solarium")){
            Solarium = 1;
        }
        if(strcmp(Rocha->_ListaMineral._Mineral[0].nome, "Aquavitae")){
            Aquavitae = 1;
        }
        if(strcmp(Rocha->_ListaMineral._Mineral[0].nome, "Terranita")){
            Terranita = 1;
        }
        if(strcmp(Rocha->_ListaMineral._Mineral[0].nome, "Calaris")){
            Calaris = 1;
        }
    }

    if( Ferrolita == 1 && Solarium == 0 && Aquavitae == 0 && Terranita == 0 && Calaris == 0 ){
        Rocha->_Categorias = Ferrom;
    }
    if( Ferrolita == 0 && Solarium == 1 && Aquavitae == 0 && Terranita == 0 && Calaris == 0 ){
        Rocha->_Categorias = Solaris;
    }
    if( Ferrolita == 1 && Solarium == 0 && Aquavitae == 1 && Terranita == 0 && Calaris == 0 ){
        Rocha->_Categorias = Aquaferro;
    }
    if( Ferrolita == 0 && Solarium == 0 && Aquavitae == 0 && Terranita == 1 && Calaris == 1 ){
        Rocha->_Categorias = Terrolis;
    }
    if( Ferrolita == 0 && Solarium == 1 && Aquavitae == 0 && Terranita == 1 && Calaris == 0 ){
        Rocha->_Categorias = Terrasol;
    }
    if( Ferrolita == 0 && Solarium == 0 && Aquavitae == 1 && Terranita == 1 && Calaris == 0 ){
        Rocha->_Categorias = Aquaterra;
    }
    if( Ferrolita == 0 && Solarium == 0 && Aquavitae == 1 && Terranita == 0 && Calaris == 1 ){
        Rocha->_Categorias = Calquer;
    }
    if( Ferrolita == 1 && Solarium == 1 && Aquavitae == 0 && Terranita == 0 && Calaris == 0 ){
        Rocha->_Categorias = Solarisfer;
    }
    if( Ferrolita == 1 && Solarium == 0 && Aquavitae == 0 && Terranita == 1 && Calaris == 0 ){
        Rocha->_Categorias = Terralis;
    }
    if( Ferrolita == 1 && Solarium == 0 && Aquavitae == 1 && Terranita == 0 && Calaris == 1 ){
        Rocha->_Categorias = Aquacalis;
    }
}