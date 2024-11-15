#ifndef TAD_ROCHAMINERAL_H
#define TAD_ROCHAMINERAL_H

#include "Lista_Minerais/TAD_ListaMineral.h"
#include "Categorias/TAD_Categorias.h"
#include "Localizacao/TAD_Localizacao.h"
#include "Data_Coleta/TAD_DataColeta.h"

//Struct dos Dados da Rocha Mineral
typedef struct {
    int Identificador;
    float Peso;
    ListaMineral _ListaMineral;
    Categorias _Categorias;
    Localizacao _Localizacao;
    DataColeta _DataColeta;
} RochaMineral;

//Gets
int GetIdentificador(RochaMineral* Rocha);
float GetPeso(RochaMineral* Rocha);
ListaMineral GetListaMineral(RochaMineral* Rocha);
Categorias GetCategorias(RochaMineral* Rocha);
Localizacao GetLocalizacao(RochaMineral* Rocha);
DataColeta GetDataColeta(RochaMineral* Rocha);

//Sets
void SetIdentificador(RochaMineral* Rocha, int ID);
void SetPeso(RochaMineral* Rocha, float PESO);
void SetListaMineral(RochaMineral* Rocha, ListaMineral LISTAMINERAL);
void SetCategorias(RochaMineral* Rocha, Categorias CATEGORIA);
void SetLocalizacao(RochaMineral* Rocha, Localizacao LOCALIZACAO);
void SetDataColeta(RochaMineral* Rocha, DataColeta DATACOLETA);

//Funções da Rocha Mineral
void InicializaRochaMineral();  //Seta os valores do struct
// void ObtemRochaMineral();       //Obtem os valores da Rocha Mineral
// void AtribuiRochaMineral();     //Atribui novos valores para a Rocha Mineral



#endif