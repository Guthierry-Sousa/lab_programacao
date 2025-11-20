// Estruturas são coleções de variáveis relacionadas agrupadas sob um único nome. Podem armazenar variáveis de muitos tipos de dados diferentes, diferentemente dos arrays.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declaração de estruturas - Não reservam nenhum espaço na memória.

// card -> identificador/tag da estrutura
// As variáveis declaradas dentro das chaves de declaração da estrutura são os membros da estrutura.
struct card{

    char *face;
    char *suit;

};

struct funcionario{

    char nome[20];
    char sobrenome[20];
    int idade;
    char sexo;
    double salario;

};

void preencherDados(struct funcionario *);
void exibirDados(struct funcionario *);
void removerQuebra(char *);

int main(){

    struct funcionario func1;

    preencherDados(&func1);
    exibirDados(&func1);

    return 0;
}

void preencherDados(struct funcionario *func){

    printf("Informe seu primeiro nome: ");
    fgets(func->nome, 20, stdin);
    removerQuebra(func->nome);

    printf("Informe seu Sobrenome: ");
    fgets(func->sobrenome, 20, stdin);
    removerQuebra(func->sobrenome);

    printf("Informe sua idade: ");
    scanf("%d", &func->idade);

    printf("Informe seu salário: ");
    scanf("%lf", &func->salario);

    printf("Informe seu sexo(M/F): ");

    getchar();

    func->sexo = getchar();
}

void exibirDados(struct funcionario *func){

    printf("\nNome: %s\n", func->nome);
    printf("\nSobrenome: %s\n", func->sobrenome);
    printf("\nIdade: %d\n", func->idade);
    printf("\nSexo: %c\n", func->sexo);
    printf("\nSalário: %.2lf\n", func->salario);
}

void removerQuebra(char *str){

    str[strcspn(str, "\n")] = '\0';
}