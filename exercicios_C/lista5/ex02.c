#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10
#define RG 20

void preencherVetor(int *vet, int tam);
void exibirVetor(int *vet, int tam);
int *retornarEnderecoMenorPar(int* vet, int tam);
int *retornarEnderecoMaiorPar(int* vet,int tam);


int main(){

    srand(time(NULL));

    int vetor[TAM];

    preencherVetor(vetor, TAM);
    exibirVetor(vetor,TAM);

    int *point_pares[2];

    *point_pares = retornarEnderecoMenorPar(vetor, TAM);
    *(point_pares+1) = retornarEnderecoMaiorPar(vetor, TAM);

    printf("\nPrimeiro elemento par: %d | Endereço: %p\n", **point_pares, *point_pares);

    printf("\nÚltimo elemento par: %d | Endereço: %p\n", **(point_pares+1), *(point_pares+1));

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
int *retornarEnderecoMenorPar(int* vet,int tam){

    for (int i = 0;i <tam; i++)
    {
        if(*(vet+i)%2 == 0){
            
            return vet+i;

        }
    }
}
int *retornarEnderecoMaiorPar(int* vet,int tam){

    for (int j = tam-1; j>=0; j--)
    {
        if(*(vet+j)%2 == 0){
            
            return vet+j;

        }
    }
}