# Aula - 30/10/2017

<!-- Fazer resumo da politica de alocação -->

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

Para encontrar o endereço real de uma página, é necessário somar o endereço da memória virutal mais o deslocamento.

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