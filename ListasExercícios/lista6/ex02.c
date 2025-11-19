// Erro Médio Quadrático (MSE)
// Erro Absoluto Médio (MAE)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RG 10
#define LIMITE 1

void exibirVetor(int *, int);
void erroMedioQuadratico(int *, int *, int);
void erroAbsolutoMedio(int *, int *, int);
void preencherVetor(int *, int, void (*exibirVetor)(int*, int));

int main(int argc, char **argv){

    srand(time(NULL));

    void (*vetFunc[])(int *, int *, int) = {erroMedioQuadratico, erroAbsolutoMedio};

    if(argc != 3){
        printf("Use: %s <tamanhoVetor> <opçãoDeErro>\n", *argv);
        printf("<opçãoDeErro>: \n0 - Erro Médio Quadrático (MSE)\n1 - Erro Absoluto Médio (MAE)\n");
        exit(1);
    }

    int N = atoi(*(argv+1));
    int erroFunc = atoi(*(argv+2));

    if(erroFunc < 0 || erroFunc > LIMITE){
        printf("Opção Inválida\n");
        exit(2);
    }
    
    int *vetor_A = malloc(sizeof(int) * N);
    int *vetor_B = malloc(sizeof(int) * N);

    if(!vetor_A || !vetor_B){
        puts("Memória Indisponível.");
        exit(3);
    }

    preencherVetor(vetor_A, N, exibirVetor);
    preencherVetor(vetor_B,N, exibirVetor);

    (vetFunc[erroFunc])(vetor_A, vetor_B, N);

    return 0;
}

void exibirVetor(int *vet, int tam){

    printf("\n");

    for(int i = 0; i<tam; i++){

        printf("%4d ", *(vet+i));

    }

    printf("\n\n");
}

void erroMedioQuadratico(int *vetA, int *vetB, int tam){

    double mse;

    int somatorio = 0;

    for(int i = 0; i<tam; i++){

        somatorio += (*(vetA+i) - *(vetB +i)) * (*(vetA+i) - *(vetB +i));
    }

    mse = (double) somatorio/tam;

    printf("\nErro Quadrático Médio = %.3lf\n\n", mse);
}

void erroAbsolutoMedio(int *vetA, int *vetB, int tam){

    double mae;

    int somatorio = 0;

    for(int i = 0; i<tam; i++){

        int x = *(vetA+i) - *(vetB +i) >= 0 ? *(vetA+i) - *(vetB +i): - (*(vetA+i) - *(vetB +i));

        somatorio += x;
    }

    mae = (double) somatorio/tam;

    printf("\nErro Absoluto Médio = %.3lf\n\n", mae);
}

void preencherVetor(int *vet, int tam, void (*exibirVetor)(int *vet, int tam)){

    for(int i = 0; i<tam; i++){

        *(vet+i) = rand() % RG;
    }

    (exibirVetor)(vet, tam);

}