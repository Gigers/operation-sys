# Aula - 06/11/2017

## Leitura

Realizar a leitura do capitulo 11

### Sistema de arquivos

Os processos devem ser capaz de armazenar e ler informações, bem como fazer o compartilhamento dessa com outros processos. Uma forma simples de isso ser realizado é através de arquivos.

O resposável pela gerência e controle desses é o sistema operacional. Especificamente, a área do sistema operacional que cuida dos arquivos é chamada de sistema de arquivos.

#### Arquivos

Um arquivo é constituido por informações logicamente relacionadas. Estas informações podem ser instruções para o processador ou dados. No caso de arquivos executado, ele carrega informações que o processador consegue interpretar, e nos dados contém informações que são montadas de forma não muito rigida, ou podendo ser com a utilização de um banco de dados.

Os arquivos podem ser armazenados em diferentes meios físicos, como em fitas e discos magnéticas, discos opticos. É importante notar que deve haver entre a informação e o meio de armazenamento uma independência.
<!-- Dúvida: Independência ? -->


* Identificação dos arquivos:
    * Essa pode variar entre sistemas operacionais, em alguns sistemas , a identificação é feita pelo nome do arquivo, podendo esta identificação ser ou não case sensitive;
    * Já em outros, a identificação é feita através de um campo chamado extensão, esse que é separado do nome do arquivo por um ponto <.> 

##### Organização de arquivos

A organização de arquivos consiste em como os seus dados estão internamente armazenados. A estrutura dos dados pode variar em função de seu tipo e propósito, veja que arquivos de texto tem formatos completamente diferentes que tem os arquivos executaveis. 

Existem diferentes formas de implementar a organização dos arquivos, seja essa regras impostas pelo sistema operacional, ou por padrões adotados por aplicações.

O caso mais simples acaba sendo a organização de arquivo, onde o sistema deixa uma quantia de bytes livres para que a aplicação que estiver salvando os dados defina o padrão de organização, a grande vantagem deste tipo de organização é que além de ser a mais simples permite maior flexibilidade, porém o controle e acesso a aquele arquivo deve ser feito pelo programa que o gerou.

Há certos tipos de sistemas operacionais que implementam formas diferentes de organização de arquivos, assim cada arquivo deve ser gerado com algum padrão suportado pelo sistema. Os padrões mais conhecidos são, Sequencial, relativa e indexada, nestes formatos de organização pode-se visualizar os arquivos como conjuntos de registros.

Esses registros podem ser classificados em dois tipos:
* Registro de tamanho fixo;
* Registro de tamanho variável.

##### Métodos de acesso

Dependendo da forma com que o arquivo está organizado, o sistema operacional pode recupera-lo de diferentes formas. Um exemplo podem ser os primeiros sistemas operacionais, que só gravavam arquivos em fitas magnéticas, essa que por sua vez armazenava em um formato de fila, onde novos arquivos eram salvos no final, sendo necessário começar do primeiro para chegar até o arquivo desejado. Esse tipo de acesso é conhecido como sequêncial.

Porém outros métodos surgiram, como o acesso direto, onde as operações de ler ou gravar eram feitas através do registro direto da posição onde estava o arquivo no disco, neste método não há necessidade de ordem na leitura nem na gravação, porém é necessário o número de registro. Outro fato é que, para implementar este método de acesso o arquivo deve estar organizado com registros de tamanho fixo.

É possível unir os dois métodos citados antes, assim permitindo acesso a um arquivo especifico e apartir desse realizar uma busca sequêncial.

Uma outra forma de acesso, que utiliza o acesso direto, é o acesso indexado, onde os arquivos possuem chaves, essas que são referênciadas pelos ponteiros do sistema e podem ser acessados pela aplicação a partir da chave, e através dessa o sistema encontra o local onde está o arquivo.

##### Operações de Entrada/Saída

As operações de entrada e saída são uma interface oferecida pelo sistema operacional.

##### Atributos

Os arquivos possuem atributos que server para ajudar na gerência deles. Esses atributos normalmente são:

* Nome do criador;
* Permissões de acesso;
* Data de criação;
* Última modificação;
* Último backup realizado.

Esses atributos estão presentes em quase todo sistema operacional, embora há sistemas que não usam, ou tem seus próprios atributos de controle.

#### Diretórios

Os diretórios são <code>estruturas de dados</code> utilizadas pelo sistema operacional para organizar de forma lógica os arquivos, essas contém referência sobre os arquivos como, local físico, tamanho, organização e outros atributos.

Ao abrir o arquivo o sistema operacional mantém uma tabela com todos os arquivos abertos, nessas são mantidos os atributos do arquivo, essa tabela ajuda a manter o alto desempenho do sistema. Isso porque é importante saber quando um arquivo está ou não aberto, para que seja possível eliminir ele do espaço que ele está utilizando no sistema e na tabela.

A implementação de diretórios é bastante variada, a mais simples delas é a single-level directory, onde há apenas um único diretório com todos os arquivos do sistema, este formato acaba limitando o usuário por não permitir nomes iguais.

