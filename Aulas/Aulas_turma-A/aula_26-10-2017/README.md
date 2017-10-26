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

* <code>Ótimo</code>
    * Este algoritimo seleciona para substituição uma página que não será mais referênciada no fuuturo ou aquela que levará o maior intervalo de tempo para ser executada novamente;
    * O problema deste algoritimo, e o que torna ele impossível de implementar, é que, o sistema operacional não consegue identificar as ações futuras do processo.

* <code>Aleatório</code>
    * Como o próprio nome sugere, este algoritimo escolhe um frame/página aleatoriamente, sem seguir nenhum critério. Podendo ocorrer também de ser selecionados os frames mais utilizados;
    * Apesar de utilizar pouco recurso, não é muito utilizado por ser pouco eficiente.

<!-- * <code>FIFO</code>
    * 

* <code>LFU</code>


* <code>LRU</code>


* <code>NRU</code>


* <code>FIFO com Buffer</code>


* <code>FIFO com circular (Clock)</code> -->


## Exercícios da aula de hoje

<code>10</code> - Descreva como ocorre a fragmentação interna em um sistema que implementa paginação.

R: A fragmentação interna pode ocorrer na última página, alocada, pois ela pode não utilizar toda a memória disponível.

<code>11</code> - Compare as políticas de busca de páginas apresentadas

R:

* Paginação por demanda:
  * Neste tipo de política, a página é transferida para a memória principal, apenas quando é referênciada. Isso faz com que apenas as partes necessárias do programa seja executadas
* Paginação antecipada:
  * Aqui o sistema diferente da demanda, carrega a página referênciada, algumas outras páginas que podem ou não ser executadas são carregadas. Esta política pode ser problemática, mas em vários momentos ajuda, pois caso o programa esteja em uma ordem contigua, para o sistema é mais fácil carregar mais uma ou duas páginas sem saber se serão utilizadas, do que voltar depois a memória secundária para pegar mais páginas.

<!-- <code>12</code> - Quais as vantagens e desvantagens da política de alocação de páginas variável comparado à alocação fixa ?

R:  -->

<code>Pergunta</code> - Memória real trabalhando, em algum momento vai ocorrer page fault, para isso há implementações para buscar de forma antescipada, como é escolhido o processo a ser retirado para a pagina pega pelo page fault entrar na memória

R: Pode ser escolhido o processo que está apresentando muito page fault, ou todos os processos, para que assim todos entram.

<!-- <code>Pergunta</code> - O que é o principio da localidade ?

R:  -->