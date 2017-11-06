# Aula - 30/10/2017

<!-- Fazer resumo da TLB -->
<!-- Fazer resumo da política de alocação -->
<!-- Fazer resumo de memória virtual por segmentação com paginação-->
<!-- Fazer resumo de swapping em memória virtual -->
<!-- Thrashing -->

## Política de substituição de páginas

Durate a execuçãode vários programas, muitas páginas estão alocados na memória principal, há casos em que o programa necessita de mais frames para continuar trabalhando, e cabe ao sistema operacional decidir qual frame alocado será liberado para dar mais espaço para o programa que está necessitando.

O processo de substituição de frames é conhecido como política de substituição de páginas, e ela existe para evitar que páginas com informações importantes ou até mesmo em uso sejam removidas.

Em casos em que há códigos executaveis na memória, não muita preocupação, isso porque há uma cópia do código na memória secundária, porém, ao se falar de variáveis, estruturas de dados e outros, esses são salvos antes de serem desalocados, este processo é conhecido como page-out. Para manter um histório de tudo que foi feito, o sistema operacional tem um page file, neste contém todas as informações de páginas que foram movidas, excluidas e etc.

Sempre que uma página é referênciada, ocorre um page-in, transpondo a página do arquivo para a memória principal. O sistema consegue saber que uma página foi modificada por conta do bit de modificação, que é alterado a cada vez que a página sofre alguma modificação.

As políticas podem ser divididas em globais e locais, de acordo com seu escopo.


### Local
Apenas as páginas do processo que gerou o page fault são candidatas a realocação. Desta forma, caso o processo necessite de mais páginas, o sistema irá olhar qual página dentre as páginas referênciadas pelo sistema, poderão ser substituidas.

### Global
Neste caso, diferente do local, todas as páginas na memória principal podem ser substituidas, independente do processo que gerou o page fault.
Este tipo de política pode gerar um maior número de páginação, em função da redução de suas páginas na memória. 

## Atividades da aula

Realizar os exercícios de 13 até 38 do capítulo 10 - Gerência de memória virtual 

<code>13</code>

------------------------------------


Endereço físico |     Conteúdo


     1536       | Página Virtual 34


     2048       | Página Virtual 9


     3072       | Tabela de páginas


     3584       | Página Virtual 65


     4608       | Página Virtual 10


------------------------------------

<code>A</code>

------------------------------------


        Página          |     Frame


    Página Virtual 34   |       3


    Página Virtual 9    |       4


    Tabela de páginas   |       6 


    Página Virtual 65   |       7


    Página Virtual 10   |       9 


------------------------------------

<code>B</code>

------------------------------------


        Página          |     Frame


    Página Virtual 49   |       0


    Página Virtual 12   |       3


    Página Virtual 9    |       4


    Tabela de páginas   |       6 


    Página Virtual 65   |       7


    Página Virtual 10   |       9 


------------------------------------

<code>C</code>

O formato da memória virtual deste sistema é <code>2 ^ 9</code>, formando agrupamento de 512 páginas.

<code>D</code>

O endereço vinculado a página 4613 é o 9 (4613 / 512)

```python
    4613 # Endereço da memória virtual
    /
    512 # Tamanho do bloco de memória deste sistema
```

<code>14</code> - Um sistema operacional implementa gerência de memória virtual por paginação, com frames de 2Kb. A patir da tabela abaixo, que representa o mapeamento de páginas de um processo em determinado instante de tempo, responda:

<code>A-)</code> - Qual o endereço físico de uma variável que ocupa o último byte da página 3 ?

Neste exercício é interessante notar as informações passadas:

* Tamanho do frame: 2 Kb == 2.048 K;
* N° do frame da página 3: 10.

Veja que a página 10 é o 11° endereço de memória, uma vez que a contagem começa do 0.

O frame 11 é também onde a página 10 termina

Sendo assim,  11 * 2.048 (Número da página * tamanho do frame) = 22.527.

OBS: O resultado de 11 * 2.048 é 22.578, este já é o limite da memória, então, usamos o -1, para pegarmos o último endereço válido, sendo ele 22.527.

<code>B-)</code> - Qual o endereço físico de uma variável que ocupa o primeiro byte da página 2 ?

* Tamanho do frame: 2.048 Kb 
* N° do frame da página 2: 100;

<code>Caso fosse necessário encontrar o último endereço, seria utilizado o frame 101, que onde a página 2 acaba, porém queremos o primeiro endereço, então calculamos apenas o primeiro endereço</code>

