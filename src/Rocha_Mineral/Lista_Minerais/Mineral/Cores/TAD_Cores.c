#include<stdio.h>
#include "TAD_Cores.h"

void RetornarCores(Cores* cor){
    switch (*cor)
    {
    case Acinzentado:
        printf("Acinzentado");
        break;
    case Amarelo:
        printf ("Amarelo");
        break;
    case Azulado:
        printf ("Azulado");
        break;
    case Marrom:
        printf ("Marrom");
        break;
    case Vermelho:
        printf("Vermelho");
        break;
    default:
        break;
    }
}