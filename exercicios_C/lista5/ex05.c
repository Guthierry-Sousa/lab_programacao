#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencherVetor(float *vet, int tam);
void exibirVetor(float *vet, int tam);
float calcularErroQuadraticoMedio(float *vet1, float *vet2, int tam);

#define TAM 10
#define RG 10

int main(){

    srand(time(NULL));

    float vetor_A[TAM];
    float vetor_B[TAM];

    preencherVetor(vetor_A, TAM);
    preencherVetor(vetor_B, TAM);

    printf("Vetor A: \n");
    exibirVetor(vetor_A, TAM); 

    printf("\nVetor B: \n");
    exibirVetor(vetor_B, TAM); 

    float erro_quadratico_medio = calcularErroQuadraticoMedio(vetor_A, vetor_B, TAM);

    printf("Erro Quadratico Médio = %f\n", erro_quadratico_medio);

    return 0;
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
float calcularErroQuadraticoMedio(float *vet1, float *vet2, int tam){

    float erro = 0.0;

    for(int i = 0; i<tam; i++){

        float diff = (*(vet1+i) - *(vet2+i));

        erro += diff*diff;
    }

    return erro/ (float) tam;

}