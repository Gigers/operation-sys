# Aula 26/10/2017

## Correção dos exercícios

<code>2</code> - Explique como um endereço virtual de um processo é traduzido para um endereço real na memória principal ?

R: A tradução é feita através do mapeamento, este que é um mecânismo que trabalha com as referências das memórias e é controlado pelo MMU (Memory Management Unit). Com ele os problemas de alocação contigua foram resolvidos. E para iniciar EDP!!!!

<code>5</code> - Diferencie página virtual de página real.

R: Endereço real são os endereços presentes na memória principal, já a página virtual são endereços que fazem parte do grupo de memória virtual de um processo. A pagina virtual sempre está associada a uma página real

## Políticas de busca das páginas

A política de busca de páginas, básicamente diz qual página serã ou não carregada para a memória principal. Para isso existem duas formas da realização do processo, sendo elas:

* Paginação por demanda:
  * Neste tipo de política, a página é transferida para a memória principal, apenas quando é referênciada. Isso faz com que apenas as partes necessárias do programa seja executadas
* Paginação antecipada:
  * Aqui o sistema diferente da demanda, carrega a página referênciada, algumas outras páginas que podem ou não ser executadas são carregadas. Esta política pode ser problemática, mas em vários momentos ajuda, pois caso o programa esteja em uma ordem contigua, para o sistema é mais fácil carregar mais uma ou duas páginas sem saber se serão utilizadas, do que voltar depois a memória secundária para pegar mais páginas.

O processo antecipado pode ser usado sem problemas em momentos de page fault, para que subpáginas sejam puxadas, Isso evita o processador gastar tempo voltando a memória principal, o que é visto como uma grande vantagem.


## Algoritimos de substituição de página

Os algoritimos de substituição representam uma das grandes dificuldades para a implementação de um sistema operacional. Isso porque como dito por Denning, o grande problema não é fazer uma nova alocação, o problema está em quem será retirado para entrar a nova alocação.
O problema está em, quanto mais sofisticado é a análise feita pelo algoritimo, maior as chances de ocorrências de overhead no sistema.

Abaixo são apresentados alguns algoritimos:

* <code>Ótimo</code>
    * Este algoritimo seleciona para substituição uma página que não será mais referênciada no fuuturo ou aquela que levará o maior intervalo de tempo para ser executada novamente;
    * O problema deste algoritimo, e o que torna ele impossível de implementar, é que, o sistema operacional não consegue identificar as ações futuras do processo.

* <code>Aleatório</code>
    * Como o próprio nome sugere, este algoritimo escolhe um frame/página aleatoriamente, sem seguir nenhum critério. Podendo ocorrer também de ser selecionados os frames mais utilizados;
    * Apesar de utilizar pouco recurso, não é muito utilizado por ser pouco eficiente.

* <code>FIFO</code>
    * Aqui o principio de fila é aplicado, onde, o que está a mais tempo na memória será o retirado, pode parecer bom de inicio, porém, nem sempre o que está na fila a mais tempo, é o que já terminou de ser executado, isso pode variar de acordo com o processo que faz a utilização da página;
    * Veja como exemplo uma página de dados, que é referênciado a todo instante, assim não deixa de ser utilizada, mesmo estando a bastante tempo na memória principal;
    * Normalmente o <code>FIFO</code> é implementado com outros algoritimos, que auxiliam na solução deste problema.

* <code>LFU - Least-Frequently-Used</code>
  * Este algoritimo faz a seleção das páginas que são menos referênciadas na memória, e para isso utilizam um contador em cada página, e assim a página com menor contado é retirada;
  * O grande problema é que, muitas das vezes as páginas com menor quantidade no contador são aquelas que estão a menos tempo na memória, isso pode causar problemas. Por isso este é um algoritimo base para outros, e não é utilizado sozinho.

* <code>LRU - Least-Recently-Used</code>
  * Aqui a escolha vai para a página que está a mais tempo sem ser referênciada, isso vai de encontro a uma das bases ditas pelo principio da localidade, onde se uma página está a algum tempo sem ser referênciada, provavelmente, não será mais usada;
  * Para a implementação deste algoritimo é necessário que cada página, carregue uma referência da última vez que foi utilizada;
  * Mesmo sendo bastante eficiente, não é muito usado por conta do custo de implementação.

* <code>NRU - Not-Recently-Used</code>
  * O NRU é bastante parecido com o LRU, porém menos sofisticado;
  * Neste algoritimo é utilizado um bit de verificação, que alterna entre 0 e 1;
    * Trabalha da seguinte maneira: Quando a página é referênciada, o bit passa a ser 1, indicando que a página foi utilizada recentemente. De tempos em tempos o sistema passa e coloca o bit em 0, então o algoritimo verifica quem está em 1, ou 0, e faz a remoção.

