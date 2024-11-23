#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "SistemadeControle.h"
#define MAX_SIZE 1000


void Inicializacao(){
    ListaSondas Frotadesonda;
    InicializaListaSondas(&Frotadesonda);
    Localizacao local;
    int numerosondas;
    float capacidade, velocidade, combustivel;
    printf("===========================================================================\n");
    printf("Numero de sondas da lista: ");
    scanf("%d",&numerosondas);
    for (int i = 0; i < numerosondas; i++){
        Sonda Venus;
        InicializarSonda(&Venus);
        //printf("Coordenadas/Armazenamento/velocidade/combustivel:");//APAGARDEPOIS
        printf("Digite as coordenadas da sonda (Latitude/Longitude):\n");
        scanf("%f %f",&local.Latitude, &local.Longitude);
        printf("Digite a capacidade maxima da sonda:\n");
        scanf("%f",&capacidade);
        //printf("Digite a velocidade e quantidade de combustivel");
        //scanf("%f %f",&velocidade, &combustivel);
        velocidade = 66;
        combustivel = 10;
        ModificarValoresSonda(&Venus, local, capacidade, velocidade, combustivel);
        Venus.IdentificadorSonda++;
        LigarSonda(&Venus);
        InserirListaSondas(&Frotadesonda,&Venus);
        printf("indentificador da sonda: %d\n",Venus.IdentificadorSonda);
        printf("---------------------------------------------------------------------------\n");
    
    }
    SelecaoDeModos(&Frotadesonda);
}

void ColetaDeNovaRocha(ListaSondas *FrotadeSondas){
    RochaMineral NovaRocha;
    float peso;
    Mineral mine;
    ListaMineral Pacotemineral;
    Localizacao Local;
    int BH,ID;
    CelulaSonda *SondaMaisProxima;
    InicializaListaMineral(&Pacotemineral);
    printf("---------------------------------------------------------------------------\n");
    printf("Coordenadas/Peso/minerais: ");
    scanf("%f %f %f ",&Local.Latitude,&Local.Longitude,&peso);
    char restante[100]; // Buffer para ler os nomes
    fgets(restante, sizeof(restante), stdin);  // Lê a linha com os nomes

    // Divide os nomes usando strtok
    char *nome1 = strtok(restante, " \n");
    char *nome2 = strtok(NULL, " \n");
    char *nome3 = strtok(NULL, " \n");

    // Verifica se todos os três nomes foram encontrados
    if (nome1 && nome2 && nome3 != NULL) {
        InicializaMineral(&mine,nome1);
        InsereListaMineral(&Pacotemineral,mine);
        InicializaMineral(&mine,nome2);
        InsereListaMineral(&Pacotemineral,mine);
        InicializaMineral(&mine,nome3);
        InsereListaMineral(&Pacotemineral,mine);
        BH = 3;
    }
    // Verifica se apenas dois nomes foram encontrados
    else if (nome1 && nome2 != NULL) {
        InicializaMineral(&mine,nome1);
        InsereListaMineral(&Pacotemineral,mine);
        InicializaMineral(&mine,nome2);
        InsereListaMineral(&Pacotemineral,mine);
        BH = 2;
    }
    // verifica se apenas um nome foi dado
    else if (nome1 != NULL){
        InicializaMineral(&mine,nome1);
        InsereListaMineral(&Pacotemineral,mine);
        BH = 1;           
    }
    
    InicializaRochaMineral(&NovaRocha,peso,Pacotemineral,Local);
    ClassificaCategoria(&NovaRocha, BH);
    ID = ProcurasIDSondaMaisproxima(FrotadeSondas,&NovaRocha);
    printf("ID da sonda onde a rocha foi inserida: %d\n",ID);//Tal vez Tirar
    
    CelulaSonda *ContSonda;
    ContSonda = FrotadeSondas->Primeiro->prox;
    while (ContSonda != NULL){
        if (ContSonda->sonda.IdentificadorSonda == ID){
            MoverSonda(&ContSonda->sonda,NovaRocha._Localizacao.Latitude,NovaRocha._Localizacao.Longitude);
            InserirRocha(&ContSonda->sonda.CompartimentoSonda,&NovaRocha,ContSonda->sonda.CapacidadeMaximaSonda);
            break;
        }
        ContSonda = ContSonda->prox;
    }
}
double CalcularDistancia(Sonda venus,RochaMineral Rocha){
    double DeltaLat = venus.LocalizacaoSonda.Latitude - Rocha._Localizacao.Latitude;
    double DeltaLon = venus.LocalizacaoSonda.Longitude - Rocha._Localizacao.Longitude;
    double x;
    x = sqrt(DeltaLat*DeltaLat + DeltaLon*DeltaLon);
    return x;
}
int ProcurasIDSondaMaisproxima(ListaSondas *FrotadeSondas,RochaMineral *Rocha){// Retorna o Identificador da sonda que é possivel inserir a rocha e é a mais proxima
    int tamanholista = 0, ID;
    CelulaSonda *ContSonda;
    ContSonda = FrotadeSondas->Primeiro->prox;
    double Menordistancia = CalcularDistancia(ContSonda->sonda,*Rocha);
    ID = ContSonda->sonda.IdentificadorSonda; 
    while (ContSonda != NULL){//Verifica o quantas sondas podem recerber a rocha
        tamanholista += VerificasePodeInserirRocha(&ContSonda->sonda.CompartimentoSonda,Rocha,ContSonda->sonda.CapacidadeMaximaSonda,1);
        ContSonda = ContSonda->prox;
    }
    int ListaIDSSonda[tamanholista], pos = 0;
    ////////////
    ContSonda = FrotadeSondas->Primeiro->prox;
    while (pos < tamanholista){//Pecorre a lista de sondas Guardando os ids que podem receber a rocha emm um vetor 
        switch (VerificasePodeInserirRocha(&ContSonda->sonda.CompartimentoSonda,Rocha,ContSonda->sonda.CapacidadeMaximaSonda,0)){
        case 0:// caso o peso nao permita a insercao 
            break;
        case 1:
            ListaIDSSonda[pos] = ContSonda->sonda.IdentificadorSonda;// caso o compartimento esteja vazio ou nao tenha nehuma rocha da mesma categoria da inserida
            pos++;
            break;
        case 2:
            ListaIDSSonda[pos] = ContSonda->sonda.IdentificadorSonda;// caso o peso da rocha enserida é menor que a da rocha ja dentro do compartimento
            pos++;
            break;
        }
        ContSonda = ContSonda->prox;
    }
    /////////////////
    ContSonda = FrotadeSondas->Primeiro->prox;
    while (ContSonda != NULL){//pecorre a lista comparando com os ids salvos e verificando qual deles tem a menor distancia
        for(int i = 0; i < tamanholista; i++){// compara o id de uma sonda com todos os ids do vetor
            if (ContSonda->sonda.IdentificadorSonda == ListaIDSSonda[i]){
                if (CalcularDistancia(ContSonda->sonda,*Rocha) < Menordistancia){// caso achae uma distancia menor que anterior quando esse valor e o id dessa sonda
                    Menordistancia = CalcularDistancia(ContSonda->sonda,*Rocha);
                    ID = ContSonda->sonda.IdentificadorSonda;    
                }
            break;
            }            
        }
        ContSonda = ContSonda->prox;
    }
    return ID;
}

