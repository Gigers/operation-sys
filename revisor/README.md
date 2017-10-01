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



# PARTE 1 Conceitos Básicos
  * O que é um Sistema Operacional ?
     * Sistema Operacional, resumidamente é apenas um conjunto de rotinas executado pelo processador, podemos dizer que é semelhante aos programas dos usuários. Sua principal função é controlar o funcionamento de um computador, gerenciando a utilização e o compartilhamento dos seus diversos recursos, como processadores, memrias e dispositivos de entrada e saída
  * Tipos de Sistemas Operacionais
  
  * * Sistemas Monoprogramáveis / Monotarefa
  
       * Foram os primeiros sistemas operacionais. São sistemas que pode-se executar apenas um programa por vez, para que outra aplicação fosse executada, deveria aguardar o término do programa corrente. Processador, memria e periféricos são de total exclusividade a execução de um único programa.
         Sua implantação é extremamente simples, não existindo preocupação no compartilhamento de recursos, tais como memória, processador e dispositivos E/S
         
  * * Sistemas Multiprogramáveis / Multitarefa
  
      * UMa evolução dos antigos sistemas monoprogramáveis, aqui é diferente, os recursos computacionais são compartilhados entre aplicações e usuários. Enquanto um simples programa espera para ler ou gravar algo em disco, outros programas estão sendo processados no mesmo intervalo de tempo. O S.O se preocupa em gerenciar o acesso concorrente aos diversos recursos, de maneira ordenada e protegida. Suas vantagens: custo reduzido, redução total de tempo de execução dos programas. Desvantagens: mais complexo a implementação.
      
   * Ele pode ser dividido em três sistemas: batch, tempo compartilhado e tempo real.
   
   * Sistema Batch:
      * Primeiros tipos de sistema operacionais multiprogramáveis. Os programas(jobs) eram submetidos para execução usando cartes perfurados e armazenados em disco ou fita, sendo guardados para serem processados. Os jobs eram executados, produzindo uma saída em disco ou fita.
       Ele não exige interação do usuário com a aplicação. Entradas e saídas de dados implementadas por memória secundária(geralmente arquivos em disco)
       Quando bem projetados são eficientes, já que utilizam melhor o processador, só que o tempo de resposta pode ser longo.
       Exemplo de aplicações: envolvendo cálculos numericos, compilações, ordenações, backups e outros que não é necessário o usuario.
  * Sistemas de tempo compartilhado
  
