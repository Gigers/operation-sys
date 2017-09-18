/* 
    


*/


#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAXIMO 5

int fila[TAMANHO_MAXIMO];

int p = 0; // Primeiro
int u = 0; // Ultimo
int barbeiro = 0;

void sair(){
    if(p != u){
        fila[p++];
    }
}
void
barbeiroDorme(){
    
    if(p == u){
        printf("O barbeiro está dormindo\n");
        barbeiro = 0;
    } else {
        printf("O barbeiro está trabalhando\n");        
        barbeiro = 1;
    }
}

void
trabalha(){
    //Representa um processo
    
    int cont = 0;
    while(cont < u) {
        while(fila[cont] != 0){
            fila[cont] = fila[p] - 1;
        }
        sair();
        cont++;
    }
    barbeiroDorme();
}



void
verificaFila(int cliente){
    if(p == u){
        fila[p] = cliente;
    } else {
        fila[u++] = cliente;
    }
    trabalha();    
}

void
main(void){

    for(int i = 0; i < 3; i++){
        verificaFila(i + 2);
    }

}