# Aula - 18/09/2017

# Sistemas preemptivos 


# Sistemas Não-preemptivos

* Sistemas que não conseguem parar no meio da execução de processos para executar outros;
* Um exemplo são os sistemas Batch;

# Deadlock

* Problema que ocorre quando todos os processos estão esperando algum recurso que está sendo utilizado por outro processo

# Starvation

* Processo que nunca entra em execução por falta de disponibilidade de recursos.

# Algoritimos de escalonamento de processos

* Shortest job first (SJF):
    * Resolve quem é menor primeiro;

* Circular:
    * O escalonamento circular utiliza do conceitos de filas para trabalhar, porém neste caso o conceito de tempo é aplicado, ou seja, cada processo tem uma fatia de tempo para ser executada, e caso expire, o processo volta para o final da fila.
* Prioridades:
    * Este é um escalonamento que realiza as decisões com base no valor da prioridade de execução , o processo com maior prioridade na fila para a execução sempre é o primeiro a ser escolhido.
    * Caso haja escalonamento entre processos de mesma prioridade, o que irá valer será quem está na fila a mais tempo.
* Circular com prioridade:
    * Este escalonamento implementa os conceitos do circular e de prioridade. Porém nesta forma de escalonamento o processo fica em execução até que termine seu processamento, passe para o estado de espera ou sofra uma preempção por tempo ou prioridade.


Continuação na próxima aula