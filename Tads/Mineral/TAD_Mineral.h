#ifndef TAD_MINERAL_
#define TAD_MINERAL_

//Definindo as Cores
typedef enum{
    Acinzentado,
    Amarelo,
    Azulado,
    Marrom,
    Vermelho
}Cores;

//Criando o tipo Mineral
typedef struct{
    char nome[10];
    float dureza;
    float reatividade;
    Cores Cor;
} Mineral;

//Sets
void setNome(Mineral* amostra, char* nome);
void setDureza(Mineral* amostra, float dureza);




#endif