* <code>FIFO com Buffer</code>
  * Como citado anteriormente, o FIFO quando unido a outros algoritimos consegue um bom resultado, e este é o caso do Buffer;
  * Neste caso, são criadas duas listas, são elas.
    * As listas citadas a seguir, podem ser criadas para cada processo, ou generalizadas, para todos os processos.
    * A primeira lista (LPA - Lista de páginas alocadas) refere-se as paǵinas que estão sendo alocadas, onde a mais antiga fica no topo e a mais nova no final;
    * A segunda lista (LPL - Lista de páginas livres) por outro lado, está relacionada aos frames que estão livres na memória principal.
  * Perceba que, o funcionamento é bastante simples, onde, quando o sistema necessita alocar um frame, ele remove o frame que será alocado, ou seja, o primeiro da LPL, e coloca ele no final da LPA.
  * Quando o sistema precise liberar espaço de página, é selecionado o primeiro da LPA, ou seja, o que está alocado a mais tempo.
  * É possível perceber então que as listas server como um buffer de páginas, evitando que elas sejam levadas para a memória secundária;
  * Com o passar do tempo a página que não for referênciada, irá chegar ao inicio da LPL, onde será devolvida para a memória secundária;
  * Por fim, permite a criação de algoritimos simples e de fácil implementação.

* <code>FIFO com circular (Clock)</code>
  * Este é um algoritimo criado para resolver o problema do FIFO com o tempo de alocação das páginas;
  * Neste algoritimo há a utilização de bit de referência e de um ponteiro, que aponta para a página alocada a mais tempo;
  * O ponto deste algoritimo é que, ele acesso o ponteiro e verifica a memória mais antiga, caso seu bit de referência seja 0, a página é removida, caso seja 1, ou seja, indica que a página foi recentemente utilizada, ela não é removida;
  * Aqui existe a possíbilidade de todos os bits de referência das paginas serem 1, e então o sistema passa colocando zero em todos, e depois o ponteiro verifica, e a mais antiga é removida.

## Exercícios da aula de hoje

<code>10</code> - Descreva como ocorre a fragmentação interna em um sistema que implementa paginação.

R: A fragmentação interna pode ocorrer na última página, alocada, pois ela pode não utilizar toda a memória disponível.

<code>11</code> - Compare as políticas de busca de páginas apresentadas

R:
* Paginação por demanda:
  * Neste tipo de política, a página é transferida para a memória principal, apenas quando é referênciada. Isso faz com que apenas as partes necessárias do programa seja executadas
* Paginação antecipada:
  * Aqui o sistema diferente da demanda, carrega a página referênciada, algumas outras páginas que podem ou não ser executadas são carregadas. Esta política pode ser problemática, mas em vários momentos ajuda, pois caso o programa esteja em uma ordem contigua, para o sistema é mais fácil carregar mais uma ou duas páginas sem saber se serão utilizadas, do que voltar depois a memória secundária para pegar mais páginas.

<code>12</code> - Quais as vantagens e desvantagens da política de alocação de páginas variável comparado à alocação fixa ?

R:
Alocação fixa

Vantagens:
* Simples implementação;

Desvantagens:
* Pouco flexivel;
* Não atende a todas as necessídades da alocação dos processos.

Alocação dinâmica:

Vantagens:
* Atende melhor as necessídades de alocação de memória dos processos;

Desvantagens:
* O sistema operacional deve estar sempre monitorando o comportamento dos processos, o que acaba gerando mais overhead.

<code>Pergunta</code> - Memória real trabalhando, em algum momento vai ocorrer page fault, para isso há implementações para buscar de forma antescipada, como é escolhido o processo a ser retirado para a pagina pega pelo page fault entrar na memória

R: Pode ser escolhido o processo que está apresentando muito page fault, ou todos os processos, para que assim todos entram.

<code>Pergunta</code> - O que é o princípio da localidade ?

R: O princípio da localidade é pode ser divido em duas partes

* Princípio da localidade temporal:
  * Aqui é descrito que, um dado que tenha sido acessado recentemente, tem maiores chances de serem acessados. Isso é verdade, uma vez que, as variáveis de um programa em execução, são sempre mais acessadas.
* Princípio da localidade espacial:
  * Nesta parte é levado como verdade que, há uma probabilidade maior de acesso a endereços de memória que estão fisicamente próximos. Isso também é uma verdade, porque no geral, o programa ao criar sua pilha de memória, faz isso de forma sequêncial, o que quase sempre garante que após acessar o endereço A, o B será acesso na sequência.

Seguindo estes princípios, o sistema de memória tende a manter os dados e instruções dos programas próximos, ao topo da hierarquia de memória que está sendo executada.


### Fontes

* http://producao.virtual.ufpb.br/books/edusantana/introducao-a-arquitetura-de-computadores-livro/livro/livro.chunked/ch05s02.html
* Livro - Arquitetura de sistemas operacionais 4° edição.
