/* 
    Programa que demonstra como criar thread

    Compilar utilizando gcc cria_thread.c -pthread

    Código feito com a ajuda de: Aleteia blog
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *
processo(){

    printf("Processo criado\n");
    sleep(5);
}

void
main(void) {

    // Cria corpo das threads
    pthread_t processo_A;
    pthread_t processo_B;
    
    // Criando a thread
    // Parametros do pthread_create
    // 1° - Referência o corpo da thread criado
    // 2° - Atributos
    // 3° -  Função que será executada
    // 4° - Argumentos para a função chamada
    pthread_create(&processo_A, NULL, processo, NULL);
    pthread_create(&processo_B, NULL, processo, NULL);

    pthread_join(processo_A, NULL);
    pthread_join(processo_B, NULL);

}