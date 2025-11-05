#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10
#define RG 10

void somarElementosVetor(float *vet, int tam, float *sum);
void preencherVetor(float *vet, int tam);
void exibirVetor(float *vet, int tam);

int main(){

    float vetor[TAM];
    srand(time(NULL));

    preencherVetor(vetor, TAM);
    printf("Vetor Gerado: \n\n");
    exibirVetor(vetor, TAM);

    float somatorio = 0.0;

    somarElementosVetor(vetor, TAM, &somatorio);

    printf("\nSomatório = %f\n", somatorio);

    return 0;
}

void somarElementosVetor(float *vet, int tam, float *sum){

    for(int i = 0; i<tam; i++){

        *(sum) += *(vet+i);
    }
}
void preencherVetor(float *vet, int tam){

    for(int i = 0; i<tam; i++){
        *(vet+i) = ((float) rand() / RAND_MAX) * RG;
    }
}
void exibirVetor(float *vet, int tam){
    for(int i = 0; i<tam; i++){
        printf("vetor[%d] = %f\n", i, *(vet+i));
    }
}