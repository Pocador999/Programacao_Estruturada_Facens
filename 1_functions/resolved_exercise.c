// Problema: Escreva um programa que pergunte ao usuário quantos números ele deseja armazenar,
// use malloc para alocar a quantidade necessária de memória e,
// em seguida, permita que o usuário insira os números. Por fim, exiba esses números.

// Solução:

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr; // Ponteiro para armazenar os números
    int n;

    // Pergunta ao usuário quantos números deseja armazenar
    printf("Quantos números você deseja armazenar? ");
    scanf("%d", &n);

    // Aloca memória suficiente para armazenar n inteiros
    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    // Recebe os números do usuário
    for (int i = 0; i < n; i++)
    {
        printf("Digite o número %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Exibe os números
    printf("Os números digitados são: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Libera a memória alocada
    free(arr);

    return 0;
}