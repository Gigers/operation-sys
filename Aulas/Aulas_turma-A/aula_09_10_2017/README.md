# Aula - 09/10/2017

* Principais componentes do sistema operacional:
    * 1° - Processador;
    * 2° - Memória.

## Gerência de memória

<!-- Introdução -->
### Introdução

A gerência de memória virtual é um assunto tratado a bastante tempo pelos projetistas de sistemas operacionais, pois, é necessário que o sistema utilize o mínimo de memória possível, e ainda, faça o gerênciamento desta da melhor forma possível.

Nos sistemas operacionais mais antigos, monoprogramaveis, a gerência de memória não era muito complexa, porém nos sistemas multiprogramaveis se tornou ponto critico para garantir que, o uso por muitos usuários e serviços não cause prejuízo ao desempenho.

<!-- Funções básicas -->
### Funções básicas
A gerência de memória tem muitas preocupações no momento da implementação e controle da memória. Abaixo será citado algumas das principais preocupações que há na gerência de memória.

Bem como é sabido, os programas ficam normalmente armazenados em dispositivos de memória secundários, por terem muita capacidade de armazenamento e serem não voláteis, mas, o processador executa apenas o que está na memória principal, fazendo com que o sistema operacional seja obrigado transferir os programas que serão executados para a memória principal, o que pode ser muito custoso.

O custo pode se dar principalmente pelo fato de, a memória secundária tem um tempo de acesso muito maior que a memória principal, desta forma o sistema deve evitar muitas requisições para a memória secundária, evitando uma grande quantidade de E/S, o que pode tornar o processo lento.

Com o problema mencionado acima a gerência de memória deve se preocupar em otimizar os programas residentes na memória principal, evitando as E/S. Este é um assunto que também abrange a alocação e disposição dos processos na memória, discutido mais a frente.

Outro grande problema que a gerência de memória deve levar em consideração é o controle de acesso aos endereços de memória, neste endereços de memória que alocam partes do sistema operacional, ou outros processos, precisam ter a certeza de que outros processos não façam o acesso, aumentando a segurança dos programas, e ao mesmo tempo, se necessário permitir o compartilhamento de um determinado espaço de memória entre os processos, isso também de forma segura.

Veja que além desta muitos outros problemas de memória são conhecidos, então é importante que se perceba, a importância e o quão crítico é a implementação desta parte do sistema operacional.

<!-- Alocação contígua simples -->
### Alocação contígua simples
Esta é a implementação de alocação de memória utilizada nos primeiros sistemas operacionais, mas, pode ser encontrado em certos sistemas ainda hoje. 

Sua implementação é bastante simples, e de código reduzido, porém apresenta algumas falhas fundamentais.

Para entender as falhas vejamos como funciona a <code>alocação contígua simples</code>. Básicamente a memória é dividida em duas partes, uma parte para o sistema operacional e outra para os programas do usuário.

Agora vamos aos problemas. Primeiro, não é uma forma otimizada de trabalhar, pois caso um programador crie um programa que não faça toda a utilização do espaço de memória, não será possível alocar naquele espaço gerando memória sub-utilizada.

Outro ponto é que nesta implementação o usuário tem acesso a todos os endereços de memória, inclusive, aos endereços do sistema operacional, o que pode ser desastroso caso algum programa faça o acesso consciente ou inconscientemente. Algumas implementações fazem o uso de um registrador para controlar o acesso, neste cada acesso é verificado, para que seja feito a verificação do acesso ou não a endereços onde estão alocados o sistema operacional.

E por fim, os programas estão limitados ao tamanho da memória principal (Que tem uma quantidade de limite baixa se comparada a outros compontentes do computador, como a memória secundária)

### Overlay

<!-- Melhorar o detalhamento -->

Técnica onde o programa é dividido em módulos para que seja possível a execução independente de cada módulo, utilizando uma mesma área de memória.

OBS: Entenda a independência citada acima como, os módulos podem estar na memória sem a necessidade de outro módulo.

Pense em um programa que é dividido em três módulos, o principal, um módulo de cadastro, e outro de impressão, o único módulo comum aos dois outros é o principal, que sempre deverá se manter na memória, os demais poderão entrar e sair sem que os dois esteja na memória.

Com o cenário acima, caso se tenha uma quantidade limita de memória para a alocação do programa todo, é possível (Além do módulo principal) alocar apenas o módulo que será utilizado.

