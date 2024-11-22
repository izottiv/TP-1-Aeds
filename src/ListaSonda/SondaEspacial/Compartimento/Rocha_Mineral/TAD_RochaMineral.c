#include "TAD_RochaMineral.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//Gets
int GetIdentificador(RochaMineral* Rocha){
    return Rocha->Identificador;
}
float GetPeso(RochaMineral* Rocha){
    return Rocha->Peso;
}
ListaMineral GetListaMineral(RochaMineral* Rocha){
    return Rocha->_ListaMineral;
}
Categorias GetCategorias(RochaMineral* Rocha){
    return Rocha->_Categorias;
}
Localizacao GetLocalizacao(RochaMineral* Rocha){
    return Rocha->_Localizacao;
}
DataColeta GetDataColeta(RochaMineral* Rocha){
    return Rocha->_DataColeta;
}

//Sets
void SetIdentificador(RochaMineral* Rocha){
    Rocha->Identificador = 100 + rand() % 100;
}
void SetPeso(RochaMineral* Rocha, float PESO){
    Rocha->Peso = PESO;
}
void SetListaMineral(RochaMineral* Rocha, ListaMineral LISTAMINERAL){
    Rocha->_ListaMineral = LISTAMINERAL;
}
void SetCategorias(RochaMineral* Rocha, Categorias CATEGORIA){
    Rocha->_Categorias = CATEGORIA;
}
void SetLocalizacao(RochaMineral* Rocha, Localizacao LOCALIZACAO){
    Rocha->_Localizacao = LOCALIZACAO;
}
void SetDataColeta(RochaMineral* Rocha, DataColeta DATACOLETA){
    Rocha->_DataColeta = DATACOLETA;
}

//Seta os valores do struct
void InicializaRochaMineral(RochaMineral* Rocha, float PESO, ListaMineral LISTAMINERAL, Localizacao LOCALIZACAO){
    SetIdentificador(Rocha);
    SetPeso(Rocha, PESO);
    SetListaMineral(Rocha, LISTAMINERAL);
    SetLocalizacao(Rocha, LOCALIZACAO);
    DefineDataHora(&(Rocha->_DataColeta));
}

void ClassificaCategoria(RochaMineral* Rocha, int numerodeminerais){
    int Ferrolita = 0;
    int Solarium = 0; 
    int Aquavitae = 0;
    int Terranita = 0;
    int Calaris = 0;

    for (int i = 0; i < numerodeminerais; i++){

        if(strcmp(Rocha->_ListaMineral._Mineral[i].nome, "Ferrolita")== 0 || strcmp(Rocha->_ListaMineral._Mineral[i].nome, "Ferrolita\n")== 0){
            Ferrolita = 1;
        }
        if(strcmp(Rocha->_ListaMineral._Mineral[i].nome, "Solarium") == 0 || strcmp(Rocha->_ListaMineral._Mineral[i].nome, "Solarium\n") == 0){
            Solarium = 1;
        }
        if(strcmp(Rocha->_ListaMineral._Mineral[i].nome, "Aquavitae") == 0 || strcmp(Rocha->_ListaMineral._Mineral[i].nome, "Aquavitae\n") == 0){
            Aquavitae = 1;
        }
        if(strcmp(Rocha->_ListaMineral._Mineral[i].nome, "Terranita") == 0 || strcmp(Rocha->_ListaMineral._Mineral[i].nome, "Terranita\n") == 0){
            Terranita = 1;
        }
        if(strcmp(Rocha->_ListaMineral._Mineral[i].nome, "Calaris") == 0 || strcmp(Rocha->_ListaMineral._Mineral[i].nome, "Calaris\n") == 0){
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

void TransformarCategoria(RochaMineral* Rocha){
    switch (Rocha->_Categorias)
    {
    case Ferrom:
        printf("Ferrom");
        break;
    case Solaris:
        printf("Solaris");
        break;
    case Aquaferro:
        printf("Aquaferro");
        break;
    case Terrolis:
        printf("Terrolis");
        break;
    case Terrasol:
        printf("Terrasol");
        break;
    case Aquaterra:
        printf("Aquaterra");
        break;
    case Calquer:
        printf("Calquer");
        break;
    case Solarisfer:
        printf("Solarisfer");
        break;
    case Terralis:
        printf("Terralis");
        break;
    case Aquacalis:
        printf("Aquacalis");
        break;
    default:
        break;
    }
}   