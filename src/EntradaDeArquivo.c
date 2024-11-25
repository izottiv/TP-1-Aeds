#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ListaSonda/TAD_ListaSonda.h"
#include "ListaSonda/SondaEspacial/TAD_Sonda.h"
#include "ListaSonda/SondaEspacial/Compartimento/TAD_Compartimento.h"
#include "ListaSonda/SondaEspacial/Compartimento/Rocha_Mineral/TAD_RochaMineral.h"
#include "ListaSonda/SondaEspacial/Compartimento/Rocha_Mineral/Lista_Minerais/TAD_ListaMineral.h"
#include "ListaSonda/SondaEspacial/Compartimento/Rocha_Mineral/Lista_Minerais/Mineral/TAD_Mineral.h"


#define TamanhoMax 100

//Esta função serve para além de ler o link, manter organizado o main.c e com uma quantidade menor de elementos, tornando a visualização mais fácil
void EntradaDeArquivo(char* Link){

    FILE *ArquivoDeEntrada = fopen(Link, "r");

    //Precisarei salvar as LINHAS dos arquivos, quantas SONDAS e QUAIS são
    char Linha[TamanhoMax];
    int N_Sondas, Operacoes;

    

    //Recebe a quantidade de SONDAS da primeira linha
    fgets(Linha, sizeof(Linha), ArquivoDeEntrada);
    N_Sondas = atoi(Linha);
    printf("%d\n",N_Sondas);    //      Vai Apagar Dps/////////////

    ListaSondas *_ListaSondas;
    _ListaSondas = malloc(N_Sondas*sizeof(CelulaSonda));

    InicializaListaSondas(_ListaSondas);

    //Salva todas as SONDAS em seu vetor
    for (int i = 0; i < N_Sondas; i++)
    {
        fgets(Linha, sizeof(Linha), ArquivoDeEntrada);  //Recebe as X sondas
        float Latitude = atof(strtok(Linha, " "));
        float Longitude = atof(strtok(NULL, " "));
        float Capacidade = atof(strtok(NULL, " "));
        float Velocidade = atof(strtok(NULL, " "));
        float Combustivel = atof(strtok(NULL, " "));
        
        Sonda _Sonda;
        InicializarSonda( &_Sonda);
        MoverSonda(&_Sonda, Latitude, Longitude);
        EditarValores(&_Sonda, Capacidade, Velocidade, Combustivel);
        InserirListaSondas(_ListaSondas, &_Sonda);
    }

    printf("\n");

    fgets(Linha, sizeof(Linha), ArquivoDeEntrada);      //Recebe as M operações
    Operacoes = atoi(Linha);
    

    for (int i = 0; i < Operacoes; i++)
    {
        fgets(Linha, sizeof(Linha), ArquivoDeEntrada);  //Recebe primeira operacao
        Linha[strcspn(Linha, "\n")] = '\0';             /*Sempre que eu tento manipular uma linha com o \n ele da erro, então com esta função eu sou capaz de trocar a sua ocorrencia por um nulo, eliminando as quebras de linha daquela linha salva */
        printf("OPERACAO: %s\n", Linha);

        //Condicionais para fazer as OPERAÇÕES
        if(!strcmp(Linha, "R")){
            fgets(Linha, sizeof(Linha), ArquivoDeEntrada);  //Recebe a linha
            printf("%s", Linha);

            float latitude = atof(strtok(Linha, " "));
            float longitude = atof(strtok(NULL, " "));

            float peso = atof(strtok(NULL, " "));

            Localizacao _localizacao;
            _localizacao.Latitude = latitude;
            _localizacao.Longitude = longitude;

            ListaMineral _listamineral;
            InicializaListaMineral(&_listamineral);          

            for(int i =0;i < 3; i++){
                char* mineral = strtok(NULL, " ");
                Mineral _mineral;
                if (mineral == NULL)
                {
                    InsereListaMineral(&_listamineral, _mineral);
                }
                else {
                    InicializaMineral(&_mineral, mineral);
                    InsereListaMineral(&_listamineral, _mineral);
                }
                
            }
        }
        else if (!strcmp(Linha, "I"))
        {

            
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
        
    }
   
    fclose(ArquivoDeEntrada);
}
