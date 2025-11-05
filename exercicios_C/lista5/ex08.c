#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLUMNS 4
#define ROWNS 4

#define RG 10

int main(){

    int matriz[ROWNS][COLUMNS];

    srand(time(NULL));
    for(int i = 0; i<ROWNS; i++){
        for(int j = 0; j<COLUMNS; j++){

            matriz[i][j] = rand()%RG;
        }
    }
    printf("Matriz gerada: \n");
    for(int i = 0; i<ROWNS; i++){
        for(int j = 0; j<COLUMNS; j++){

            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    int sum_diagonal = 0;

    for(int i = 0; i<ROWNS; i++){
        for(int j = 0; j<COLUMNS; j++){

            if(i==j){
                sum_diagonal += matriz[i][j];
            }
        }
    }

    if(sum_diagonal%2 == 0){
        printf("Somatório diagonal: %d | É Par!\n", sum_diagonal);
    }
    else{
        printf("Somatório diagonal: %d | É Ímpar!\n", sum_diagonal);
    }
    
    return 0;
}