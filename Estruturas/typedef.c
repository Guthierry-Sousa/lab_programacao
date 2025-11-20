// Typedef: Oferece um mecanismo de criação de sinônimos para tipos de dados previamente definidos.

// Criar um novo nome com typedef não cria um novo tipo; typedef simplesmente cria um novo nome de tipo.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cria o tipo de estrutura User sem a necessidade de uma instrução typedef separada.

typedef double reais;

typedef struct{

    char nome[20];
    int idade;
    reais salario;

} User;

int main(){

    User user1; // struct User user1;

    printf("Informe sua idade: \n");
    scanf("%d", &user1.idade);

    getchar();

    printf("Informe sua nome: \n");
    fgets(user1.nome, 20, stdin);

    user1.nome[strcspn(user1.nome, "\n")] = '\0';

    printf("Informe seu salário: \n");
    scanf("%lf", &user1.salario);

    printf("\n==== Dados do Usuário ==== \n");
    printf("\nNome: %s\nIdade: %d\nSalário: %.2lf\n", user1.nome, user1.idade, user1.salario);

    return 0;
}