100 * 2.048 = 204.8;

<code>C-)</code> - Qual o endereço físico de uma variável que tem deslocamento 10 na página 3 ?

<!-- Deslocamento 10, refere-se a 10 bits -->
<!-- Unidade do deslocamento ? -->

* Tamanho do frame: 2.048;
* N° do frame da página 3: 10.

2.048 * 10 = 20.48 + 10 b = 20.49 

<code>D-)</code> - Quais páginas do processo estão na memória ?

Páginas 0, 1, 2, 3, 6.

<!-- <code>15</code> - Um sistema operacional implementa gerência de memória virtual por paginação. Considere endereços virtuais com 16 bits, referênciados por um mesmo processo durante sua execução e sua tabela de páginas abaixo com no máximo 256 entradas. Estão representadas apenas as páginas presentes na memória real. Indique para cada endereço virtual a seguir a página virtual em que o endereço se encontra, o respectivo deslocamento e se a página se encontra na memória principal neste momento. -->


<code>16</code> - Uma memória virtual possui páginas de 1024 endereços, existem 8 páginas virtuais e 4096 bytes de memória real. A tabela de páginas de um processo está descrita abaixo. O asterisco indica que a página não está na memória principal:

<code>A-)</code> - Faça a lista/faixa de todos os endereços virtuais que irão causar page fault.

O page fault ocorre por todas as páginas que não estáo na memória principal, e este é um processo que ocorre quando esta página é referênciada na memória:

* Página 2: 2048 / 3071 (Faixa de 0 até 3071)

* Página 3: 3072 / 4095 

* Página 5: 5120 / 6143

* Página 7: 7168 / 8191

<code>B-)</code> - Indique o endereço real correspondete aos seguintes endereços virtuais 0, 1023, 1024, 6500 e 3728

Para encontrar o endereço real de uma página, é necessário somar o endereço do frame mais o deslocamento.

Endereço real: deslocamento + endereço real

* Endereço 0: 
    * Página virtual: 0
    * Deslocamento: 0
    * Endereço real: 0 + (3 * 1024)  = 3072 

* Endereço 1023:
    * Página virtual: 0
    * Deslocamento: 1023
    * Endereço real: 1023 + (3 * 1024) = 4095

* Endereço 1024:
    * Página virtual: 1
    * Deslocamento: 0
    * Endereço real: 0 + (1024) = 1024

* Endereço 6500:
    * Página virtual: 6
    * Deslocamento: 356
    * Endereço real: 356 + 0 = 356

* Endereço 3728:
    * Página virtual: 3
    * Deslocamento: 656
    * Endereço real: 656 + * = Page fault

<code>17-)</code> - Por que existe a necessidade de uma política de substituição de páginas ? Compare as políticas de substituição local e global

R: Cada processo faz referência a diversas páginas, porém há casos em que existe a necessidade de fazer referência a mais páginas, e para isso a necessidade de substituição das já alocadas surge.

Comparação: 

Local
* As candidadas a substituição estão ligadas ao processo que a chamou;
* Os demais processos não são modificados

Global
* Todas as páginas na memória principal, exceto as do sistema operacional, são candidatas para a substituição;
* Pode gerar mais páginação nos processos que tiveram suas páginas movidas.

<code>18-)</code> - Para que serer o bit de modificação nas tabelas de páginas e segmentos ?

R: Serve para indicar que uma página foi ou não modificada recentemente. Este é um atributo que poderá ser verificado por políticas de substituição, para que caso a página não tenha sido modificada recetente, ela será substituida

<code>19-)</code> - Como o princípio da localidade viabiliza a implementação da gerência de memória virtual por paginação ?s

R: Tem uma grande importância pois seus principios fazem com que haja menor chance de existir page faults. O que também deixa de afetar as operações de E/S

OBS: Isso porque como visto, o aumento dos page faults, afeta a E/S

<code>20-)</code> - Porque programas não estruturados estão sujeitos a uma alta taixa de fragmentação ?

R: Em programas estruturados, boa parte dos recursos usados pelo sistema já eram definidos em seu inicio, já em programas não estruturados, ele está sempre pedindo novos recursos, o que pode causar grande quantidade de páginação

<code>21-)</code> - Descreva os algoritimos de substituição de páginas FIFO e LRU, apresentando vantagens e desvantagens

