#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "SistemadeControle.h"


void Inicializacao(){
    ListaSondas Frotadesonda;
    InicializaListaSondas(&Frotadesonda);
    Sonda Venus;
    InicializarSonda(&Venus);
    int numerosondas;
    printf("Numero de sondas da lista: ");//apagar depois
    scanf("%d",&numerosondas);
    for (int i = 0; i < numerosondas; i++){
        printf("Coordenadas/Armazenamento/velocidade/combustivel: ");//APAGARDEPOIS
        scanf("%f %f %f %f %f",&Venus.LocalizacaoSonda.Latitude,&Venus.LocalizacaoSonda.Longitude,&Venus.CapacidadeMaximaSonda,&Venus.VelocidadeSonda,&Venus.NivelIncialCombustivel);
        Venus.IdentificadorSonda++;
        LigarSonda(&Venus);
        InserirListaSondas(&Frotadesonda,&Venus);
    }
    ColetaDeNovaRocha(&Frotadesonda);
    ColetaDeNovaRocha(&Frotadesonda);
    ColetaDeNovaRocha(&Frotadesonda);
    ImprimeStatusSondas(&Frotadesonda);
}

void ColetaDeNovaRocha(ListaSondas *FrotadeSondas){
    RochaMineral NovaRocha;
    float peso;
    Mineral mine;
    ListaMineral Pacotemineral;
    Localizacao Local;
    int BH;
    CelulaSonda *SondaMaisProxima;
    InicializaListaMineral(&Pacotemineral);
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
    ProcurasIDSondaMaisproxima(FrotadeSondas,&NovaRocha);
}

double CalcularDistancia(Sonda venus,RochaMineral Rocha){
    double DeltaLat = venus.LocalizacaoSonda.Latitude - Rocha._Localizacao.Latitude;
    double DeltaLon = venus.LocalizacaoSonda.Longitude - Rocha._Localizacao.Longitude;
    double x;
    x = sqrt(DeltaLat*DeltaLat + DeltaLon*DeltaLon);
    return x;
}

int ProcurasIDSondaMaisproxima(ListaSondas *FrotadeSondas,RochaMineral *Rocha){
    double MenorDistancia;
    int tamanho = 0;
    MenorDistancia  = CalcularDistancia(FrotadeSondas->Primeiro->prox->sonda,*Rocha) + 1;
    CelulaSonda *AuxCont;
    AuxCont = FrotadeSondas->Primeiro->prox;
    while (AuxCont != NULL){//procura quantas sondas podem receber a rocha
        switch (VerificasePodeInserirRocha(&AuxCont->sonda.CompartimentoSonda,Rocha,AuxCont->sonda.CapacidadeMaximaSonda)){
        case 0:
            tamanho ++;
            break;
        case 1:
            tamanho++;
            break;
        case 2:
            tamanho++;
            break;
        default:
            break;
        }
        AuxCont = AuxCont->prox;
    }
    int listadeVetores[tamanho];
    int numero = 0;
    AuxCont = FrotadeSondas->Primeiro->prox;
    while (AuxCont != NULL){ // guarda os ids das sondas e guarda  em um vetor
        switch (VerificasePodeInserirRocha(&AuxCont->sonda.CompartimentoSonda,Rocha,AuxCont->sonda.CapacidadeMaximaSonda)){
        case 0:
            listadeVetores[numero] = AuxCont->sonda.IdentificadorSonda;
            break;
        case 1:
            listadeVetores[numero] = AuxCont->sonda.IdentificadorSonda;
            break;
        case 2:
            listadeVetores[numero] = AuxCont->sonda.IdentificadorSonda;
            break;
        default:
            break;
        }
        numero ++; 
        AuxCont = AuxCont->prox;        
    }
    for (int i = 0; i < tamanho; i++){
        printf("Ids disponieveis para aceitar rocha %d\n",listadeVetores[i]);
    }
    AuxCont = FrotadeSondas->Primeiro->prox;
    int idprox;
    while (AuxCont != NULL){//procura a sonda mais proxima da rocha
        for(int x = 0;x < tamanho;x++){
            if (AuxCont->sonda.IdentificadorSonda == listadeVetores[x]){
                if(CalcularDistancia(AuxCont->sonda,*Rocha) < MenorDistancia){
                    MenorDistancia = CalcularDistancia(AuxCont->sonda,*Rocha);
                    idprox = AuxCont->sonda.IdentificadorSonda;
                }
            }
        }
        AuxCont = AuxCont->prox;
    }
    AuxCont = FrotadeSondas->Primeiro->prox;
    while (AuxCont != NULL){
        if(AuxCont->sonda.IdentificadorSonda == idprox){
            switch(VerificasePodeInserirRocha(&AuxCont->sonda.CompartimentoSonda,Rocha,AuxCont->sonda.CapacidadeMaximaSonda)){// olha qual caso a insercao vai acontecer
                case 0: // caso o compartimento esteja vazia retorna zero onde vc precisa enserir a rocha
                    MoverSonda(&AuxCont->sonda,Rocha->_Localizacao.Latitude,Rocha->_Localizacao.Longitude);
                    InserirRocha(&AuxCont->sonda.CompartimentoSonda,Rocha,AuxCont->sonda.CapacidadeMaximaSonda);
                    printf("Rocha enserida na sonda: %d ",AuxCont->sonda.IdentificadorSonda);
                    printf("porque o compartimento estava vazio\n");
                    break;
                case 1:// caso retorn 1 a tem o mesmo tipo de rocha e esta no meio e troca rocha
                    MoverSonda(&AuxCont->sonda,Rocha->_Localizacao.Latitude,Rocha->_Localizacao.Longitude);
                    TrocaRocha(&AuxCont->sonda.CompartimentoSonda,Rocha);
                    printf("Rocha enserida na sonda: %d ",AuxCont->sonda.IdentificadorSonda);
                    printf("porque a rocha estava no meio da lista");
                    break;
                case 2:// caso a lista nao esteja vazia e nao tenha uma rocha de categoria iqual a recebida coloca a recebida na ultima possicao retorna 2
                    MoverSonda(&AuxCont->sonda,Rocha->_Localizacao.Latitude,Rocha->_Localizacao.Longitude);
                    InserirRocha(&AuxCont->sonda.CompartimentoSonda,Rocha,AuxCont->sonda.CapacidadeMaximaSonda);
                    printf("Rocha enserida na sonda: %d ",AuxCont->sonda.IdentificadorSonda);
                    printf("porque nao havia nenhuma rocha da mesma catgoria\n");
                    break;
            }
            break;
        }
        AuxCont = AuxCont->prox;
    }
}