Vale lembrar que a definição do tamanho da área de overlay deve ser feita pelo programador. Normalmente o tamanho da área de overlay é dado pelo tamanho do maior módulo, assim, caso o módulo de cadastro tenha 4Kb, e o de impressão 2Kb, o tamanho da área de overlay terá 4Kb.

Esta é uma técnica que permite ao programador criar programas que não fiquem limitados ao tamanho da memória principal, porém deve ser feito com bastante cuidado, já que a má implementação desta técnica pode trazer problemas de desempenho do programa (Por conta de transferências excessivas) e manutenção do código.

Área de overlay: Área de memória que será compartilhada entre os módulos do programa.

### Alocação particionada

A evolução dos sistemas operacionais trouxeram muitas mudanças, principalmente na otimização do uso dos recursos. No inicio se tinha a sub utilização da memória (Por conta das forma de alocação) e do uso de processador que era feito de uma forma a trazer muito mais tempo ocioso do que de trabalho, porém a evolução dos sistemas multiprogramaveis fizeram com que seja necessários vários programas sendo executados ao mesmo tempo e muitos deles alocado na memória.

Como o sistema operacional distribui as memórias para os demais programas ? Conteúdo da página 59

Utiliza-se duas estratégias:

* Alocação particionada estática:
    * Utilizado pelos primeiros programas multiprogramados;
    
    * Todas as técnicas citadas abaixo, usam espaços fixos separados na memória (Partições)

        * <code>Alocação particionada estática ou fixa</code>:
            * Tamanho de partições de memória feitas na inicialização do sistema;
                * Se alguma alteração fosse necessária, esta seria feita através da reinicialização da máquina.
        
        * <code>Alocação particionada estática absoluta</code>:
            * Refere-se a técnica de gerência de memóra onde os endereços de memória utilizados pelo programa eram específicados pelo programador, o que limitava muito a gerência pelo sistema operacional, e ainda, não permitia uma melhor alocação (Disposição em uma partição vazia com mais espaço por exemplo), pois os endereços utilizados serão sempre os mesmos (Os programas ficam sempre na mesma partição);
            * Os endereços absolutos eram endereços diretos da memória principal;
            * Causava sub utilização, já que, ao utilizar endereços absolutos, caso o endereço estiver em uso, não é possível fazer remanejamento para outro espaço da memória.

        * <code>Alocação particionada estática relocável</code>:
            * Endereços deixaram de ser absolutos;
            * Todos os endereços passaram ser relativos ao inicio do código;
            * O <code>loader</code> cálcula todos os endereços de memória a partir do endereço em que o programa foi carregado.
   
    * Para manter o controle sobre quais partições estão alocadas, a gerência de memória mantém uma tabela com o endereço inicial de cada partição, seu tamanho, e se está em uso.
    * Proteção baseada em dois registradores, esses que delimitam quais serão os pontos de memórias (Inferior e superior) que serão utilizadas pelo programa, e caso o programa vá além deste limite ele será interrompido e um erro de violação de memória é exibido;
    * Neste formato de alocação de memória, hávia o problema da fragmentação, onde os programas não usavam todo o espaço disponível para ele (Partição), conhecido como fragmentação interna.

        * Problema ocorre principalmente por fazer a divisão da memória em partições de tamanhos fixos, assim programas pequenos podem ser colocados em partições grandes, o que gera a fragmentação;
    
        * Outro problema é que apenas um programa é permitido em cada partição, desta forma, completando o que foi dito acima, mesmo que não ocupe todo o espaço, este não poderá ser dividido.

* Dinâmica:
    * Não há espaços pré-definidos;
    * Cada programa utiliza o espaço que for necessário;
    * Não há o problema de fragmentação interna;
        * Porém gerou a framentação externa.
    * Para a solução da fragmentação externa há duas técnicas:
        * Na primeira, as memórias adjacentes ao programa que foi finalizado se juntam para criar espaços de memória livre maior;
        * Na segunda técnica, os programas são relocados, todos eles são movidos para áreas novas na memória, liberando assim todo espaço que está sendo subutilizado. (Conhecido também como partição dinâmica com relocação);
            * É problemático por ser bastante complexo;
            * O sistema deve implementar relocação dinâmica.
    
    * Estratégias de alocação de partição (Página: 165)
    Para realizar a implementação da alocação dinâmica existem três técnicas, e são elas:
        
        * Best-fit:
            * A partição escolhida para alocar o programa é a que irá deixar menos quantidade de espaço sendo subutilizado;
            * As áreas estão ordenadas por tamanho, o que faz a busca ser mais simples;
            * Problema é: Em médio prazo só haverá espaços pequenos, dificil de alocar (Aumenta o problema da fragmentação);
        
        * Worst-fit:
            * Aloca sempre nos maiores espaços, ou seja, nas piores memórias;
            * Ao alocar sempre nos maiores espaços de memórias disponíveis, deixa muitos espaços de memórias livres, evitando o problema de framentação.
        
        * First-fit:
            * Primeiro que entra no espaço e encaixa serve;
            * Mais rápida que as duas citadas anteriormente;
            * Ordenada as memórias em ordem crescente;
            * Consome menos recursos do sistema.