* <code>FIFO</code>
    * Aqui o principio de fila é aplicado, onde, o que está a mais tempo na memória será o retirado, pode parecer bom de inicio, porém, nem sempre o que está na fila a mais tempo, é o que já terminou de ser executado, isso pode variar de acordo com o processo que faz a utilização da página;
    * Veja como exemplo uma página de dados, que é referênciado a todo instante, assim não deixa de ser utilizada, mesmo estando a bastante tempo na memória principal;
    * Normalmente o <code>FIFO</code> é implementado com outros algoritimos, que auxiliam na solução deste problema.

* <code>LRU - Least-Recently-Used</code>
  * Aqui a escolha vai para a página que está a mais tempo sem ser referênciada, isso vai de encontro a uma das bases ditas pelo principio da localidade, onde se uma página está a algum tempo sem ser referênciada, provavelmente, não será mais usada;
  * Para a implementação deste algoritimo é necessário que cada página, carregue uma referência da última vez que foi utilizada;
  * Mesmo sendo bastante eficiente, não é muito usado por conta do custo de implementação.

<code>22-)</code> - Considere um sistema com memória virtual por paginação com endereço virtual com 24 bits e página com 2048 endereços. Na tabela de páginas a seguir, de um processo em determinado instante de tempo, o bit de validade 1 indica página na memória principal e o bit de modificação 1 indica que a página sofreu alteração.

<code>a-)</code> - Quantos bits possui o campo deslocamento do endereço virtual ?

2 ^ 11 = 2048 = 11 bits

<code>b-)</code> - Qual o número máximo de entradas que a tabela de páginas pode ter ?


<code>c-)</code> - Qual o endereço físico que ocupa o último endereço da página 2 ?


<code>d-)</code> - Qual o endereço físico traduzido do endereço virtual (00080A)16 ? 


<code>e-)</code> - Caso ocorra um page fault e uma das páginas do processo deva ser descartada, quais páginas poderiam sofrer page out ?


<code>23</code> - Considere um sistema de memória virtual que implemente paginação, onde o limite de frames por processo é igual a três. Descreva para os itens abaixo, onde é apresentada uma sequência de referências a páginas pelo processo, o número total de page faults para as estratégias de realocação de páginas FIFO e LRU.

Indique qual a mais eficaz para cada um dos itens:

a-) 1/ 2/ 3/ 1/ 4/ 2/ 5/ 3/ 4/ 3

J = Já estava alocado

FIFO - Retira o que está a mais tempo na memória
Melhor política

5 Page faults

1  |  2 | 3  | 1  | 4  | 2  | 5  | 3  | 4  | 3  |

PF | PF | PF | J  | PF | J  | PF | J  | J  | J  |

   |    |    |    |  1 |    | 2  |    |    |    |

LRU - Retira a que está a mais tempo na memória sem ser referênciada

B - Byte de referência
1  | 2  | 3  | 1  | 4  | 2  | 5  | 3  | 4  | 3  |

PF | PF | PF | B  | PF | PF | PF | PF | PF | B  |

   |    |    |    | 2  | 3  | 1  | 4  | 2  |    |

b-) 1/ 2/ 3/ 1/ 4/ 1/ 3/ 2/ 3/ 3

FIFO = 7 Page faults
1  |  2 | 3  | 1  | 4  | 1  | 3  | 2  | 3  | 3  |

PF | PF | PF | J  | PF | PF | J  | PF | PF | J  |

   |    |    |    | 1  | 2  |    | 3  | 4  |    |

LRU = 5 Page faults (Melhor é o LRU)

1  |  2 | 3  | 1  | 4  | 1  | 3  | 2  | 3  | 3  |

PF | PF | PF | J  | PF | J  | J  | PF | J  | J  |

   |    |    |    | 2  |    |    | 4  |    |    |

<code>24</code> - Em um sistema de memória virtual que implementa paginação, as páginas têm 4 K endereços, a memória principal possui 32 Kb e o limite de páginas na memória principal é de 8 páginas. Um programa faz referência a endereços virtuais situados nas páginas 0, 2, 1, 9, 11, 4, 5, 2, 3, 1, nesta ordem. Após essa sequência de acessos, a tabela completa desse programa tem a configuração abaixo. As entradas em branco correspondem a páginas ausentes.


<code>a-)</code> - Qual o tamanho (em bites) e o formato do endereço virtual ?

K = 2 ^ 10 = 1.024

Informações:
Tamanho da página: 4 K
Memória principal: 32 Kb
Limite de páginas: 8

R:

Formato da memória:

