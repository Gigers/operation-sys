/*
    Felipe Menino Carlos
    3° ADS - Turma A
    
    compile: gcc semafaro.c -pthread
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MEMORIA_MAX 5

void down(int recurso);
void up();
void * processo_a();
void * processo_b();
void * processo_c();

// Fila de espera dos processos
int fila_espera[MEMORIA_MAX];

// Auxs da fila
int p = 0;
int u = 0;

// Variável do semaforo
int s = 1;

void
down(int recurso){

    if(s == 0){

        printf("O processo terá de esperar\n");

        fila_espera[u++] = recurso;   

    } else {

        s = s - 1;        

    }
}

void
up(){

    s = s + 1;
    
    if(p != u) {

        fila_espera[p++];

    }
}

void *
processo_a(){

    down(123);
    printf("O processo A está sendo executado\n");

    sleep(5);        

    up();

}

void *
processo_b(){

    down(321);

    printf("O processo B está sendo executado\n");
    sleep(5);

    up();

}

void *
processo_c(){

    down(123321);

    printf("O processo C está sendo executado\n");
    sleep(5);

    up();

}


void
main(void){

    // Define thread
    pthread_t thr_1;
    pthread_t thr_2;
    pthread_t thr_3;


    // Cria threads
    pthread_create(&thr_1, NULL, processo_a, NULL);
    pthread_create(&thr_2, NULL, processo_b, NULL);
    pthread_create(&thr_3, NULL, processo_c, NULL);

    // Acompanho os retornos do processo
    pthread_join(thr_1, NULL);
    pthread_join(thr_2, NULL);
    pthread_join(thr_3, NULL);
}