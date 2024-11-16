#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TAD_DataColeta.h"

void DefineDataHora(DataColeta* data){
    struct tm *data_hora;
    time_t segundos;
    time(&segundos);
    data_hora = localtime(&segundos);
    data->dia = data_hora->tm_mday;
    data->mes = data_hora->tm_mon+1;
    data->ano = data_hora->tm_year+1900;
    data->hora = data_hora->tm_hour;
    data->minuto = data_hora->tm_min;
    data->segundo = data_hora->tm_sec;

}