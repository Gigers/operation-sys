# Aula - 23/10/2017

## Gerência de memória virtual

A memória principal é uma técnica que combina memória principal e secundária, para fazer com que os programas não se limitem apenas ao tamanho físico da memória principal.

Traz vantagens como:
* Como citado, o programa não está limitado apenas ao tamanho fíxo da memória principal, já que tem a memória física;
* Melhor utilização do processador;
* Mais processos sendo executados de uma única vez.

A memória virtual é gerenciada pelo MMU.

#### Espaço de endereçamento virtual

O conceito de memória virtual pode ser comparado a ideia de um vetor em uma linguagem como C, isso porque ao declarar um vetor o programador não se preocupa em quais endereços esse será alocado. E isso ocorre também na memória virtual, onde, os programas, aplicativos não se preocupam com as alocações, eles simplesmente as utilizam.

Pode ser que neles tenham endereços de memória, porém este não é o endereço real, e sim o virtual, que é distribuido. Isso faz com que o programa tenha suas partes na memória princípal ou secundário, sem que haja problemas com isto. Esse mecânismo trabalha no sistema de referências, onde uma memória virtual faz referência a uma física, e pode ser chamado de mapeamento.

O endereçamento virtual faz com que a área de endereçamento de um programa seja conhecido como <code>espaço de endereçamento virtual</code> e representa o conjunto de endereços virtuais utilizados pelo programa, e os endereços físicos são alocados no <code>espaço de endereçamento real</code>

Como já citado, o mecânismo de memória virtual permite a utilização de mais referências de memória virtual que o disponível na memória principal, isso ocorre por que, este faz o uso da memória secundária para trabalhar.

Ele basicamente faz com que apenas as partes do programa que estão em execução fiquem na memória principal, e os demais na memória secundária até serem referênciados.

#### Mapeamento

Esta é a técnica utilizada para fazer a referência entre endereço real e virtual. Com ele a alocação contigua em memória teve o problema resolvido.

O componente que faz a gerência deste processo é o Memory Management Unit (MMU), sendo acionado sempre que um endereço é referênciado.

Todos os programas tem suas próprias tabelas de memória, como se a memória estive lá apenas para elas.

O mapeamento trabalha com uma tabela que se adepta aos horários que ele tem para executar.

OBS: É uma estrutura de dados

#### Paginação

A memória virtual por paginação é uma técnica para gerência de memória onde os espaços de memória virtual e real são divididos em blocos (estes denominados páginas) de tamanho igual a todos.

No espaço virtual as páginas são chamadas de páginas e no espaço real essas são chamadas de frame ou página real.

Todo o mapeamento de endereço virtual em real é realizado através das tabelas de páginas, cada processo possui sua própria tabela, e cada página virtual do processo tem sua entrada na tabela (ETP - entrada na tabela de páginas).

Nesta técnica a memória virtual é formada pelo número de página virtual e o deslocamento.

Frame / Pagina real = Memória principal
Paginação = Memória virtual


#### Políticas de busca das páginas (Página 179)

A política de busca de páginas, básicamente diz qual página serã ou não carregada para a memória principal. Para isso existem duas formas da realização do processo, sendo elas:

* Paginação por demanda:
  * Neste tipo de política, a página é transferida para a memória principal, apenas quando é referênciada. Isso faz com que apenas as partes necessárias do programa seja executadas
* Paginação antecipada:
  * Aqui o sistema diferente da demanda, carrega a página referênciada, algumas outras páginas que podem ou não ser executadas são carregadas. Esta política pode ser problemática, mas em vários momentos ajuda, pois caso o programa esteja em uma ordem contigua, para o sistema é mais fácil carregar mais uma ou duas páginas sem saber se serão utilizadas, do que voltar depois a memória secundária para pegar mais páginas.

O processo antecipado pode ser usado sem problemas em momentos de page fault, para que subpáginas sejam puxadas, Isso evita o processador gastar tempo voltando a memória principal, o que é visto como uma grande vantagem.

#### Working set

O Working set pode ser definido como um conjunto de páginas que está sendo utilizado pelo processo em determinado tempo. Isso torna eficiente alocar as páginas na memória, uma vez que essas são as páginas referênciadas pelo processo, e que serão necessários naquele intervalo de tempo.
O intervalo de tempo é denominado <code>janela de working set</code>, e o tamanho desta é definido pela quantidade de páginas as quais estão se referênciando.

Alguns pontos que devem ser observados sobre o working set são:

* Caso o limite de páginas reais seja maior que o working set, menor serão as chances de uma página referênciada pelo processo não estar presente na memória;
  * Na situação dita acima, o que pode ocorrer é a ocupação excessiva de memória;
* No caso do limite ser menor que o working set, a paginação será alta, isso porque o working set não estará em sua totalidade na memória principal.

