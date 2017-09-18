# Aula - 04/09/2017

 * As threads são divididas em dois tipos:
    * Modo usuário;
        * Para chamar threads são utilizadas bibliotecas
    * Modo Kernel

O modo usuário acaba sendo mais rápido que o modo kernel, por ter menos passos envolvidos no processo.

# Threads

Em processos multi-threads o contexto de hardware pode ser entendido como:
  * Registradores.


# Exercícios

Atividades  1, 2, 3 - página 94

1 - Como uma aplicação pode implementar concorrência em um ambiente monothread ?

R: Com a utilização de processos pai e filhos, utilizando de interrupções.

2 - Quais os problemas de aplicações concorrentes desenvolvidas em ambientes monothreads ?

R: O processo de criação, troca e finalização acabam sendo mais demorados e complexos, com cada um sendo um processo diferente, tendo seus contextos de software e hardware diferentes, a mudança requer muito mais passos, o que as torna lentas.

3 - O que é um ambiente multithreads e quais são suas vantagens ?

R: Os ambientes multithreads conseguem compartilhar melhor os conextos de software, sendo um para todos os threads, diferenciando apenas o contexto de hardware, o que faz o processo ser mais rápido, e dinâmico, evitando problemas com complexidade.

4 - Explique a diferença entre unidade de alocação de recursos e unidade de escalonamento.

R:
* Escalonamento: Responsável em gerenciar e escalonar os recursos. Define quem será executado e em qual ordem será feita a execução.

* Alocação de recursos: Responsável em alocar os recusos dos processos, quando é necessário separar os contextos dos processos

5 - Quais as vantagens e desvantagens do compartilhamento do espaço de endereçamento entre threads de um mesmo processo ?

R: 

Vantagens: 

 * Os processos trabalham no mesmo contexto de software, compartilhando assim os recursos e permitindo melhor comunicação entre threads.

Desvantagem: 

 * Falta de proteção nas memórias compartilhadas. (Dependendo do bom trabalha do programador para fazer a segurança).

6 - Compare os threads em modo usuário e modo kernel

 Modo usuário (TMU):
 * Devem existir bibliotecas de rotinas para criação/eliminação de thread;
 * O sistema operacional não sabem da existência dos threads, sendo responsabilidade do programa gerênciar todas as threadas que cria; 
 * Permitem a criação de multithreads mesmo em sistemas operacionais que não tem suporte a thread em modo kernel;
 * O tem a limitação de que é, o sistema operacional encara todos os threads gerados como um grande monothread.

Modo kernel:
* São implementados diretamente pelo sistema operacional;
* O sistema operacional sabe de todos os processos, e cuida de seu escalonamento;
* Acaba se tornando lento por conta de todos os tratamentos, os threads em modo kernel acabam sendo mais lentos;
* Há comandos que permitem ao processo pedir para que um thread seja criado
