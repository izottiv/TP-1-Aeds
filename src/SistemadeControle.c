#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "SistemadeControle.h"


ListaSondas Inicializacao(){
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
    return Frotadesonda;
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

    SondaMaisProxima = Procurasondamaisproxima(FrotadeSondas, &NovaRocha);
    MoverSonda(&SondaMaisProxima->sonda,NovaRocha._Localizacao.Latitude,NovaRocha._Localizacao.Longitude);
    InserirRocha(&SondaMaisProxima->sonda.CompartimentoSonda,&NovaRocha,SondaMaisProxima->sonda.CapacidadeMaximaSonda);
    printf("SE pa deu bom\n");
}

double CalcularDistancia(Sonda venus,RochaMineral Rocha){
    double DeltaLat = venus.LocalizacaoSonda.Latitude - Rocha._Localizacao.Latitude;
    double DeltaLon = venus.LocalizacaoSonda.Longitude - Rocha._Localizacao.Longitude;
    double x;
    x = sqrt(DeltaLat*DeltaLat + DeltaLon*DeltaLon);
    return x;
}

CelulaSonda *Procurasondamaisproxima(ListaSondas *FrotadeSondas,RochaMineral *Rocha){
    double MenorDistancia;
    int identificador;
    MenorDistancia = CalcularDistancia(FrotadeSondas->Primeiro->prox->sonda, *Rocha);
    CelulaSonda *Auxcont;
    Auxcont = FrotadeSondas->Primeiro->prox;
    while (Auxcont != NULL){// pecorre a lista procurando a sonda perfeita
        if(VerificasePodeInserirRocha(&Auxcont->sonda.CompartimentoSonda,Rocha,Auxcont->sonda.CapacidadeMaximaSonda) == 0){ // Verifica se a sonda tem espaco sobrando se sim faz o negocio ai
            if(CalcularDistancia(Auxcont->sonda,*Rocha) < MenorDistancia){// guarda o indentificador da mais proxima
                MenorDistancia = CalcularDistancia(Auxcont->sonda,*Rocha);
                identificador = Auxcont->sonda.IdentificadorSonda;
            }
            Auxcont= Auxcont->prox;
        }
    }
    Auxcont = FrotadeSondas->Primeiro->prox;
    while (Auxcont != NULL){// procura o indentificador da sonda mais proxima e returna o valor na memoria dela
        if(identificador == Auxcont->sonda.IdentificadorSonda){
            printf("Achou a sonda mais proxima\n");
            return Auxcont; 
        }
        Auxcont= Auxcont->prox;
    }
    
}

void ImprimeStatusSondas();
void RedistribuicaoDeRochas();
void SelecaoDeModos(ListaSondas *FrotadeSondas) {
    int numerooperacoes;
    char operacaoescolhida;

    printf("Número de operacoes: ");
    scanf("%d", &numerooperacoes);
    while (getchar() != '\n'); 

    for (int i = 0; i < numerooperacoes; i++) {
        printf("Escolha a operacao: ");
        scanf(" %c", &operacaoescolhida);

        if (operacaoescolhida == 'R') {

            ColetaDeNovaRocha(FrotadeSondas);
            printf("Entrou na função ColetaDeNovaRocha\n");

        } else if (operacaoescolhida == 'I') {
            printf("Função ImprimeStatusSondas chamada\n");
            
        } else if (operacaoescolhida == 'E') {
            printf("Função RedistribuicaoDeRochas chamada\n");
        }
    }
}