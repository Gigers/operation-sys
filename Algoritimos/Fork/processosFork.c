/*
 Código por: Carlos Neto (A.K.A Carlinhos) - 3° Semestre ADS B
*/ 

#include <stdio.h>      //Biblioteca para a entrada e saida de dados
#include <sys/types.h>  //Biblioteca para possibilitar a execução do "fork()"
#include <unistd.h>     //Biblioteca para possibilitar a execução do "fork()"
#include <stdlib.h>     //Biblioteca para a declaração do exit()

int main(int argc, char const *argv[]) {

  int var_pid;
  int var_pid2;

  var_pid = fork();   /* A partir deste momento, há um processo PAI e um processo FILHO, (dois processos distintos em memoria)
                      porém, eles copiam para sua sua respectivas PCB, todos as variáveis anteriomente declaradas */
  int x=100;
  if(var_pid==0){
    x=11;
    printf("FILHO: \t PID: %d, var_pid: %d \n ", getpid(), var_pid );
    printf("\tEndereco de X: %p , Valor de X:%d\n\n", &x,x );

    var_pid2 = fork();

    if(var_pid2==0){
      printf("FILHO / FILHO: \t PID: %d , var_pid: %d \n ", getpid(), var_pid2);
      printf("\tEndereco de X: %p , Valor de X:%d\n\n", &x,x );
    }

    else {
      x=100;
      printf("FILHO / PAI: \t PID: %d , var_pid: %d\n", getpid(),var_pid2 );
      printf("\tEndereco de X: %p , Valor de X:%d\n\n", &x,x );
    }

  }

  else{
    printf("PAI: \t PID: %d, var_pid: %d\n", getpid(),var_pid );
    printf("\tEndereco de X: %p, Valor de X:%d\n\n", &x,x );
  }

}

/*  ou seja...
Quando PAI:
PID = (PID do pai)
VAR_PID = (PID do filho)

Quando FILHO:
PID=(PID do filho)
VAR_PID = 0
*/

/* Saída:
PAI: 	 PID: 12524, var_pid: 12525
FILHO: 	 PID: 12525, var_pid: 0

FILHO / PAI: 	 PID: 12525, var_pid: 12526
FILHO / FILHO: 	 PID: 12526, var_pid: 0
*/
