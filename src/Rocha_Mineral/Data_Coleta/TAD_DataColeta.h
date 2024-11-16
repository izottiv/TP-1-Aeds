#ifndef TAD_DATACOLETA_H
#define TAD_DATACOLETA_H

//Struct da Data de Coleta
typedef struct 
{
    int dia;
    int mes;
    int ano;

    int hora;
    int minuto;
    int segundo;
} DataColeta;

void DefineDataHora(DataColeta* data);

#endif