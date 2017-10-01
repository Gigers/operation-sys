## ROADMAP - Sistemas operacionais 

ROADMAP para prova de sistemas operacionais

### Leitura do livro - Arquitetura de Sistemas Operacionais 4ª Edição

Fazer a leitura dos seguintes capitulos

Capitulos
* Conceitos básicos;
* Conceitos de hardware e software;
* Concorrência;
* Estrutura do sistema operacional;
* Processos;
* Threads;
* Sincronização e comunicação entre processos;
* Gerência do processador.

### Exercícios

A leitura é importânte, porém para a fixação dos conceitos é necessário fazer todos os exercícios, abaixo vou listar os principais:

* Página 22 e 23 - Exercícios 4, 14, 18, 19 e 20;
* Página 39 - Exercícios 2, 6, 8 e 10;
* Página 62 - Exercícios 1, 2, 4, 5, 6 e 8;
* Página 84 - Exercícios (1, 2, 3), 4, (5, 6), 9;
* Página 84 - Exercícios 10, 11, 13, 14, 15;
* Página 94 - Exercícios 1, 2, 3;
* Página 152 - Exercícios 12 a 18.



### PARTE 1 Conceitos Básicos
  * O que é um Sistema Operacional ?
  
      Sistema Operacional, resumidamente é apenas um conjunto de rotinas executado pelo processador, podemos dizer que é semelhante aos programas dos usuários. Sua principal função é controlar o funcionamento de um computador, gerenciando a utilização e o compartilhamento dos seus diversos recursos, como processadores, memrias e dispositivos de entrada e saída
  * Tipos de Sistemas Operacionais
  
  * * Sistemas Monoprogramáveis / Monotarefa
 
      Foram os primeiros sistemas operacionais. São sistemas que pode-se executar apenas um programa por vez, para que outra aplicação fosse executada, deveria aguardar o término do programa corrente. Processador, memria e periféricos são de total exclusividade a execução de um único programa.
 Sua implantação é extremamente simples, não existindo preocupação no compartilhamento de recursos, tais como memória, processador e dispositivos E/S
         
  * * Sistemas Multiprogramáveis / Multitarefa
  
      Uma evolução dos antigos sistemas monoprogramáveis, aqui é diferente, os recursos computacionais são compartilhados entre aplicações e usuários. Enquanto um simples programa espera para ler ou gravar algo em disco, outros programas estão sendo processados no mesmo intervalo de tempo. O S.O se preocupa em gerenciar o acesso concorrente aos diversos recursos, de maneira ordenada e protegida. Suas vantagens: custo reduzido, redução total de tempo de execução dos programas. Desvantagens: mais complexo a implementação.
      
   * Ele pode ser dividido em três sistemas: batch, tempo compartilhado e tempo real.
   
   * * Sistema Batch:
   
      * Primeiros tipos de sistema operacionais multiprogramáveis. Os programas(jobs) eram submetidos para execução usando           cartes perfurados e armazenados em disco ou fita, sendo guardados para serem processados. Os jobs eram executados,           produzindo uma saída em disco ou fita.
        Ele não exige interação do usuário com a aplicação. Entradas e saídas de dados implementadas por memória                     secundária(geralmente arquivos em disco)
        Quando bem projetados são eficientes, já que utilizam melhor o processador, só que o tempo de resposta pode ser               longo.
        Exemplo de aplicações: envolvendo cálculos numericos, compilações, ordenações, backups e outros que não é necessário         o usuario.
  * * Sistemas de tempo compartilhado
  
      Os sistemas de tempo compartilhado, permitem que diversos programas sejam executados em pequenos intervalos definidos        pelo sistema operacional.
       Esta forma de trabalho é bastante utilizada pelas aplicações corporativas, por oferecerem tempo de resposta e execução        bons. Neste sistema, o usuário pode interagir com o sistema operacional, utilizando mouse, teclado e vídeo.
       Caso o tempo definido para uma aplicação não seja o suficiente, ela volta para a fila e outro processo entra em seu          lugar.
      
  * * Sistema em tempo real
  
      A forma de implementação de sistemas de tempo real, porém com a diferença que o tempo separado para a execução da     aplicação é feito de forma muito rígida, e não é finalizado a qualquer momento, para um possível novo calculo do tempo, como é feito com o tempo compartilhado.
 Aqui não existe a divisão do tempo, a aplicação pode levar o tempo que for necessário para rodar a aplicação, e todas as definições do tempo que será gasto, quais recursos serão utilizados, é definido pelo próprio programa que está executando, e  não pelo sistema operacional, assim como ocorre nos demais formatos citados acima.
 É um tipo de sistema muito utilizado em aplicações críticas, como usinas nucleares e controle de tráfego aéreo.
 
 * Sistemas com Múltiplos Processadores
 
     Os sistemas com múltiplos processadores são aqueles que tem dois ou mais processadores trabalhando em conjunto.
Esses permitem que muitas aplicações sejam executadas ao mesmo tempo e ou que uma mesma aplicação rode em diferentes processadores, porém neste caso a aplicação terá de ter o suporte a trabalhar desta forma.
Múltiplos processadores são utilizados nos meios científicos nos cálculos aeroespaciais, simulações entre vários outras áreas.
Os conceitos utilizados nestes sistemas são os mesmos encontrados nos sistemas multitarefas, e são esses:

* * Escalabilidade: Esta é a característica de conseguir aumentar  o poder computacional acrescentando processadores;
* * Disponibilidade: Com o trabalho sendo realizado com múltiplos processadores, caso algum deles venha a falhar, os demais ainda continuaram trabalhando normalmente;
Balanceamento de carga: É a capacidade de dividir o processamento entre os diversos processadores.

Ainda há uma divisão que é feita dentro dos sistemas com múltiplos processadores, essa classificação é feita de acordo com a forma de comunicação entre as UCPs presentes no hardware.

As divisões são feitas entre os sistemas fortemente acoplados e os fracamente acoplados.

 * * Sistemas fortemente acoplados

Os sistemas com múltiplos processadores fortemente acoplados são caracterizados por, várias UCPs dividindo uma única memória, dispositivos de E/S que são gerenciados tudo isso pelo mesmo sistema operacional. Os sistemas fortemente acoplados são divididos entre:
SMP - Tem tempo uniforme no acesso a memória;
NUMA - Sistemas que são conectados através de uma rede de interconexão.
Nestes dois sistemas todos os sistemas operacionais tem os mesmos problemas. 

 * * Sistemas fracamente acoplados

Os sistemas com múltiplos processadores fortemente acoplados são caracterizados pela forma independente de trabalho. São sistemas que são interligados, porém cada um com seu sistema operacional, estes podendo ser diferentes ou não. E cada um dos computadores ligados tem seu gerenciamento feito de forma diferente.

 * * Os sistemas fracamente acoplados são divididos em:

 * * SOR (Sistemas operacionais para redes) - Permitem que um host compartilhe seus recursos para as demais máquinas na rede;
 * * Sistemas distribuídos  - Nos SORs os hosts sabem que existem múltiplos host oferecendo serviços, já nos sistemas distribuídos, o sistema operacional mascara essa informação, fazendo com que mesmo que haja vários máquinas trabalhando, o sistema trabalha como se fosse apena um.
