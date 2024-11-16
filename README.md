TP AEDS

TAD 1 - TIPO ABSTRATO DE DADOS MINERAL:

STRUCT:
● Nome

● Dureza

● Reatividade

● Cor


tem q ter inicialização, set e get


TAD 2 -  TIPO ABSTRATO DE DADOS LISTA DE MINERAIS(Implementar usando Vetor):

Lista de vetor referente aos minerais

tem q inicializar lista vazia, inserir mineral no final, retirar mineral de certo nome e imprimir todos os componentes

TAD 3 -  TIPO ABSTRATO DE DADOS ROCHA MINERAL:

STRUCT:
 ● Identificador
 
 ● Peso

 ● Lista de minerais

 ● Categoria

 ● Localização (Latitude, Longitude)
 
 ● Data de Coleta

tem que inicializar, obtenção e atribuição de valores, além da
operação de classificação, que preenche o campo Categoria, conforme a lista de minerais
presentes na rocha.

 TAD 4 -  TIPO ABSTRATO DE DADOS COMPARTIMENTO:

 Lista encadeada 

 ● Criar: inicializa a lista vazia;
 
 ● Retornar tamanho, isto é, o número atual de rochas minerais no compartimento;
 
 ● Verificar se está vazia;
 
 ● Exibir: imprime o conteúdo do compartimento, sendo necessário indicar quando a lista
 está vazia;
 
 ● Retornar peso atual do compartimento;
 
 ● Trocar rocha (Adiciona uma rocha mais leve no lugar da rocha mais pesada do mesmo
 tipo)
 
 ● Inserir rocha: armazenar nova Rocha Mineral encontrada na localização dada seguindo
 as regras que indicam que não poderão haver rochas repetidas e de acordo com o peso
 máximo permitido;
 
 ● Remover rocha(Pela categoria);

 TAD 5 - TIPO ABSTRATO DE DADOS SONDA ESPACIAL:

 Este TAD deve representar uma Sonda Espacial a ser enviada para a exploração de Marte.
 Assim, a estrutura deste TAD deve conter os campos descritos abaixo.
 
 ● Identificador
 
 ● Compartimento
 
 ● Localização (Latitude, Longitude)
 
 ● Esta Ligada
 As operações do TAD englobam todas as ações necessárias para fazer a sonda funcionar.
 
 ● Inicializar: inicializa uma nova sonda, sem nenhuma rocha mineral e inicialmente
 desligada
 
 ● Liga: modifica Esta Ligada de Não para Sim
 
 ● Desliga: modifica Esta Ligada de Sim para Não
 
 ● Move: modifica a Localização da Sonda para outro par (Latitude, Longitude)

 TAD 6 - TIPO ABSTRATO DE DADOS LISTA DE SONDAS ESPACIAIS:

  Este TAD deverá permitir a criação de uma lista linear de Sondas Espaciais, com as operações:
 
 ● Inicializa: inicializa uma lista de sondas vazia
 
 ● Insere: insere uma nova sonda no final da lista
 
 ● Retira: retira a sonda com identificador I
 
 ● Imprime: mostra na saída todas as sondas presentes na lista, imprimindo todos os
    atributos de cada uma delas.


atual comando para compilar:
 gcc -o Programa main.c src/ListaSonda/TAD_ListaSonda.c src/Lis
taSonda/SondaEspacial/TAD_Sonda.c src/ListaSonda/SondaEspacial/Compartimento/TAD_Compartimento.c src/ListaSonda/SondaEspacial/Com
partimento/Rocha_Mineral/TAD_RochaMineral.c src/ListaSonda/SondaEspacial/Compartimento/Rocha_Mineral/Categorias/TAD_Categorias.c 
src/ListaSonda/SondaEspacial/Compartimento/Rocha_Mineral/Data_Coleta/TAD_DataColeta.c src/ListaSonda/SondaEspacial/Compartimento/
Rocha_Mineral/Localizacao/TAD_Localizacao.c src/ListaSonda/SondaEspacial/Compartimento/Rocha_Mineral/Lista_Minerais/TAD_ListaMine
ral.c src/ListaSonda/SondaEspacial/Compartimento/Rocha_Mineral/Lista_Minerais/Mineral/TAD_Mineral.c src/ListaSonda/SondaEspacial/
Compartimento/Rocha_Mineral/Lista_Minerais/Mineral/Cores/TAD_Cores.c