# Aula 11-09-2017

* Compartilhamento de memória pode ser danoso, para isso algumas técnicas são utilizadas para evitar que problemas ocorram.
    * O primeiro deles é a exclusão mutua, que evita que multiplos processos escrevam na mesma região de memória, durante a sessão critica;
        * Sessão critica: Momento de uso de uma parte da memória por um processo.
    * Há também soluções de hardware e software para resolver estes problemas.

* Algoritimos para a aplicação da exclusão mutua:
    * Primeiro algoritimo:  
    * Segundo algoritimo:
    * Terceiro algoritimo: 
    * Quarto algoritimo:
    * Dekker: 
    * Peterson: 

* Para a próxima aula ler: Semáfaros 7.7 e Problema dos filósofos 7.7.3 e 7.7.4

# Deadlock

* Para que fique bem entendido, o Deadlock é o problema causado quando vários programas precisam dos recursos de outros processos para executar, um exemplo deste tipo de problema pode ser visto no problema dos filósofos

# Resumos da leitura

A seguir escrevo um pouco sobre cada um dos textos lidos

# Semáfaros

* É hoje uma das principais formas de aplcação de concorrência em sistemas operacionais;
* Sua implementação é feita através de uma variavél inteira, essas que são manipuladas por duas instruções o UP e o DOWN. A instrução UP incremente, enquanto a DOWN decrementa a variável;
* Quando a variavel chega a zero o processo entra em espera;
* São classificados em binários ou contadores. No caso dos binários, só podem assumir os valores 0 e 1, já os contadores, pode assumir qualquer valor positivo que não seja 0.

# Problema dos filósofos

* O problema dos filósofos apresenta uma ideia de que há 5 pratos na mesa, e 5 garfos. Essa mesa é utilizada pelos filosos para pensar e comer. No momento em que o filósofo para de pensar e vai comer, ele deve utilizar dois garfos, um de sua esquerda e outro de sua direita, o problema apresentado aqui é quando todos os filósofos querem comer, e cada um segura um garfo, porém ninguem come, pois para comer é necessários dois garfos. Com isso o famoso deadlock é ocasionado.

* Há algumas soluções para isso, veja:
    * Permitir que apenas quatro filosofos sentem a mesa;
    * Permitir que um filósofo pegue o garfo apenas se o outro estiver disponível;
    * Permitir que um filósofo impar pegue primeiro o seu garfo da direita, e em seguida, o da esquerda.

Links importantes: https://www.youtube.com/watch?v=6ql4YW1LHC8
                   https://www.youtube.com/watch?v=K2qpBEpMXmA

# Problema do barbeiro

* O problema do barbeiro é bastante simples, na barbearia, há uma quantidade N de cadeiras para clientes esperarem. Caso o barbeiro não tenha nenhum cliente, ele dorme até alguém aparecer.
* Se algum cliente chega e não há ninguem sendo atendido ele vai diretamente para o barbeiro, caso contrário ele fica na fila de espera, e se não houver cadeiras, o cliente vai embora.

* Semáforos binários -> barbeiro;
* Semáforos contador -> clientes;

O barbeiro executa DOWN no cliente, com o objetivo de escolher alguém a fazer o corte, caso não haja ninguem o barbeiro vai dormir. Caso haja cliente um UP é executado no barbeiro indicando que ele está trabalhando.

O cliente executa a Mutex espera, que permite verificar se todas as cadeiras estão ocupadas. Se isso ocorrer o cliente vai embora, realizando um UP no Mutex, caso contrário, a variavel espera é incrementada e o processo solicita recurso ao barbeiro através da instrução DOWN no semáfaro barbeiro (Mutex).

Links importantes: https://www.youtube.com/watch?v=6PH-M7qyRLo