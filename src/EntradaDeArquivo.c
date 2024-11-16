#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TamanhoMax 100

//Esta função serve para além de ler o link, manter organizado o main.c e com uma quantidade menor de elementos, tornando a visualização mais fácil
void EntradaDeArquivo(char* Link){

    FILE *ArquivoDeEntrada = fopen(Link, "r");

    //Precisarei salvar as LINHAS dos arquivos, quantas SONDAS e QUAIS são
    char Linha[TamanhoMax],*Sondas[TamanhoMax], *DadosDasSondas[TamanhoMax];
    int N_Sondas, Operacoes;
    

    //Recebe a quantidade de SONDAS da primeira linha
    fgets(Linha, sizeof(Linha), ArquivoDeEntrada);
    N_Sondas = atoi(Linha);
    printf("%d\n",N_Sondas);    //      Vai Apagar Dps/////////////

    //Como o vetor das sondas é um ponteiro, tenho de alocar dinamicamente a memória dele
    for (int i = 0; i < N_Sondas; i++)
    {
        Sondas[i] = (char*)malloc(TamanhoMax * sizeof(char));
    }

    //Salva todas as SONDAS em seu vetor
    for (int i = 0; i < N_Sondas; i++)
    {
        fgets(Linha, sizeof(Linha), ArquivoDeEntrada);  //Recebe as X sondas
        strcpy(Sondas[i], Linha);
    }
    
    //          Vai Apagar dps/////////////
    for (int i = 0; i < N_Sondas; i++)
    {
        printf("%s", Sondas[i]);
    }

    fgets(Linha, sizeof(Linha), ArquivoDeEntrada);      //Recebe as M operações
    Operacoes = atoi(Linha);
    
    //Aloca agora, também para as operacoes, criando um vetor único que vai salvar as novas rochar e seu índice para organizarmos depois
    for (int i = 0; i < Operacoes; i++)
    {
        DadosDasSondas[i] = (char*)malloc(TamanhoMax * sizeof(char));
    }

    for (int i = 0; i < Operacoes; i++)
    {
        fgets(Linha, sizeof(Linha), ArquivoDeEntrada);  //Recebe primeira operacao
        Linha[strcspn(Linha, "\n")] = '\0';             /*Sempre que eu tento manipular uma linha com o \n ele da erro, então com esta função eu sou capaz de trocar a sua ocorrencia por um nulo, eliminando as quebras de linha daquela linha salva */
        printf("ESTA LINHA >> %s\n", Linha);

        //Condicionais para fazer as OPERAÇÕES
        if(!strcmp(Linha, "R")){
            fgets(Linha, sizeof(Linha), ArquivoDeEntrada);  //Recebe a linha
            Linha[strcspn(Linha, "\n")] = '\0';             //Remove o \n
            strcpy(DadosDasSondas[i], Linha);               //Copia aquela linha para o vetor de dados
        }
        else if (!strcmp(Linha, "I"))
        {
            for (int j = 0; j < i; j++)
            {
                printf("%s\n", DadosDasSondas[j]);          //Aqui ele imprime os status
            }
        }
        else {
            /*
            Operação E: primeiramente, todas as sondas devem ser movidas para o ponto comum
            de coordenadas (0,0). Em seguida, realiza-se uma redistribuição das rochas entre as
            sondas, para equilibrar o peso total de amostras em cada uma, tentando deixar a
            distribuição de peso entre as sondas o mais igual possível. Isso garante uma divisão
            uniforme das amostras e facilitará o transporte das sondas. Esta operação só será
            executada uma única vez ao fim do arquivo e será seguida de uma operação I
            */
        }
        
        printf("%s\n", DadosDasSondas[i]);
    }
    
    
    
    for (int i = 0; i < N_Sondas; i++) {
        free(Sondas[i]);
    }
    for (int i = 0; i < Operacoes; i++) {
        free(DadosDasSondas[i]);
    }
    fclose(ArquivoDeEntrada);
}