<code>2 ^ 4 = 16</code>
4 bits para os possíveis 16 endereços

```python
   Deslocamento =  2 ** 2 + 2 ** 10 = 2 ** 12
```

<code>b-)</code> O processo faz novas referências a endereços virtuais situados nas páginas 5, 15, 12, 8 e 0, nesta ordem. Complete o quadro a seguir, que ilustra o processamento dessa sequência de acessos utilizando a estratégia de remoção FIFO. Mostre o estado final da tabela de páginas.


Página referênciada | Página removida   | Page Fault    
         5          |       -           | False
         15         |       0           | True
         12         |       2           | True
         8          |       1           | True
         0          |       9           | True


<code>25</code> - Em um computador, o endereço virtual é de 16 bits e as páginas têm tamanho de 2 K endereços. O limite de páginas reais de um processo qualquer é de quatro páginas. Inicialmente, nenhuma página está na memória principal. Um programa faz referência a endereços virtuais situados nas páginas 0, 7, 2, 7, 5, 8, 9, 2 e 4, nesta ordem.

<code>a-)</code> - Quantos bits do endereço virtual destinam-se ao número de páginas ? E ao deslocamento ?

Número de páginas: 2 ^ 1 + 2 ^ 10 = 2 ^ 11

16 bits de memória

Endereço virtual: 4 bits
Deslocamento: 11

<code>b-)</code> - Ilustre o comportamento da política de substituição LRU mostrando, a cada referência, quais páginas estão em memória, os page faults causados e as páginas escolhidas para descarte.

Resposta no arquivo <code>exe_25_b</code>

<code>26-)</code> - Um sistema trabalha com gerência de memória virtual por paginação. Para todos os processos do sistema, o limite de páginas na memória principal é igual a 10. Considere um processo que esteja executando um programa e em determinado instante de tempo (T) a sua tabela de páginas possui o conteúdo a seguir. O bit de validade igual a 1 indica página na memória principal e o bit de modificação igual a 1 indica que a página sofreu alteração.

<code>a-)</code> - Em quais instantes de tempo ocorreram um page out ?

* T + 4
* T + 6

<code>b-)</code> - Em que instante de tempo o limite de páginas do processo na memória principal é atingido ?

* T + 3

<code>c-)</code> - Caso a política de realocação de páginas utilizada seja o FIFO, no instante (T + 1), qual a página que está há mais tempo na memória principal ? 

* P0

<code>d-)</code> - Como o sistema identifica que no instante (T + 2) não há ocorrência de page fault ?

Através do bit de modificação

<code>27</code> - Um sistema possui quatro frames. A tabela abaixo apresenta para cada página o momento da carga, o momento do último acesso, o bit de referência e o bit de modificação

<code>a-)</code> - Qual página será substituida utilizando o algoritimo NRU ?
Frame 0

<code>b-)</code> - Qual página será substituida utilizando o algoritimo FIFO ?
Frame 2

<code>c-)</code> - Qual página será substituida utilizando o algoritimo LRU  ?
Frame 1

<code>28</code> - Considere um processo com limite de páginas reais igual a quatro e um sistema que implementa a politica de substituição de páginas FIFO. Quantos page faults ocorrerão considerando que as páginas virtuais são referenciadas na seguinte ordem 0 1 7 2 3 2 7 1 0 3. Repita o problema utilizando a política LRU


FIFO
Page faults = 6

J = Já estava
0  |  1 | 7  | 2  | 3  | 2  | 7  | 1  | 0  | 3  |

PF | PF | PF | PF | PF | J  | J  | J  | PF | J  |

   |    |    |    | 0  |    |    |    | 1  |    |

LRU
Page faults = 7
0  |  1 | 7  | 2  | 3  | 2+ | 7+ | 1+ | 0  | 3  |

PF | PF | PF | PF | PF | J  | J  | J  | PF | PF |

   |    |    |    | 0  |    |    |    | 3  | 2  |

<code>29</code> - Os sistemas operacionais OpenVMS e Windows NT/2000 utilizam dois buffers de páginas: um buffer de páginas livres e outro para páginas modificadas. Qual a vantagem de implementar um buffer de páginas modificadas ?

R: Com este arquivo o page in se torna mais rápido e fácil, por não perder o tempo salvando elas em disco. Isso faz o sistema operacional ter ganhos

<code>30</code> - Explique porque as páginas pequenas podem aumentar a taxa de paginação ?

