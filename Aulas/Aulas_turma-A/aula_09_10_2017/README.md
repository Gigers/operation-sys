# Aula - 09/10/2017

* Principais componentes do sistema operacional:
    * 1° - Processador;
    * 2° - Memória.

### Como o sistema operacional distribui as memórias para os demais programas ?

Página do livro (Arquitetura de sistemas operacionais): 159

Utiliza-se duas estratégias:
* Estática (Alocação particionada estática ou fixa):
    * Utilizado pelos primeiros programas multiprogramados;
    * Espaço fixo separado para os programas;
        * Isso ocorria por conta dos montadores e compiladores da época, isso porque,e eles fazia atribuição absoluta de endereçços de memória ao programa. (Esta técnica refere-se a alocação particionada estática absoluta).
    * Espaços que ficam sobrando na memória -> Fragmentação interna;
    * Tamanho de partições de memória feitas na inicialização do sistema;
    * Se alguma alteração fosse necessária, esta seria feita através da reinicialização da máquina;
    * Nos formatos de alocação particionados estáticos relocável os programas não tem definição de memória absoluta;
        * Para fazer isto funcionar o sistema operacional cria uma tabela das partições e quais delas estão em uso ou não.
    * Proteção baseada em dois registradores, esses que delimitam quais serão os pontos de memórias máximas que serão utilizadas pelo programa, e caso o programa fosse além deste limite ele era interrompido e um erro de violação de memória era exibido;
    * Neste formato de alocação de memória, hávia o problema da fragmentação, onde os programas não usavam todo o espaço disponível para ele, conhecido como fragmentação interna.
* Dinâmica:
    * Não há espaços pré-definidos;
    * Cada programa utiliza o espaço que for necessário;
    * Não há o problema de fragmentação interna;
        * Porém gerou a framentação externa.
    * Para a solução da fragmentação externa há duas técnicas:
        * Na primeira, as memórias adjacentes ao programa que foi finalizado se juntam para criar espaços de memória livre maior;
        * Na segunda técnica, os programas são relocados, todos eles são movidos para áreas novas na memória, liberando assim todo espaço que está sendo subutilizado. (Conhecido também como partição dinâmica com relocação);
            * É problemático por ser bastante complexo. 
    * Algoritimos de alocação dinâmica (Página: 165)
    Para realizar a implementação da alocação dinâmica existem três técnicas, e são elas:
        * Best-fit:
            * A partição escolhida para alocar o programa é a que irá deixar menos quantidade de espaço sendo subutilizado;
            * As áreas estão ordenadas por tamanho, o que faz a busca ser mais simples;
            * Problema é: Em médio prazo só haverá espaços pequenos, dificil de alocar (Aumenta o problema da fragmentação);
        * Worst-fit:
            * Aloca sempre nos maiores espaços, ou seja, nas piores memórias;
            * Ao alocar sempre nos maiores espaços de memórias disponíveis, deixa muitos espaços de memórias livres, evitando o problema de framentação;
            * 
        * First-fit:
            * Primeiro que entra no espaço e encaixa serve;
            * Mais rápida que as duas citadas anteriormente;
            * Ordenada as memórias em ordem crescente;
            * Consome menos recursos do sistema.
* Swap
    * Memória de troca;
    * Utilizada para contornar o problema da falta de memória principal;
    * Técnica aplicada a programas que estão esperando por espaços na memória para serem executados;
    * Esta técnica existe para ajudar na gerência de memória, e como dito acima, é aplicada aos programas que estão em espera porque até eles ocupam espaço na memória principal
    * A técnica pega o programa que tem a menor chance de ser executado e está na memória principal e coloca ele na memória secundária, e quando for necessário sua execução, volta ele para o disco.
    * Swap out: Tiro da memória e coloco no disco;
    * Swap in: Tipo do disco e passa para a memória.

### Overlay

Técnica onde o programador define a quantidade de memória que será utilizada, ele define o módulo principal, este será o maior, e não poderá ser modificado, e os módulos secundários, que poderão ser modificados.
Técnica utilizada apenas nos sistemas estáticos.

### Hiberfil.sys
Arquivo usado pelo Windows como swap na memória

### Exercícios

* 1 - Gerenciar os espaços de memória para cada programa, 

* 2 - Está sendo subutilizado 1/4 da memória, isso porque apenas 30 Kb está sendo utilizado sobrando 10 Kb

* 3 - Técnica onde o programador define a quantidade de memória que será utilizada, ele define      o módulo principal, este será o maior, e não poderá ser modificado, e os módulos                secundários, que poderão ser modificados. Técnica utilizada apenas nos sistemas estáticos.

* 4 - O programa não poderá ser executado, pois sem espaço não há execução.

* 5
    * Interna: Espaço vazio entre uma alocação e outra;
    * Externa: Espaços cada vez menores na memória, difíceis de serem alocados.

* 6
* a-) Fragmentação:
    * P1-) 2 Kb;
    * P2-) 4 Kb;
    * P3-) 4 Kb;
* b-) Fragmentação:
    * P1-) 4 Kb;
    * P2-) 8 Kb;
    * P3-) 6 Kb;
* c-) Fragmentação:
    * P1-) 0 Kb;
    * P2-) 0 Kb;
    * P3-) 0 Kb;

* 9 - <code>Resposta dentro do diretório exe_09</code>

* 11 - <code>Resposta dentro do diretório exe_11</code>

* 12 - <code>Resposta dentro do diretório exe_12</code>

* 13 - O swapping é uma técnica para o auxilio de gerência de memória, criado para resolver o problema de insuficiência de memória principal. Veja que todo programa, ele estando em espera, ou execução, está alocando memória, e isso em ambientes com poucos recursos de memória pode ser  um problema, assim para resolver este problema, o swap pega os programas que estão na memória principal em espera, que tem poucas chances de serem executados e envia eles para a memória secundária (Normalmente o disco rigido). E quando ele for executado, volta para a memória principal normalmente.

* 14 - O loader permite que o programa seja colocado em qualquer posição da memória, assim toda vez que o programa for carregado do swap, o loader se encarrega de fazer sua alocação.