// Exercício - Escreva um programa em C que:

// Pergunte ao usuário quantos números inteiros ele deseja armazenar.
// Use malloc para alocar a memória necessária para armazenar esses números.
// Permita que o usuário insira os números.
// Calcule e exiba a soma de todos os números inseridos.
// Libere a memória alocada.

// Solução:

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr;
    int n;

    printf("Quantos números inteiros você deseja armazenar? ");
    scanf("%d", &n);

    // Alocação de Memória
    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    // Recebendo os números do usuário
    for (int i = 0; i < n; i++)
    {
        printf("Digite o número %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Exibindo os números inseridos
    printf("Os números digitados foram: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Calculando a soma
    int soma = 0;
    for (int i = 0; i < n; i++)
    {
        soma += arr[i];
    }

    // Exibindo a soma
    printf("A soma dos números é: %d\n", soma);

    // Liberando a memória alocada
    free(arr);

    return 0;
}