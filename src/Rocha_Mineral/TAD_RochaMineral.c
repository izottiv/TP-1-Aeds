#include "TAD_RochaMineral.h"
#include <string.h>

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
void SetIdentificador(RochaMineral* Rocha, int ID){
    Rocha->Identificador = ID;
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
void InicializaRochaMineral(RochaMineral* Rocha, int ID , float PESO, ListaMineral LISTAMINERAL, Categorias CATEGORIA, Localizacao LOCALIZACAO, DataColeta DATACOLETA){
    SetIdentificador(Rocha, ID);
    SetPeso(Rocha, PESO);
    SetListaMineral(Rocha, LISTAMINERAL);
    SetCategorias(Rocha, CATEGORIA);
    SetLocalizacao(Rocha, LOCALIZACAO);
    SetDataColeta(Rocha, DATACOLETA);
}

// //Obtem os valores da Rocha Mineral
// void ObtemRochaMineral(){

// }

// //Atribui novos valores para a Rocha Mineral
// void AtribuiRochaMineral(){

// }


    