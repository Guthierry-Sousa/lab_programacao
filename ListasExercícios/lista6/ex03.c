// Erro Médio Quadrático (MSE)
// Erro Absoluto Médio (MAE)

// Exercício 02, mas com uma função de gerar números aleatório diferente.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265359
#define RG 10
#define LIMITE 1

void gerarAleatorios(double *, double (*func_rand)(void), int);
double meu_rand();

void exibirVetor(double *, int);
void erroMedioQuadratico(double *, double *, int);
void erroAbsolutoMedio(double *, double *, int);
void calcularErro(double *, double *, int , void (*funcaoErro)(double *, double *, int));

int main(int argc, char **argv){

    srand(time(NULL));

    void (*vetFunc[])(double *, double *, int) = {erroMedioQuadratico, erroAbsolutoMedio};

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
    
    double *vetor_A = malloc(sizeof(double) * N);
    double *vetor_B = malloc(sizeof(double) * N);

    if(!vetor_A || !vetor_B){
        puts("Memória Indisponível.");
        exit(3);
    }

    printf("Vetor A:\n");
    gerarAleatorios(vetor_A,&meu_rand, N);
    exibirVetor(vetor_A, N);

    printf("Vetor B:\n");
    gerarAleatorios(vetor_B,&meu_rand, N);
    exibirVetor(vetor_B, N);

    calcularErro(vetor_A,vetor_B, N, vetFunc[erroFunc]);

    free(vetor_A);
    free(vetor_B);

    return 0;
}

void exibirVetor(double *vet, int tam){

    printf("\n");

    for(int i = 0; i<tam; i++){

        printf("%lf ", *(vet+i));

    }

    printf("\n\n");
}

void erroMedioQuadratico(double *vetA, double *vetB, int tam){

    double mse;

    double somatorio = 0;

    for(int i = 0; i<tam; i++){

        somatorio += (*(vetA+i) - *(vetB +i)) * (*(vetA+i) - *(vetB +i));
    }

    mse = somatorio/tam;

    printf("\nErro Quadrático Médio = %.3lf\n\n", mse);
}

void erroAbsolutoMedio(double *vetA, double *vetB, int tam){

    double mae;

    double somatorio = 0;

    for(int i = 0; i<tam; i++){

        double x = *(vetA+i) - *(vetB +i) >= 0 ? *(vetA+i) - *(vetB +i): - (*(vetA+i) - *(vetB +i));

        somatorio += x;
    }

    mae = somatorio/tam;

    printf("\nErro Absoluto Médio = %.3lf\n\n", mae);
}

void calcularErro(double *vetA, double *vetB, int tam, void (*funcaoErro)(double *, double *, int )){

    printf("\nCálculo do Erro\n");

    (funcaoErro)(vetA, vetB, tam);

    printf("\n-------------------------------\n");
}

void gerarAleatorios(double *vet, double (*func_rand)(void), int quantidade){


    for(int i = 0; i<quantidade; i++){

        *(vet+i) = func_rand();

    }

}

// Distribuição Gaussiana
double meu_rand(){

    double u1 = (double) rand() / RAND_MAX;
    double u2 = (double) rand() / RAND_MAX;

    double x = sqrt(-2 * log(u1)) * cos(2 * u2 * PI);

    return x;

}