#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5
#define RG 10

void preencherVetor(int *vet, int tam);
void exibirVetor(int *vet, int tam);
void calcularMedia(int *vet, int tam, float *mean);
void calcularMediana(int *vet, int tam, float *median);
void calcularModa(int *vet, int tam, int *moda);

int main(){

    srand(time(NULL));

    int vetor[TAM];
    float media = 0.0;
    float mediana = 0.0;
    int moda;

    preencherVetor(vetor, TAM);
    exibirVetor(vetor, TAM);
    calcularMedia(vetor, TAM, &media);
    calcularMediana(vetor, TAM, &mediana);
    calcularModa(vetor, TAM, &moda);

    printf("\nMédia = %f\n\n", media);
    printf("\nMediana = %f\n\n", mediana);
    printf("\nModa = %d (pode ocorrer mais de uma moda)\n\n", moda);

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

void calcularMedia(int *vet, int tam, float *mean){

    int somatorio = 0;

    for(int i = 0; i<tam; i++){

        somatorio += *(vet+i);
    }

    *mean = (float) somatorio/tam;

}

void calcularMediana(int *vet, int tam, float *meadian){

    if(tam % 2 == 0){
        *meadian = (float) (*(vet + (tam/2)) + *(vet + ((tam/2) - 1))) / 2;
    }
    else{
        *meadian = (float) (*(vet + (tam/2)));
    }

}

void calcularModa(int *vet, int tam, int *moda){

    int max_frequencia = 0;

    for(int i = 0; i<tam; i++){

        int frequencia_atual = 0;

        for(int j = 0; j<tam; j++){

            if(*(vet+j) == *(vet+i)){
                frequencia_atual++;
            }
        }
        if(frequencia_atual>max_frequencia){

            max_frequencia = frequencia_atual;

            *moda = *(vet+i);
        }
    }
}