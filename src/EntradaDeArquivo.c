#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SistemadeControle.h"
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
    printf("%s", Linha);
    N_Sondas = atoi(Linha);  
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

            Mineral mine;    
            int BH = 0;

            char *nome1  = strtok(NULL, " ");
            char *nome2 = strtok(NULL, " \n");
            char *nome3 = strtok(NULL, " \n");

            // Verifica se todos os três nomes foram encontrados
            if (nome1 && nome2 && nome3 != NULL) {
                InicializaMineral(&mine,nome1);
                InsereListaMineral(&_listamineral,mine);
                InicializaMineral(&mine,nome2);
                InsereListaMineral(&_listamineral,mine);
                InicializaMineral(&mine,nome3);
                InsereListaMineral(&_listamineral,mine);
                BH = 3;
            }
            // Verifica se apenas dois nomes foram encontrados
            else if (nome1 && nome2 != NULL) {
                InicializaMineral(&mine,nome1);
                InsereListaMineral(&_listamineral,mine);
                InicializaMineral(&mine,nome2);
                InsereListaMineral(&_listamineral,mine);
                BH = 2;
            }
            // verifica se apenas um nome foi dado
            else if (nome1 != NULL){
                InicializaMineral(&mine,nome1);
                InsereListaMineral(&_listamineral,mine);
                BH = 1;           
            }
            
            

            RochaMineral Rocha;
            InicializaRochaMineral(&Rocha, peso, _listamineral, _localizacao);
            ClassificaCategoria(&Rocha, BH);
            
            TransformarCategoria(&Rocha);

            int ID = ProcurasIDSondaMaisproxima(_ListaSondas, &Rocha);

            if(ID > 0){// Insere a rocha na sonda de acordo com o identificador recebido
            CelulaSonda *ContSonda;
            ContSonda = _ListaSondas->Primeiro->prox;
            while (ContSonda != NULL){
                if (ContSonda->sonda.IdentificadorSonda == ID){
                    MoverSonda(&ContSonda->sonda,Rocha._Localizacao.Latitude,Rocha._Localizacao.Longitude);
                    InserirRocha(&ContSonda->sonda.CompartimentoSonda,&Rocha,ContSonda->sonda.CapacidadeMaximaSonda);
                }
                ContSonda = ContSonda->prox;
            }
            }
            else{
                printf("Nenhum sonda disponivel para receber a rocha\n");
            }
        }
        else if (!strcmp(Linha, "I"))
        {
            CelulaSonda* aux;
            aux = _ListaSondas->Primeiro->prox;
            int nsonda = 1;
            while(aux){ // Pecorre a lista de sonda 
                printf("%d\n",nsonda); // imprime o numero da sonda
                if(VerificaSeVazia(&aux->sonda.CompartimentoSonda) == 0){              
                    ImprimeCategoriaPeso(&aux->sonda.CompartimentoSonda); // imprime a categora da rocha e o peso
                }
                else{
                    printf("Compartimento Vazio!\n"); // Caso o compatimento estja vazio
                }
                nsonda++;
                aux = aux->prox;
            }
        }
        else {
            RedistribuicaoDeRochas(_ListaSondas);
        }
        
    }
   
    fclose(ArquivoDeEntrada);
}
