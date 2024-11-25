#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "SistemadeControle.h"
#define MAX_SIZE 1000


void Inicializacao(){ // inicializa a opçao manual
    ListaSondas Frotadesonda;
    InicializaListaSondas(&Frotadesonda);
    Localizacao local;   
    int numerosondas;
    float capacidade, velocidade, combustivel;
    printf("===========================================================================\n");
    printf("Numero de sondas da lista: ");
    scanf("%d",&numerosondas);
    printf("===========================================================================\n");
    for (int i = 1; i <= numerosondas; i++){//Recebe as informacoes das sondas e colocam na lista de sondas Frotadesonda
        Sonda Venus;
        InicializarSonda(&Venus);
        printf("Digite a Informacao da sonda numero %d\n",i);
        printf("Latitude / Longitude / CapacidadeMaxima / Velocidade / Combustivel\n");
        scanf("%f %f %f %f %f",&local.Latitude,&local.Longitude,&capacidade,&velocidade, &combustivel);
        ModificarValoresSonda(&Venus, local, capacidade, velocidade, combustivel);
        Venus.IdentificadorSonda++;
        LigarSonda(&Venus);
        InserirListaSondas(&Frotadesonda,&Venus);
        printf("Sonda lancada com o indentificador: %d\n",Venus.IdentificadorSonda);
        printf("---------------------------------------------------------------------------\n");
    }
    SelecaoDeModos(&Frotadesonda);
}
/*----------------------------------------------------------------------------------------------------*/
void ColetaDeNovaRocha(ListaSondas *FrotadeSondas){
    printf("Entrou na funcao Coleta De Nova Rocha\n");        
    printf("---------------------------------------------------------------------------\n");
    RochaMineral NovaRocha;
    float peso;
    Mineral mine;
    ListaMineral Pacotemineral;
    Localizacao Local;
    int BH,ID;
    CelulaSonda *SondaMaisProxima;
    InicializaListaMineral(&Pacotemineral);
    printf("Digite as informacoes da  rocha:\n");// Recebe as informaçoes da rocha
    printf("Latitude / Longitude / Peso / Minerais\n");
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
    
    InicializaRochaMineral(&NovaRocha,peso,Pacotemineral,Local); // cria a rocha com as informaçoes recebidas
    ClassificaCategoria(&NovaRocha, BH); // classifca a categoira da rocha 
    ID = ProcurasIDSondaMaisproxima(FrotadeSondas,&NovaRocha); // Procura o identificador da sonda mais proxima a rocha
    if(ID > 0){// Insere a rocha na sonda de acordo com o identificador recebido
        CelulaSonda *ContSonda;
        ContSonda = FrotadeSondas->Primeiro->prox;
        while (ContSonda != NULL){
            if (ContSonda->sonda.IdentificadorSonda == ID){
                MoverSonda(&ContSonda->sonda,NovaRocha._Localizacao.Latitude,NovaRocha._Localizacao.Longitude);
                InserirRocha(&ContSonda->sonda.CompartimentoSonda,&NovaRocha,ContSonda->sonda.CapacidadeMaximaSonda);
            }
            ContSonda = ContSonda->prox;
        }
    }
    else{
        printf("Nenhum sonda disponivel para receber a rocha\n");
    }
    printf("===========================================================================\n");
}
double CalcularDistancia(Sonda venus,RochaMineral Rocha){// Calcula a distancia de uma sonda ate uma rocha
    double DeltaLat = venus.LocalizacaoSonda.Latitude - Rocha._Localizacao.Latitude;
    double DeltaLon = venus.LocalizacaoSonda.Longitude - Rocha._Localizacao.Longitude;
    double x;
    x = sqrt(DeltaLat*DeltaLat + DeltaLon*DeltaLon);
    return x;
}
int ProcurasIDSondaMaisproxima(ListaSondas *FrotadeSondas,RochaMineral *Rocha){// Retorna o Identificador da sonda que é possivel inserir a rocha e é a mais proxima
    int tamanholista = 0, ID = 0;
    CelulaSonda *ContSonda;
    ContSonda = FrotadeSondas->Primeiro->prox;
    double Menordistancia = INFINITY; 
    while (ContSonda != NULL){//Verifica quantas sondas podem recerber a rocha
        tamanholista += VerificasePodeInserirRocha(&ContSonda->sonda.CompartimentoSonda,Rocha,ContSonda->sonda.CapacidadeMaximaSonda,1);
        ContSonda = ContSonda->prox;
    }
    if (tamanholista > 0){
        int ListaIDSSonda[tamanholista], pos = 0;
        ////////
        ContSonda = FrotadeSondas->Primeiro->prox;
        while (pos < tamanholista){//Pecorre a lista de sondas guardando os ids que podem receber a rocha em um vetor 
            switch (VerificasePodeInserirRocha(&ContSonda->sonda.CompartimentoSonda,Rocha,ContSonda->sonda.CapacidadeMaximaSonda,0)){    
                case 0:// caso o peso nao permita a inserção 
                    break;
                case 1:
                    ListaIDSSonda[pos] = ContSonda->sonda.IdentificadorSonda;// caso o compartimento esteja vazio ou nao tenha nehuma rocha da mesma categoria da inserida
                    pos++;
                    break;
                case 2:
                    ListaIDSSonda[pos] = ContSonda->sonda.IdentificadorSonda;// caso o peso da rocha inserida seja menor que a da rocha que ja esta dentro do compartimento
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
                    if (CalcularDistancia(ContSonda->sonda,*Rocha) < Menordistancia){// caso ache uma distancia menor que anterior quando esse valor e o id dessa sonda
                        Menordistancia = CalcularDistancia(ContSonda->sonda,*Rocha);
                        ID = ContSonda->sonda.IdentificadorSonda;    
                    }
                    break;
                }            
            }
            ContSonda = ContSonda->prox;
        }
    }
    else{
        ID = 0;
    }
    return ID;
}
/*----------------------------------------------------------------------------------------------------*/
void ImprimeStatusSondasADMIN(ListaSondas *Frotadesondas){
    printf("Funcao Imprime Status Sondas chamada\n");
    CelulaSonda* aux;
    aux = Frotadesondas->Primeiro->prox;
    int nsonda = 1;
    while(aux){ // Pecorre a lista de sonda 
        printf("---------------------------------------------------------------------------\n");
        printf("%d\n",nsonda); // imprime o numero da sonda
        if(VerificaSeVazia(&aux->sonda.CompartimentoSonda) == 0){
            ImprimeCategoriaPeso(&aux->sonda.CompartimentoSonda); // imprime a categora da rocha e o peso
        }
        else{
            printf("-Compartimento Vazio\n"); // Caso o compatimento estja vazio
        }
        nsonda++;
        aux = aux->prox;
    }
    printf("===========================================================================\n");
}
/*----------------------------------------------------------------------------------------------------*/
void RedistribuicaoDeRochas(ListaSondas *Frotadesondas){
    printf("Funcao Redistribuicao De Rochas chamada\n");
    RetornaBase(Frotadesondas); // Faz que todas as sondas serem movidas a coodernada (0,0)
    double media;
    int RochasRetiradas = 0,aux = 0;
    CelulaSonda *Auxsonda;
    Auxsonda = Frotadesondas->Primeiro->prox;
    Compartimento *CompartimentoAux;        
    ////////////////// CALCULA A MEDIA
    media = RetornaMediadePesoFrota(Frotadesondas);
    int SondaAcima = 0,possicao = 0;
    Auxsonda = Frotadesondas->Primeiro->prox;
    while (Auxsonda != NULL){// Procura Quantas sonda estao acima da media
        if (PesoAtualCompartimento(&Auxsonda->sonda.CompartimentoSonda) > media){
            SondaAcima ++;
        }
        Auxsonda = Auxsonda->prox;
    }
    //////////////////// PROCURA SONDA ACIMA DA MEDIA
    if (SondaAcima > 0){// Caso tenha sonda acima da media Tem oq redistribuir
        int ListaDeIDS[SondaAcima];
        Auxsonda = Frotadesondas->Primeiro->prox;
        while (Auxsonda != NULL){// Procura quais sao os ids e guarda no vetor LISTADEIDS
            if (PesoAtualCompartimento(&Auxsonda->sonda.CompartimentoSonda) > media){
                ListaDeIDS[possicao] = Auxsonda->sonda.IdentificadorSonda;
                possicao ++;
            }
            Auxsonda = Auxsonda->prox;
        }     
    ///////////////////////// RETIRA AS ROCHAS DA SONDAS
    RochasRetiradas = RetornaQuantidadeDeRochasFrota(Frotadesondas);
    RochaMineral VetorRochas[RochasRetiradas];
    Auxsonda = Frotadesondas->Primeiro->prox;
    while (Auxsonda != NULL){
        CompartimentoAux = Auxsonda->sonda.CompartimentoSonda.PrimeiroRocha->Prox;
        while (CompartimentoAux != NULL){
            RochaMineral Rocharetirada;
            RemoverRochaPorCategoria(&Auxsonda->sonda.CompartimentoSonda,&Rocharetirada,CompartimentoAux->_RochaMineral._Categorias);
            VetorRochas[aux] = Rocharetirada;
            aux++;
            CompartimentoAux = CompartimentoAux->Prox; 
        }
        Auxsonda = Auxsonda->prox;        
    }
    //////////// GUARDA AS ROCHAS RETIRADAS NAS SONDA NOVAMENTE
    int Inter = 0,RochasRetiradasaux = RochasRetiradas;
    aux = 0;
    Auxsonda = Frotadesondas->Primeiro->prox;
    while (aux < RochasRetiradas){
        if (RetornaQuantasSonda(Frotadesondas) < RochasRetiradas && Inter == 0){
            if (Auxsonda == NULL){
                Auxsonda = Frotadesondas->Primeiro->prox;
            }
            switch (VerificasePodeInserirRocha(&Auxsonda->sonda.CompartimentoSonda,&VetorRochas[aux],media,0)){
            case 0:
                Inter = 1;
                break;
            case 1:
                InserirRocha(&Auxsonda->sonda.CompartimentoSonda,&VetorRochas[aux],media);
                aux++;
                RochasRetiradasaux--;
                Auxsonda = Auxsonda->prox;
                break;
            case 2:
                InserirRocha(&Auxsonda->sonda.CompartimentoSonda,&VetorRochas[aux],media);
                aux++;
                RochasRetiradasaux--;    
                Auxsonda = Auxsonda->prox;
                break;
            }            
        }
        else{
            InserirRochaMedia(&Auxsonda->sonda.CompartimentoSonda,&VetorRochas[aux]);
            aux++;
            RochasRetiradasaux--;
            Auxsonda = Auxsonda->prox;
            Inter = 0;        
        }
    }
    /////////////////
    }
    else{
        printf("Nao e necessario redistribuir, nenhuma sonda ultrapaca a media\n");
    }
    printf("===========================================================================\n");
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
int RetornaQuantasSonda(ListaSondas *Frotadesondas){// quantas sondas tem na lista 
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
/*----------------------------------------------------------------------------------------------------*/
void SelecaoDeModos(ListaSondas *FrotadeSondas) {
    int numerooperacoes;
    char operacaoescolhida;
    printf("===========================================================================\n");
    printf("Numero de operacoes: "); // recebe quantas operaçoes vai ser realizada
    scanf("%d", &numerooperacoes);
    printf("===========================================================================\n");
    while (getchar() != '\n'); 

    for (int i = 0; i < numerooperacoes; i++){// Recebe a operacao escolhida 
        printf("Escolha a operacao: ");
        scanf(" %c", &operacaoescolhida);
        printf("===========================================================================\n");
        if (operacaoescolhida == 'R') {
            ColetaDeNovaRocha(FrotadeSondas);
        } else if (operacaoescolhida == 'I') {
            ImprimeStatusSondasADMIN(FrotadeSondas);
        } else if (operacaoescolhida == 'E') {
            RedistribuicaoDeRochas(FrotadeSondas);
        }
    }
}
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
                    printf("porque o comparimento estava vazio\n");
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
                    printf("porque nao avia nenhuma rocha da mesma catgoria\n");
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
        printf("\n============================================================\n");
        printf("Numero da sonda: %d\n",nsonda);
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
        aux = aux->prox;
        printf("\n============================================================\n");
    }
}

void RedistribuicaoDeRochas(ListaSondas *Frotadesondas){
    RetornaBase(Frotadesondas);
    
    
    
}


void RetornaBase(ListaSondas *Frotadesondas){
    CelulaSonda *AuxCont;
    AuxCont = Frotadesondas->Primeiro->prox;
    while(AuxCont != NULL){
        MoverSonda(&AuxCont->sonda,0,0);
        AuxCont = AuxCont->prox;
    }
}

double RetornaMediadePesoFrota(ListaSondas *Frotadesondas){
    double media = 0;
    
    CelulaSonda *AuxCont;
    AuxCont = Frotadesondas->Primeiro->prox;
    while (AuxCont != NULL){
        media = media + PesoAtualCompartimento(Frotadesondas);
        AuxCont = AuxCont->prox;
    }
    printf("media da lista: %f\n",media);
    
    return media;
}

void SelecaoDeModos();