Apesar de o conceito ser bastante simples, a implementação do working set não é nada simples, isso porque o sistema operacional terá de garantir que o working set de todos os processos estejam na memória principal. Isso faz com que esta técnica seja implementada apenas em sistemas de politica de alocação de páginas variável.

Uma forma de implementar esta técnica, é a estratégia de frequência de <code>page fault</code>, onde é estabelecido um limite, e caso este seja ultrapassado, a quantidade de páginas limite aumenta, para que se tente buscar o working set completo do processo, e caso não ultrapasse o limite, o sistema continua o tratamento normal, evitando problemas com desempenho.

#### Segmentação

A memória virtual por segmentação divide os endereços de memória, assim como a paginação, porém, diferente dessa a segmentação divide os blocos de memória de tamanhos diferentes.
Neste tipo de técnica os programas são divididos em sub-rotinas e estruturas de dados.

Outro ponto diferente, na segmentação a alocação tem a ver com a lógica do programa, e na paginação nada disso ocorria.

Seu mecanismo de mapeamento é similiar ao da paginação. Porém pontos ocmo a proteção, compartilhamento e estruturas de dados dinâmicas são mais simples que as de paginação.

Há ainda um outro ponto bastante interessante sobre a segmentação. Como foi dito, a segmentação divide a memória em espaços diferentes, e esses podem variar o tamanho durante a execução do programa, o que facilita muito a implementação de estruturas dinâmicas.

## Exercícios

1 a 9

<code>1</code> - Quais os benefícios oferecidos pela técnica de memória virtual ? Como este conceito permite que um programa e seus dados ultrapassem os limites da memória principal ?

R: As vantagens oferecidas pela memória virtual são:

* O programa deixa de estar limitado aos tamanhos físicos da memória;
* Mais processos sendo executados de uma única vez;
    * Isso ocorre porque ficam na memória apenas partes do programa.
* Melhor utilização do processador

<code>2</code> - Explique como um endereço virtual de um processo é traduzido para um endereço real na memória principal ?

R: A tradução é feita através do mapeamento, este que é um mecânismo que trabalha com as referências das memórias e é controlado pelo MMU (Memory Management Unit). Com ele os problemas de alocação contigua foram resolvidos.

<code>3</code> - Por que o mapeamento deve ser feito em blocos e não sobre células individuais ? Apresente um exemplo numérico.

R: Caso o mapeamento fosse feito em células individuais seu tamanho o tornaria inviavel, pois o tamanho da célula teria o mesmo espaço do endereçamento remoto.

<code>4</code> - Qual a principal diferença entre os sistemas que implementam paginação e os que implementam segmentação ?

R: A principal diferença entre as duas tecnicas está na forma de alocação de memória, onde a pagina faz alocação igual para os blocos e a segmentação cria segmentos de diversos tamanhos, estes que podem crescer durante a execução do programa, facilitando a implementação de estruturas de dados dinâmicas.

<code>5</code> - Diferencie página virtual de página real.

R: Endereço real são os endereços presentes na memória principal, já a página virtual são endereços que fazem parte do grupo de memória virtual de um processo.

<code>6</code> - O que são tabelas de páginação e tabelas de segmento ?

R: As tabelas de páginação são estruturas de dados utilizadas para realizar o mapeamento na páginação. E as tabelas de segmento carregam os espaços de memória livre e carregadas. Para que seja possível saber quando será ou não possível realizar a alocação de um segmento novo.

<code>7</code> - Para que serve o bit de validade nas tabelas de páginas e segmentos ?

R: Indica se o segmento e ou página estão na memória principal.

<code>8</code> - O que é um page fault, quando ocorre e quem controla a sua ocorrência ? Como uma elevada taxa de page fault pode comprometer o sistema operacional ?

R: Este é um processo que ocorre sempre que um processo faz referência a uma página que não está na memória principal, e esta verificação é feita através da entrada na <code>tabela de páginas</code>. Caso muitos page faults ocorram, o desempenho do sistema pode ser comprimetido.

<code>9</code> - Nos sistemas de paginação, a rotina para tratamento de page faults está residente na memória principal. Esta rotina pode ser removida da memória principal em algum momento ? O que aconteceria se esta rotina não estivesse na memória principal durante a ocorrência de um page fault ?

R: Não, se ela não estiver lá, não será possível chamar as páginas requisitadas pelo processo.

## Memória (Questões de sala)

* Quantos endereços tem dentro de um espaço de 4 bytes (int) ?

R: 4 endereços, a cada 1 byte, há um endereço. Não vemos isso em C, pois ele facilita o processo, e então vemos apenas um endereço, para os quatro bytes alocados.

## Dicas

Latência e diferenças de tempos da memórias
https://dzone.com/articles/scale-computing-latencies