void ImpressaoSondas(ListaSondas *FrotaSonda){
    printf("Quantas rochas na sonda %d\n",RetornaQuantidadeDeRochasFrota(FrotaSonda));
    int numero = 1;
    CelulaSonda *Venus;
    Venus = FrotaSonda->Primeiro->prox;
    for(int i = 1;i <= RetornaQuantasSonda(FrotaSonda);i++){
        printf("---------------------------------------------------------------------------\n");
        printf("%d\n",numero);
        printf("Indentificador: %d\n",Venus->sonda.IdentificadorSonda);
        ImprimeConteudoCompartimento(&Venus->sonda.CompartimentoSonda);
        numero ++;
        Venus = Venus->prox;
    }
    printf("---------------------------------------------------------------------------\n");  
}

void RetornaBase(ListaSondas *Frotadesondas){// Faz todas as sonda retornar para coordenadas 0,0
    CelulaSonda *AuxCont;
    AuxCont = Frotadesondas->Primeiro->prox;
    while(AuxCont != NULL){
        MoverSonda(&AuxCont->sonda,0,0);
        AuxCont = AuxCont->prox;
    }
}
double RetornaMediadePesoFrota(ListaSondas *Frotadesondas){// Retorna a media de peso de todas as sondas em uma lista
    double media = 0;
    CelulaSonda *AuxCont;
    AuxCont = Frotadesondas->Primeiro->prox;
    while (AuxCont != NULL){
        media = media + PesoAtualCompartimento(&AuxCont->sonda.CompartimentoSonda);
        AuxCont = AuxCont->prox;
    }
    media = media/RetornaQuantasSonda(Frotadesondas);
    return media;
}
int RetornaQuantasSonda(ListaSondas *Frotadesondas){// quantas sondas tem na frita
    int quantidade = 0;
    CelulaSonda *AuxCont;
    AuxCont = Frotadesondas->Primeiro->prox;
    while (AuxCont != NULL){
        quantidade++;
        AuxCont = AuxCont->prox;
    }
    return quantidade;
}
int RetornaQuantidadeDeRochasFrota(ListaSondas *Frotadesondas){//Retorna a quantidade de rochas da frota inteira
    int quantidaderocha = 0;
    CelulaSonda *AuxCont;
    AuxCont = Frotadesondas->Primeiro->prox;
    while (AuxCont != NULL){
        quantidaderocha = quantidaderocha + QuantasRochasEmCompartimento(&AuxCont->sonda.CompartimentoSonda);
        AuxCont = AuxCont->prox;
    }
    return quantidaderocha;
}


void SelecaoDeModos(ListaSondas *FrotadeSondas) {
    int numerooperacoes;
    char operacaoescolhida;
    printf("===========================================================================\n");
    printf("Numero de operacoes: ");
    scanf("%d", &numerooperacoes);
    while (getchar() != '\n'); 

    for (int i = 0; i < numerooperacoes; i++) {
        printf("Escolha a operacao: ");
        scanf(" %c", &operacaoescolhida);

        if (operacaoescolhida == 'R') {
            printf("Entrou na funcao Coleta De Nova Rocha\n");
            ColetaDeNovaRocha(FrotadeSondas);
        } else if (operacaoescolhida == 'I') {
            printf("Funcao Imprime Status Sondas chamada\n");
            ImpressaoSondas(FrotadeSondas);// trocar para outra funcao de imprimir
        } else if (operacaoescolhida == 'E') {
            printf("Função Redistribuicao De Rochas chamada\n");
        }
    }
}