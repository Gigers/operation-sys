# Aula 16/10/2017

### Conceitos base para a aula

* Alocação contígua simples
    * Na alocação contigua simples é feita a divisão da memória em duas partes, a parte do sistema operacional, onde o mesmo irá ficar armazenado, e outra parte para os programas do usuário;
    * Neste tipo de alocação o usuário tem acesso a qualquer parte da memória principal, o que pode ser bastante inseguro. Para resolver isso alguns sistemas operacionais utilizam um registrador para delimitar as áreas do sistema operacional e a do usuário. Caso o programa em execução tente acessar algum ponto de memória, ele é cancelado e uma mensagem de violação de memória é exibido.
    * Seu problema é o mau uso da memória, isso porque, ao alocar um programa, deixa espaços da memória sem uso, e que não vão poder ser alocadas.

* Overlay:
    * Esta é uma técnica que surgiu para solucionar o problema da alocação contigua, onde, os programas estão limitados ao tamanho do bloco de memória reservado a eles;
    * A solução consiste na divisão dos programas em módulos, onde é possível a execução independente de cada módulo, todos utilizando a mesma memória principal;
    * Divisão feita em três módulos:
        * Principal: Módulo comum aos outros dois, sendo o maior e permanecendo na memória até o fim da execução do programa;
        * Cadastramento: É inpedentede, ou seja, não precisa ter o módulo de impressão na memória; 
        * Impressão: Possui as mesmas características do cadastramento.
        * OBS: O módulo de cadastramento e o de impressão, compartilham um espaço de memória, este nomeado espaço overlay.
    * É importante citar que toda a configuração e forma de uso da área de overlay é feita pelo programador. E sempre deve-se definir a área de overlay, pelo tamanho do módulo principal.
    * Esta técnica é utilizada no sistema de alocação estática.

* Swapping
    * Esta é uma técnica criada para o auxilio da gerência de memória, isso porque, todos os programas que estão sendo executados ou em espera estão em execução. Então o swapping pega os programas que estão na memória principal, e que tem menos chances de serem executados e envia para a memória secundário, normalmente um disco rígido.

* Loader
    * O loader permite que um programa seja alocado em qualquer posição da memória princípal, desta forma trabalha para servir o swapping, onde faz alocação dos programas presentes no swap.

#### Formas de alocação revistos na aula de hoje

- Best-fit
    -  Este é um algoritimo que busca o espaço para alocação que gere o mínimo possível de fragmentação, ou seja, utilize uma quantidade de memória que evita sobras;
    - Seu problema é que por alocar em espaços de memória do tamanho ou pouco superior ao que o programa necessita, pode gerar pequenos espaços na memória, que ficam subutilizados e são dificeis de serem alocados. Este problema ocorre a médio prazo;
    - Este formato de alocação, ordena a lista de memórias livres para verificar qual o menor espaço;
    - Por realizar a ordenação a alocação é mais simples.

- Worst-fit
    - Ao contrário do best-fit, este algoritimo busca alocar os programas em espaços onde irá sobrar mais espaços sendo subutilizados. Isso para evitar os problemas do best-fit de sobrar pequenos espaços que não poderão ser alocados
    - Também ordena as informações da memória para saber qual a maior disponível.

- First-fit
    -  Aqui a alocação é feita no primeiro espaço que de memória que o programa conseguir se encaixar. Sem utilizar critérios de sobrar espaços ou não;
    - Mais rápido que os demais;
    - Ordenação da lista memórias livres em ordem crescente.

### Atividades

- Correção dos exercícios do capitulo 9


### Exercícios de sala

* Descrever os algoritimos Best-fit, Worst-fit, First-fit
    * Exercício realizado presente no diretório <code>exe_sala</code>