void ImprimeStatusSondas(ListaSondas *Frotadesondas){
    CelulaSonda* aux;
    aux = Frotadesondas->Primeiro->prox;
    int nsonda = 1;
    while(aux){
        printf("============================================================\n");
        printf("Numero da soda: %d\n",nsonda);
        printf("Identificador: %d\n", aux->sonda.IdentificadorSonda);
        printf("Peso atual do compartimento da sonda: %.1f\n", PesoAtualCompartimento(&aux->sonda.CompartimentoSonda));
        printf("Velocidade da Sonda: %.2f\n", aux->sonda.VelocidadeSonda);
        printf("Nivel de Combustivel: %.2f\n", aux->sonda.NivelIncialCombustivel);
        printf("Localizacao: Latitude = %.6f Longitude = %.6f\n", aux->sonda.LocalizacaoSonda.Latitude,aux->sonda.LocalizacaoSonda.Longitude);
        printf("Esta Ligada: ");
        if(aux->sonda.EstaLigada == 1){
            printf("Sim\n");
        }
        else{
            printf("Nao\n");
        }
        printf("---------------------------------------------\n");
        ImprimeConteudoCompartimento(&aux->sonda.CompartimentoSonda);
        nsonda++;
        aux = aux->prox;
    }
}

void RedistribuicaoDeRochas(ListaSondas *Frotadesondas){
    RetornaBase(Frotadesondas);
    RochaMineral ListaDeRochaDaFrota[RetornaQuantidadeDeRochasFrota(Frotadesondas)];
    CelulaSonda *AuxCont;
    Compartimento *AuxComp;
    int pos = 0;
    AuxCont = Frotadesondas->Primeiro->prox;
    while (pos < RetornaQuantidadeDeRochasFrota(Frotadesondas)){
        AuxComp = AuxCont->sonda.CompartimentoSonda.PrimeiroRocha->Prox;    
        ListaDeRochaDaFrota[pos] = AuxCont->sonda.CompartimentoSonda.PrimeiroRocha->_RochaMineral;    
        while (AuxComp != NULL){
            pos++;
        }
        
        pos++;
        AuxCont = AuxCont->prox;
    }
    
    printf("Ta dando bom\n");
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


void SelecaoDeModos();