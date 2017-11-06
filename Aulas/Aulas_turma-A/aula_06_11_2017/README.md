# Aula - 06/11/2017

## Correção dos exercícios

* 22 - (Correção);
* 27 - (Correto);
* 34 - (Correção);
* 38 - (Completar);


<code>38</code> - O que é thrashing em sistemas que implementam memória virtual ?

O thrashing é um problema que ocorre em todo tipo de sistema, principalmente nos que implementam a memória virtual, seja ela por paginação ou segmentação, nele o sistema fica mais tempo fazendo a gerência da memória do que trabalhando nos processos.

No caso da paginação, ocorre nos níveis de:

* Próprio processo:
    * Aumenta a paginação;
    * Aqui o sistema passa mais tempo esperando as páginas do que executando.

* Sistema
    * Ocorre quando existem mais páginas do que memória disponível;
    * Aqui o sistema pode ficar mais tempo realizando swapping do que processando, isso porque para evitar o problema de mais processos que memória, é utilizado o swap.

Na segmentação também ocorrem esses tipos de problemas, divididos em dois níveis, veja:

* Processo:
    * Pode ocorrer a transferência excessiva de segmentos, por conta da modularização dos exercícios.

* Sistema:
    * Também tem o problema do swap, apresentado na paginação.


<code>22-)</code> - Considere um sistema com memória virtual por paginação com endereço virtual com 24 bits e página com 2048 endereços. Na tabela de páginas a seguir, de um processo em determinado instante de tempo, o bit de validade 1 indica página na memória principal e o bit de modificação 1 indica que a página sofreu alteração.

<code>a-)</code> - Quantos bits possui o campo deslocamento do endereço virtual ?

2 ^ 11 = 2048 = 11 bits.

Frame: 1
Deslocamento: 100

<code>b-)</code> - Qual o número máximo de entradas que a tabela de páginas pode ter ?

Para encontrar a quantidade de páginas que a tabela pode ter, basta fazer a quantidade total do endereço virtual, menos o deslocamento 

tamanho da página - deslocamento = tamanho máximo de entradas
24 - 11 = 13

2 ^ 13 = 8192

<code>c-)</code> - Qual o endereço físico que ocupa o último endereço da página 2 ?
Tamanho da página + o tamanho da página

10.240 + 2.047
12.287

<code>d-)</code> - Qual o endereço físico traduzido do endereço virtual (00080A)16 ? 

Realizar conversão de base, e depois encontrar o endereço virtual

2058

<code>e-)</code> - Caso ocorra um page fault e uma das páginas do processo deva ser descartada, quais páginas poderiam sofrer page out ?

<code>34</code> - 

* tlb miss time
* tlb search time
* tlb hit time

Page fault: 2%

Direto: (2% of 100) = 2 * 2 (dois níveis) = 4 ns;

Indireto: direto * 2 = 12 ns // Passa pela tabela

OBS: Não há cache nem tempo de acesso a tlb

## Leitura

Realizar a leitura do capitulo 11