Depois dessa implementação surgiu a User File Directory (UDF), nessa para cada usuário tem-se um diretório separado, o que permite ao usuário criar arquivos sem a necessidade e preocupação de conhecer o nome de todos os arquivos do sistema, ou seja, essa implementação passou a evitar os conflitos causados na single-level directory.
Para a implementação desse sistema é necessário utilizar um diretório adicional, este denominado Master File Directory (MFD), é indexado pelo nome do usuário e faz referência a pasta pessoal.

Com a implementação do MFD surge uma nova implementação, onde há dois níveis. Com a utilização do MFD a arquitetura dos diretórios passou a ser parecida com um árvore, onde o MDF é a raiz e os UDF são os galhos. 

Nesta arquitetura para referênciar os arquivos, é necessário antes citar o usuário a quem o arquivo percente, ficando algo parecido com /NOMEDOUSUARIO/arquivo.txt

Claro que esta sintaxe pode variar de acordo com o sistema.

Com o MFD a estrutura melhorou, porém isso quando falamos da parte do sistema, para o usuário ainda existe apenas uma página, e então surge o Tree-structured directory, que é utilizado pela maioria dos sistemas operacionais, e trabalha de forma parecida com um árvore.

Nesta nova implementação o usuário pode criar subdiretórios, e fazer isso em vários níveis diferentes (Dependendo do sistema), além disso a estrutura passou a ficar mais organizada também para o sistema, aqui ainda há o MFD, e desse todos os demais diretórios são acessados. Os arquivos podem ser acessados por um path absoluto, veja o exemplo desse acesso no Linux

```shell
/home/user/documentos/dados/arquivos_fatec/so/aula_06_11_2017.md
```

#### Gerência de espaço livre em disco

Para que o sistema desempenhe as operações de alocar, excluir, entre outras já citadas, é importante que ele saiba quais espaços estão livres para novos armazenamentos. Esse controle normalmente é feito com a utilização de uma tabela ou lista, e cada vez que um arquivo é adicionado ou removido as alterações também são feitas nessa tabela.

Uma maneira bastante simples de fazer esse controle é através de uma técnica conhecida como bit map, nessa cada bloco do disco é representado em uma tabela, e quando há arquivos esse bloco é preenchido com o bit 1, e quando não tem, preenchido com um bit 0.

Outra forma de implementar o bit map é através de listas encadeadas, nessa cada bloco terá que dispor de um espaço, este que faz referência ao próximo bloco. Há alguns problemas com essa implementação, a primeira é que terá de haver um espaço livre para o endereço,e outra é que a lista deverá ser percorrida de forma sequêncial.

Por fim há um formato que diz que, blocos contiguos são geralmente liberados simultaneamente, desta forma podemos enxergar o disco como um segmento de blocos livres, assim é possível manter uma tabela com apenas o primeiro endereço dos blocos contiguos.

#### Gerência de alocação de espaço em disco

Uma operação já citada, e que merece atenção é a forma com que a alocação é feita, vejamos algumas formas de realizar este processo.

##### Alocação contígua

Nesta forma de alocação, o arquivo é alocado em um bloco contiguo, e a referência para esse é o endereço do primeiro bloco. O acesso é bastante simples, tanto na forma sequêncial quanto na forma direta. Seu grande problema é que para alocar terá de existir um bloco continuo de endereço livre para alocar o endereço.

Com a alocação contigua, podemos enxergar o disco com um grande vetor, com vários espaços, de diferentes tamanhos, onde os arquivos são alocados. 

Esses espaços, ou segmentos, estão divididos entre os alocados e os blocos livres. Caso ocorra de, no momento da alocação, haver mais de um espaço em que o arquivo se encaixe, será necessário utilizar alguma estratégia de alocação, sendo algumas delas (Já vistas em aulas passadas)

* First-fit:
    * O primeiro local disponível será onde o arquivo ficará armazenado.
* Best-fit:
    * Será alocado o espaço que deixa a menor quantidade de memória sobrando depois de alocado;
    * É necessário percorrer toda a lista para encontrar este valor, a não ser que a lista de blocos esteja ordenada
* Worst-fit:
    * Aqui o bloco que for alocado e deixar o maior espaço sobrando, será utilizado;
    * Da mesma forma que o best-fit, terá de percorrer a lista caso não esteja ordenado.

Idependente da forma de alocação, existe um problema na alocação contígua, com o tempo, os blocos vão se deteriorando em espaços menores, e pode ocorrer de chegar a um ponto em que não exista mais blocos contíguos.

Para contornar esse problema, é necessário usar uma rotina denominada desfragmentação, essa faz a reorganização dos arquivos no disco de maneira que exista apenas um único segmento de blocos livres. Pode levar muito tempo para ser executado. Esse é um processo que deve ser feito periódicamente.
<!-- O que é a área de trabalho, onde os arquivos são postos durante o processo ? -->