R: Por precisar alocar mais páginas para desempenhas as funções, isso pode trazer um grande aumento na paginação. Diferente das páginas grandes, que armazenam menos, porém isso já é o suficiente para o processo.

<code>31</code> - A arquitetura VAX-11 utiliza 32 bits para endereçamento e páginas de 512 bytes. Calcule o número de bits para cada parte do endereço virtual, sabendo que o espaço de endereçamento é dividido em quatro partes: P0, P1, S0 e S1, sendo que cada uma possui sua própria tabela de páginas.

R: 2 ^ 2 = 4 (P0, P1, S0, S1); (2 bits)
Deslocamento: 2 ^ 9
Memória NPV2: 21

<code>32</code> - Um sistema computacional com espaço de endereçamento de 32 bits utiliza uma tabela de páginas de dois níveis. Os endereços virtuais são divididos em um campo de 9 bits para o primeiro nível da tabela, outro de 11 bits para o segundo nível, e um último campo para o deslocamento. Qual o tamanho das páginas ? Quantas páginas podem existir no espaço de endereçamento virtual ?

R:
Deslocamento = 2 ^ x

x = 32 - (11 + 9)

deslocamento = 2 ^ x = 4096

Nível 1 + Nível 2 = Espaço existente para o endereçamento de páginas virtuais
Dessa forma temos 2 ^ 20 páginas

<code>33</code> - Na arquitetura SPARC, o espaço de endereçamento virtual de 4G pode ser dividido para cada processo em páginas de 4 Kb. A busca do endereço real correspondente ao endereço virtual gerado pelo processador envolve, em caso de falha na TLB, três níveis de acesso à memória principal. No primeiro nível, é feito um acesso a uma tabela única por processo de 256 entradas. Essa tabela gera o endereço de uma das 256 possíveis tabelas de nível 2. Cada tabela de nível 2 possui 64 entradas e, quando acessada, gera o endereço da tabela de nível 3 que deve ser consultada. Essa tabela, que também possui 64 entradas, gera o endereço real procurado. Essa tabela de níveis 1, 2 e 3 formam basicamente uma árvore de busca na memória e vão sendo criadas dinamicamente à medida que novas páginas na memória vão sendo alocadas para aquele processo. Qual a vantagem de se ter esse esquema de tabelas em múltiplos níveis, criadas dinamicamente sob demanda, em vez de uma tabela única criada integralmente quando da carga do processo ? Justifique sua resposta com um exemplo ?

R: Caso fosse utilizado uma única tabela, teriamos problemas com o tamanho da tabela. Imagine um processo que tem milhares de entradas, e todas essas alocadas em uma única tabela, ela ficaria grande de mais e a gerência seria dificil, separar e colocar de forma dinâmica, facilita e mantém tudo funcionando sem que haja problemas com desempenho ou quantidade utilizada de memória.

<!-- <code>34</code>-  -->

<code>35</code> - Descreva o mecanismo de tradução de um endereço virtual em endereço real em sistemas que implementam gerência de memória virtual utilizando segmentação por paginação.

A segmentação por paginação contém os seguintes elementos

* NVS: Número do segmento virtual
* NPV: Número de página virtual
* Deslocamento

R: Através do NVS, obtém-se uma entrada na tabela de segmentos, que contém informações da tabela de páginas do segmento. O NPV identifica unicamente a página virtual que contém o endereço, funcionando como um índice na tabela de páginas. O deslocamento indica a posição do endereço virtual em relação ao início da página na qual se encontra, assim o endereço físico é obtido, então, combinando-se o endereço do frame, localizado na tabela de páginas, com o deslocamento, contido no endereço virtual.


<code>36</code> - Na técnica de swapping que critérios o sistema operacional pode utilizar para selecionar os processos que sofrerão swap out ?

R: Utiliza-se a prioridade do processo e a chance que este tem de ser executado.

<code>37</code> - Existe fragmentação em sistemas que implementam gerência de memória virtual ? Se existe, que tipo de fragmentação é encontado em sistemas com paginação ? Que tipo de fragmentação é encontrado em sistemas com segmentação ?

R: Existe, na paginação, ocorre a fragmentação interna, normalmente ocorre quando a última página não ocupa todo o espaço. E na segmentação ocorre a fragmentação externa, entre as páginas.

<code>38</code> - O que é thrashing em sistemas que implementam memória virtual ?

O thrashing é um problema que ocorre em sistemas que implementam a memória virtual, nele o sistema fica mais tempo fazendo a gerência da memória do que trabalhando nos processos.