// Uso de estruturas com funções;

// - Para passar uma estrutura por referência, passe o endereço da variável da estrutura.

// - Quando as estruturas ou membros individuais da estrutura são passados a uma função, eles são passados por valor.

// Os arrays são automaticamente passados por referência, para passar um array por valor, crie uma estrutura que tenha o array como membro.

#include <stdio.h>

struct exemplo{

    int array[20];

};

void alterarElemento(struct exemplo);

int main(){

    struct exemplo arrayValor;

    // Preencher Array
    for(int i = 0; i<20; i++){

        arrayValor.array[i] = 20; 

    }

    // Exibir Array

    for(int i = 0; i<20; i++){

        printf("%d  ",arrayValor.array[i]);

    }

    alterarElemento(arrayValor);

    // Elemento não é modifica, pois como as estruturas são passadas por valor, o rray que está como membre tambem é passado por valor.
    printf("\nElemento 1 = %d\n", arrayValor.array[1]);

    return 0;
}

void alterarElemento(struct exemplo vet){

    vet.array[1] = 10;

}