// Exercício - Escreva um programa em C que:

// Aloca memória para armazenar 5 números inteiros.
// Permita que o usuário insira esses números.
// Redimensione o bloco de memória para armazenar 10 números.
// Peça ao usuário que insira mais 5 números.
// Exiba todos os 10 números.
// Libere a memória alocada.

// Solução:

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr;
    int i;

    // Aloca memória para 5 inteiros
    arr = (int *)malloc(5 * sizeof(int));
    if (arr == NULL)
    {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    // Recebendo os primeiros 5 números
    printf("Digite 5 números:\n");
    for (i = 0; i < 5; i++)
        scanf("%d", &arr[i]);

    // Redimensiona a memória para armazenar mais 5 números (total 10)
    arr = (int *)realloc(arr, 10 * sizeof(int));
    if (arr == NULL)
    {
        printf("Erro na realocação de memória.\n");
        return 1;
    }

    // Recebendo mais 5 números
    printf("Digite mais 5 números:\n");
    for (i = 5; i < 10; i++)
        scanf("%d", &arr[i]);

    // Exibindo todos os 10 números
    printf("Os 10 números digitados são:\n");
    for (i = 0; i < 10; i++)
        printf("%d ", arr[i]);

    printf("\n");

    // Libera a memória alocada
    free(arr);

    return 0;
}
