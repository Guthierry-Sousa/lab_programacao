#include <stdio.h>
#include <stdlib.h>

// - Operador de membro da estrutura(.): Acessa um membro da estrutura por meio do nome da variável da estrutura.

// - Operador de ponteiro de estrutura(->): Acessa um membro da estrutura por meio de um ponteiro para estrutura.

// Operador (.) tem maior precedência em relação ao operador de desreferência (*).

struct dados{

    char nome[20];
    int idade;

};

int main(){

    struct dados user1 = {"Guthierry", 18};

    struct dados *pDados = &user1;

    // Operador de ponto(.) 
    printf("Nome = %s\n", user1.nome);
    printf("Idade = %d\n", user1.idade);

    // Operador de seta(->) - Equivalente a (*pDados).nome ou .idade, que desreferencia o ponteiro e acessa os membros nome e idade usando o operador de mombro da estrutura.
    printf("\nNome = %s\n", pDados->nome);
    printf("Idade = %d\n", pDados->idade);

    return 0;
}