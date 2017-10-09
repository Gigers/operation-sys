# Aula - 09/10/2017

* Principais componentes do sistema operacional:
    * 1° - Processador;
    * 2° - Memória.

### Como o sistema operacional distribui as memórias para os demais programas ?

Página do livro (Arquitetura de sistemas operacionais): 159

Utiliza-se duas estratégias:
* Estática:
    * Espaço fixo separado para os programas;
    * Espaços que ficam na memória -> Fragmentação interna;
* Dinâmica:
    * Não há espaços pré-definidos;
    * Algoritimos de alocação dinâmica (Página: 165)
        * Best-fit:
            * A partição escolhida para alocar o programa é a que irá deixar menos quantidade de espaço sendo subutilizado;
            * As áreas estão ordenadas por tamanho, o que faz a busca ser mais simples;
            * Problema é: Em médio prazo só haverá espaços pequenos, dificil de alocar;
        * Worst-fit:
            * Aloca sempre nos maiores espaços;
        * First-fit:
            * Primeiro que entra no espaço e encaixa serve.
* Swap
    * Memória de troca
    * Swap out: Tiro da memória e coloco no disco;
    * Swap in: Tipo do disco e passa para a memória.

### Overlay

Técnica onde o programador define a quantidade de memória que será utilizada, ele define o módulo principal, este será o maior, e não poderá ser modificado, e os módulos secundários, que poderão ser modificados.
Técnica utilizada apenas nos sistemas estáticos.

### Hiberfil.sys
Arquivo usado como swap na memória

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

* 9 - 

* 11 - 

* 12 - 

* 13 - 

* 14 - 