### Swapping

O <code>swapping</code> é uma técnica para o auxilio de gerência de memória, criado para resolver o problema de insuficiência de memória principal. Veja que todo programa, ele estando em espera, ou execução, está alocando memória, e isso em ambientes com poucos recursos de memória pode ser um problema, assim para resolver este problema, o swap pega os programas que estão na memória principal em espera, que tem poucas chances de serem executados e envia eles para a memória secundária (Normalmente o disco rigido). E quando ele for executado, volta para a memória principal normalmente.

* Característica:
    * Memória de troca;
    * Utilizada para contornar o problema da falta de memória principal;
    * Técnica aplicada a programas que estão esperando por espaços na memória para serem executados;
    * Esta técnica existe para ajudar na gerência de memória, e como dito acima, é aplicada aos programas que estão em espera porque até eles ocupam espaço na memória principal
    * A técnica pega o programa que tem a menor chance de ser executado e está na memória principal e coloca ele na memória secundária, e quando for necessário sua execução, volta ele para o disco.
    * Swap out: Tiro da memória e coloco no disco;
    * Swap in: Tipo do disco e passa para a memória.

Para implementar esta técnica é necessário que o sistema operacional ofereça um <code>loader</code> com a capacidade de relocação dinâmica, caso não tenha, o programa será realocado apenas no momento do carregamento.

Seu grande problema, é a quantidade de operações de E/S feitas por conta do processo de retirar e inserir processos na memória, em casos em que há pouca memória, pode ocorrer de o sistema operacional ficar trabalhando apenas para <code>swapping</code> e não executar os programas.

### Hiberfil.sys
Arquivo usado pelo Windows como swap na memória

### Exercícios

* 1 - Gerênciar os espaços de memória utilizados pelos programas, realizar otimização dos processos que estão alocados na memória, bem como a proteção e controle de acesso aos endereços de memória, assim evitando problemas de segurança. 
Por fim deve-se levar em consideração que a gerência de memória deve gerênciar os compartilhamentos de memória entre os processos e garantir que estes serão feitos de maneira segura. 

* 2 - Está sendo subutilizado 1/4 da memória, isso porque apenas 30 Kb está sendo utilizado sobrando 10 Kb

    * Informações (Alocação contigua):
        * Espaço total: 40 Kb;
        * Sistema operacional 10 Kb;
        * Programa: 20 Kb;
        * Total: 30 Kb sendo usado, ou seja, 10 Kb (1/4) estão sem uso algum. 

* 3 -
    Com as informações passadas pelo exercício, o programa irá iniciar e trabalhar com um módulo de cada vez utilizando um espaço de memória de 30 Kb (Área de overlay)

    * Informações (Alocação contigua)
        * Espaço total: 64 Kb;
        * Sistema operacional: 14 Kb;
        * Programa: 90 Kb
            * Módulo principal: 20 Kb;
            * Módulo 1: 10 Kb;
            * Módulo 2: 20 Kb;
            * Módulo 3: 30 Kb;
        * Enquanto o programa existir será executado: 34 Kb (S.O + Módulo principal)

* 4 - O programa não poderá ser executado, o que poderia ser feito o módulo de 40 Kb poderia ser reduzido pelo programador em outros dois módulos, caso contrário não será possível executar o programa

* 5
    * Interna: Problema que ocorre nas partições, onde o sistema operacional define partições de tamanho fixo que podem não ser utilizados pelo programa, gerando assim fragmentação interna;
    * Externa: Ocorre em espaços cada vez menores na memória, difíceis de serem alocados, gerando fragmentação externa.

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