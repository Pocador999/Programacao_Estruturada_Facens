// Exercício - Escreva um programa em C que:

// Receba dois números inteiros do usuário.
// Use uma função para trocar os valores dos dois números.
// Exiba os números trocador após a chamada da função.

// Solução:

#include <stdio.h>

// Declaração da função para trocar os valores
void swap(int *a, int *b);

int main()
{
    int num1, num2;

    // Recebe dois números inteiros
    printf("Digite dois números inteiros: ");
    scanf("%d %d", &num1, &num2);

    printf("Números antes da troca: %d %d\n", num1, num2);

    // Chama a função para trocar os valores
    swap(&num1, &num2);

    printf("Números após a troca: %d %d\n", num1, num2);

    return 0;
}

// Implementação da função para trocar os valores
void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}