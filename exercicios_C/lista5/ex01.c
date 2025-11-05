#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 11
#define RG 20

void preencherVetor(int *vet, int tam);
void exibirVetor(int *vet, int tam);
int *retornarEndereco(int* vet, int tam);


int main(){

    srand(time(NULL));

    int vetor[TAM];

    preencherVetor(vetor, TAM);
    exibirVetor(vetor,TAM);

    int *point = retornarEndereco(vetor, TAM);

    if(point){
        puts("Primeiro elemento par do vetor: ");
        printf("Elemento: %d - Endereço: %p\n", *point, point);
    }
    else{
        puts("Vetor não possui números pares.");
    }

    return 0;
}

void preencherVetor(int *vet, int tam){

    for(int i = 0; i<tam; i++){

        *(vet+i) = rand() % RG;
    }
}

void exibirVetor(int *vet, int tam){

    for(int i = 0; i<tam; i++){

        printf("vetor[%d] = %d | Endereço: %p\n", i, *(vet+i), vet+i);
    }
}
int *retornarEndereco(int* vet, int tam){

    for (int i = 0; i < tam; i++)
    {
        if(*(vet+i)%2 == 0){

            return vet+i;

        }
    }

    return NULL;
}