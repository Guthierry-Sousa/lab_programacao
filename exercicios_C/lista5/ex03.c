#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10
#define RG 10

void preencherVetor(int *vet, int tam);
void exibirVetor(int *vet, int tam);
void exibirVetorNormalizado(float *vet, int tam);

int* getMenorValor(int *vet, int tam);
int* getMaiorValor(int *vet, int tam);

void normalizar(int *vet, float* vet_normalizado, int *maior, int *menor ,int tam);

int main(){

    srand(time(NULL));
    
    int vetor[TAM];

    preencherVetor(vetor, TAM);
    exibirVetor(vetor, TAM);

    int *max = getMaiorValor(vetor, TAM);
    int *min = getMenorValor(vetor, TAM);

    printf("\nMax = %d\n", *max);
    printf("\nMin = %d\n", *min);

    float x[TAM];

    printf("\n\n");

    normalizar(vetor, x, max, min, TAM);
    exibirVetorNormalizado(x, TAM);

    return 0;
}

void preencherVetor(int *vet, int tam){
    for(int i = 0; i<tam; i++){
        *(vet+i) = rand() % RG;
    }
}
void exibirVetor(int *vet, int tam){
    for(int i = 0; i<tam; i++){
        printf("vetor[%d] = %d\n", i, *(vet+i));
    }
}
void exibirVetorNormalizado(float *vet, int tam){
    for(int i = 0; i<tam; i++){
        printf("vetor[%d] = %f\n", i, *(vet+i));
    }
}
int* getMenorValor(int *vet, int tam){

    int *menor = vet;

    for(int i = 1; i<tam; i++){

        if(*(vet+i) < *(menor)){

            menor = vet+i;

        }

    }
    return menor;
}
int* getMaiorValor(int *vet, int tam){

    int *maior = vet;

    for(int i = 1; i<tam; i++){

        if(*(vet+i) > *(maior)){

            maior = vet+i;
        }
    }
    return maior;
}
void normalizar(int *vet, float* vet_normalizado, int *maior, int *menor ,int tam){

    for(int i = 0; i<tam; i++){

        *(vet_normalizado+i) = (float) (*(vet+i) - *menor)/(*(maior) - *(menor));

    }
}