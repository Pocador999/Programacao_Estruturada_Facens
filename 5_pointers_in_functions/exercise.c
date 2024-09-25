// Exercício - Escreva um programa em C que:

// Receba três números inteiros do usuário.
// Use uma função para encontrar o maior número entre os três, utilizando ponteiros.
// Exiba o maior número após a chamada da função.

// Solução:

#include <stdio.h>

// Função para encontrar o maior número entre três
int findMax(int *a, int *b, int *c);

int main()
{
    int num1, num2, num3;

    // Entrada dos três números
    printf("Digite três números inteiros: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    // Exibe o maior número
    printf("O maior número é: %d\n", findMax(&num1, &num2, &num3));

    return 0;
}

// Função que retorna o maior número
int findMax(int *a, int *b, int *c)
{
    if (*a >= *b && *a >= *c)
        return *a;
    else if (*b >= *a && *b >= *c)
        return *b;
    else
        return *c;
}
