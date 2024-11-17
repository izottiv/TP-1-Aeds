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
    char Linha[TamanhoMax], *DadosDasSondas[TamanhoMax];
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
            Linha[strcspn(Linha, "\n")] = '\0';    
            
            //meu bglh
            char* token = strtok(Linha, " ");
            float latitude = atof(token);
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
                InicializaMineral(&_mineral, mineral);
                InsereListaMineral(&_listamineral, _mineral);
                
            }
            ImprimeListaMineral(&_listamineral);
            printf("Localização: %.2f, %.2f | Peso: %d\n", latitude, longitude, peso);
            printf("Minerais adicionados com sucesso à lista.\n");
            /*Localizacao _Localizacao;
            float v1 = atof((Linha, " "));
            printf("%f", v1);*/
            // int Peso = atoi(strtok(NULL, " "));
            // printf("%d", Peso);

            // ListaMineral lisM;
            // Mineral m1, m2, m3;
            // char Mineral1[50], Mineral2[50], Mineral3[50];
            // strcpy(Mineral1, strtok(NULL, " "));
            // strcpy(Mineral2, strtok(NULL, " "));
            // strcpy(Mineral3, strtok(NULL, " "));
            
            // InicializaMineral(&m1, Mineral1);
            // InicializaMineral(&m2, Mineral2);
            // InicializaMineral(&m3, Mineral3);
            // InsereListaMineral(&lisM, m1);
            // InsereListaMineral(&lisM, m2);
            // InsereListaMineral(&lisM, m3);

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
    
    for (int i = 0; i < Operacoes; i++) {
        free(DadosDasSondas[i]);
    }
    fclose(ArquivoDeEntrada);
}
