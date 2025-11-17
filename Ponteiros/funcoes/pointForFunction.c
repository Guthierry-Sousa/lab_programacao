// Um ponteiro para uma função contém o endereço da função na memória.
// Um nome de função é o endereço inicial na memória do código que realiza a tarefa da função

// - Programa de classificação de múltiplas finalidades usando ponteiros para função

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15
#define RANGE 10

void bubble(int *, const int, int (*compare)(int x, int y));
void inverter(int*, int*);
void gerarVetor(int *, const int);
void exibirVetor(int *, const int);
int crescente(int , int);
int decrescente(int, int);

int main(){

    srand(time(NULL));

    int order;
    int vetor[SIZE];


    printf("Vetor Gerado: \n");
    gerarVetor(vetor, SIZE);
    exibirVetor(vetor, SIZE);

    printf("Informe 1 para ordem crescente,\nInforme 2 para ordem decrescente: ");
    scanf("%d", &order);

    if(order == 1){
        printf("\nOrdem Crescente: \n");
        bubble(vetor, SIZE, crescente);
        
    }
    else{
        printf("\nOrdem Decrescente: \n");
        bubble(vetor, SIZE, decrescente);
        
    }
    exibirVetor(vetor ,SIZE);

    return 0;
}

void bubble(int *vetor, const int tam, int (*compare)(int x, int y)){

    int flag;

    for(int i = 0; i<tam-1; i++){

        flag = 1;

        for(int j = 0; j<tam-1-i;j++){

            if((*compare)(*(vetor+j), *(vetor+j+1))){
                inverter(vetor+j, vetor+j+1);
                flag = 0;
            }

        }
        if(flag) break;
    }

}

void gerarVetor(int *vetor, const int tam){

    for(int i = 0; i<tam; i++){
        *(vetor+i) = rand() % RANGE;
    }

}

void exibirVetor(int *vetor, const int tam){

    printf("\n");
    for(int i = 0; i<tam; i++){

        printf("%3d ", *(vetor+i));
    }
    printf("\n\n");

}

void inverter(int *elemento1, int *elemento2){

    int aux = *elemento1;
    *elemento1 = *elemento2;
    *elemento2 = aux;

}

int crescente(int x, int y){

    return x>y;
}
int decrescente(int x, int y){

    return x<y;
}