Com isso foi possível perceber que, o grande problema da alocação contígua, está justamente na alocação. Há ainda um problema que pode ocorrer que é, uma alocação temporária, para que depois essa passe a ser definitiva, e este não é um processo trivial de ser feito.

##### Alocação encadeada

Na alocação encadeada os arquivos estão organizados como um conjunto de blocos, onde um está ligado ao outro, sendo assim, um bloco deve salvar o endereço do próximo (Isso tira a necessidade de ter o endereço físico).
Aqui a fragmentação não tem efeito, já que os blocos não precisam ser armazenados de forma contígua. O que ocorre aqui é a fragmentação de arquivos, onde o arquivo é quebrado em diversas partes, gerando o externs.

As externs causam problemas no acesso ao arquivo, uma vez que para realizar a leitura/gravação o arquivo deve deslocar diversas vezes em sua superfície (Físico), o que causa problemas de velocidade ao acesso. Para evitar esses problemas a desfragmentação deve ser feita periódicamente.

Uma grande desvantagem é o acesso sequêncial, que pode ser bastante lento, além de desperdiçar espaço com os ponteiros.

##### Alocação indexada

A alocação indexada corrige os problemas da alocação encadeada, ou seja, aqui o acesso aos blocos pode ser feito diretamente e não ficam armazenados informações e/ou ponteiros nos blocos. Isso é feito porque aqui se utiliza um bloco de índice, esse que armazena todos os ponteiros e permite acesso direto aos blocos.

#### Proteção de acesso

Com uma quantidade elevada de múltiplos usuários usando o sistema, é vital a implementação de proteção de acesso, isso garante a integridade dos dados do usuário, isso porque existem definições que dizem respeito aos acessos ao arquivo, modificação, exclusão, adição ou qualque outra operação.

As principais encontradas nos sistemas operacionais são:

* Leitura; 
* Escrita;
* Execução;
* Exclusão.

No caso de diretórios, que também é mantido pelo sistema de arquivos, existem algumas outras operações como:

* Visualização do conteúdo;
* Eliminação do diretório;
* Permissão de criação/alteração dentro do diretório.

Para realizar a adição de proteções no acesso existem diversas técnicas, veja algumas delas.

##### Senha de acesso

A senha é um princípio bastante simples, onde para acessar os dados é necessário saber a senha, porém este é um formato bastante limitado, uma vez que não diz sobre o que pode ou não ser feito com o arquivo/diretório, isso se tratando de modificações, adições, exlusões. Um outro problema é o compartilhamento, já que todos terão de ter a senha.

##### Grupos de usuários

A implementação é muito utilizada em diversos sistemas, podendo ser visto no Windows (10, 8, Server, etc), e em sistemas POSIX. O princípio também é bastante básico, aqui um grupo é associado a permissões em certos arquivos. Neste macanismo existem três níveis de proteção

* Owner (Dono) - Apenas o dono tem acesso;
* Group (Grupo) - O grupo todo tem acesso;
* All (Todos) - Todos tem acesso.

Para cada um desses níveis de segurança é necessário específicar as ações que poderão ser realizados, seja ela leitura, escrita, visualização, exlusão, etc.


##### Lista de controle de acesso

A lista de controle de acesso é uma lista que faz o vinculo de cada um dos arquivos com os usuários que podem fazer sua utilização. Como neste tipo de controle todos os usuários são descritos por extenso, a lista pode ficar muito grande, o que pode causar um overhead. Se comparado aos grupos de usuário tem um menor desempenho com grandes quantidades por realizar a busca de forma sequêncial.

Há sistemas que fazem a implementação dos dois tipos de controle, trazendo flexibilidade ao sistema. Isso em casos em que não se quer adicionar um grupo, e sim um usuário e vice-versa.

#### Implementação de caches

Como o acesso ao disco sempre foi um grande problema no desempenho de sistemas operacionais, alguns sistemas começaram a realizar a implementação de um buffer cache, que é um espaço na memória principal que aloca informações sobre os arquivos que estiveram envolvidos em operações de entrada/saída. Assim quando necessário o processador primeiro verifica esse buffer cache, caso a informação esteja lá ele a usa, caso contrário, busca no disco.

Para definir o que fica no cache é utilizado técnicas como o FIFO ou LRU (Vistos em aulas passadas)

Existe um pequeno problema que vem junto com a implementação de caches, ele pode ocorre caso haja faltas de energia. Consiste básicamente em, os dados no cache em problemas de energia não são passados para o disco, e dessa forma são perdidas.

Para tentar solucionar este problema há duas técnicas

* 1° - Aqui os dados do cache são salvos períodicamente no HD
    * Menos E/S
    * Um mínimo risco de perda
* 2° - A cada modificação no cache, os dados são salvos no HD
    * Mais E/S
    * Quase nenhum risco de perda.

Por conta da quantidade de E/S, hoje boa parte dos sistemas operacionais usa a primeira técnica.

## Correção dos exercícios da última aula

* 22 - (Correção);
* 27 - (Correto);
* 34 - (Correção);
* 38 - (Completar).

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