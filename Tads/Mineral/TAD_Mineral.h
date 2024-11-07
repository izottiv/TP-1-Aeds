#ifndef TAD_MINERAL_H
#define TAD_MINERAL_H

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
}Mineral;

//Sets
void setNome(Mineral* amostra, char* nome);
void setDureza(Mineral* amostra, float dureza);
void setReatividade(Mineral* amostra, float reatividade);
void setCor(Mineral* amostra, Cores cor);

//Gets
char* getNome(Mineral* amostra);
float getDureza(Mineral* amostra);
float getReatividade(Mineral* amostra);
Cores getCor(Mineral* amostra);

//inicialização
void inicializacao(Mineral* amostra, char* nome, float dureza, float reatividade, Cores cor);

#endif