# 31/08/2017 - Cápitulo 5

# Processos com S.O Sim

* CPU-Bound
    * Processos que irão ficar mais tempo sendo executados.

* I/O bound
    * Processos que serão executados por curto prazo de tempo


# Questões

* Com base na observação do comportamento do processo criado, identifique se o processo é I/O-Bound ou CPU-bound. Justifique sua resposta

R: O processo é I/O-Bound quando espera as entradas e ou saídas para dispositivos como fitas ou discos, esses normalmente depois da execução vão para o estado de espera, para esperar a próxima I/O

O processo CPU-Bound, normalmente será executado por um tempo de normalmente será finalizado.

Analise os efeitos gerados no caso de redução do tempo gasto na operação de E/S pelo processo I/O-bound

R: Os processos CPU-bound ocupam mais tempo de processamento que os processos I/O-bound, isso porque os processos I/O-bound em boa parte de sua vida ele fica no estado <code>Em espera</code>.


# Threads

São processos mais leves, cada um tem seu contexto de hardware e todos usam o mesmo contexto de software.

Quando decidir que devo usar thread ou gerar um novo processo.


# Exercícios

10, 11, 13, 14, 15 - Página 84

10 - Dê um exemplo que apresente todas as mudanças de estado de um processo, juntamente com o evento associado a cada mudança.

R: 

Pronto -> Execução

Após o processo ser criado, o sistema operacional coloca todos os processo com estado <code>Pronto</code> em uma fila.

Execução -> Espera

Os processos que estão em execução passam para o estado em espera. Isso ocorre por conta de eventos gerados pelos próprios processos, esses podendo ser uma operação de I/O ou equivalente.

Espera -> Pronto

O processo passa de estado <code>Espera</code> para pronto quando os recursos os quais o processo precisa são cedidos a eles pelo sistema operacional.

Execução -> Pronto

Os processos passam de <code>Execução</code> para <code>Pronto</code> ocorre quando a fatia de tempo que o sistema operacional havia cedido para o processo chega ao fim, e com isso ele volta para a fila, para ser executado novamente.

11 - Deferencie processos multithreads, subprocessos e processos independentes.

Neste exercício o interessante é notar que multithreads, subprocessos e processos independentes são formas diferentes de implementar a concorrência

Processos independentes - São processos que ao serem criados não mantem um vínculo com seu criador, desta forma mantém contexto de software e hardware próprios

Subprocessos - Os subprocessos, são processos que ao serem criados seguem uma hierarquia, onde há um processo-pai e suas várias derivações. Aqui o contexto de hardware de cada um é separado e o contexto de software é utilizado um único para todos.

Processos multithreads - Threads foram criadas na tentativa de diminuir a quantidade de tempo gasto com os subprocessos (Criação de subprocesso, troca de contexto, eliminação de processos), com ele um único processo implementa a concorrência entre as várias threads que foram criadas.
As threads compartilham o processador da mesma maneira que um processo, porém em escala menor. Veja que cada thread representa um trecho ou função do programa que está sendo executado.

13 - Qual a relação entre processo e arquitetura microkernel ?

R: Para que exista os microkernels os serviços do sistema são disponibilizados através de processos, assim os dois estão diretamente relacionados.

14 - As aplicações CPU-Bound são as aplicações que ficam sendo executadas boa parte do tempo, como um navegador, ou outra aplicação como um programa de cálculo de matrizes. E os I/O-Bound, são aqueles que quase sempre estão no estado de espera, podendo citar o editor de texto, que nem sempre está sendo executado, por estar esperando operações de entrada.

15 - Justifique com um exemplo a frase "o sinal está para o processo assim como as interrupções e exceções estão para o sistema operacional"

R: Bem ao analisar esta frase se tem que, os sinais podem se assemelhar as interrupções, porém, há diferenças. No caso dos sinais, eles sinalizam o processo sobre alguma ação que será feita sobre eles, como por exemplo sua finalização, então neste caso, o processo recebe o bit em seu PCB, informando que o mesmo será excluido, e então no momento de sua execução isso ocorre. Diferente das interrupções que eram usadas para fazer a concorrência entre os processos.   
