#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLUMNS 4
#define ROWNS 4

#define RG 100


int main(){

    int matrix[ROWNS][COLUMNS];

    srand(time(NULL));

    for(int i = 0; i<ROWNS; i++){
        for(int j = 0; j<COLUMNS; j++){

            matrix[i][j] = rand() % RG; //[0,99]
        }
    }

    printf("Matriz gerada: \n");
    for(int i = 0; i<ROWNS; i++){
        for(int j = 0; j<COLUMNS; j++){

            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int limiar;

    printf("\nInforme um limiar: \n");
    scanf("%d", &limiar);
    
    for(int i = 0; i<ROWNS; i++){
        for(int j = 0; j<COLUMNS; j++){

            if(matrix[i][j]>limiar){
                matrix[i][j] = 1;
            }
            else{
                matrix[i][j] = 0;
            }
        }
    }
    printf("\nMatriz binarizada: \n");
    for(int i = 0; i<ROWNS; i++){
        for(int j = 0; j<COLUMNS; j++){

            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}