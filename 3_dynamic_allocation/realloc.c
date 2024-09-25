// Exercício - Escreva um programa em C que:

// Pergunte ao usuário quantos números ele deseja armaenar.
// Aloque memória para armazenar esses números.
// Permita que o usuário insira esses números.
// Pergunte se o usuário deseja adicionar mais números.
// Se sim, redimensione o bloco de memória para armazenar os novos números.
// Exiba todos os números.
// Libere a memória alocada.

// Solução:

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr;
    int i, n, new_size;
    int choice;

    printf("Quantos números você deseja armazenar? ");
    scanf("%d", &n);

    // Aloca memória para n inteiros
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    // Recebendo os números
    printf("Digite %d números:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Perguntando se o usuário deseja adicionar mais números
    printf("Deseja adicionar mais números? (1 - Sim, 0 - Não)");
    scanf("%d", &choice);

    while (choice != 0 && choice != 1)
    {
        printf("Opção inválida. Deseja adicionar mais números? (1 - Sim, 0 - Não) ");
        scanf("%d", &choice);
    }

    if (choice == 1)
    {
        printf("Quantos números você deseja adicionar? ");
        scanf("%d", &new_size);

        // Redimensiona a memória para armazenar mais new_size números
        arr = (int *)realloc(arr, (n + new_size) * sizeof(int));
        if (arr == NULL)
        {
            printf("Erro na realocação de memória.\n");
            return 1;
        }

        // Recebendo os novos números
        printf("Digite mais %d números:\n", new_size);
        for (i = n; i < n + new_size; i++)
            scanf("%d", &arr[i]);

        // Atualiza o valor de n
        n += new_size;
    }

    printf("Os números digitados são:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
        
    printf("\n");

    free(arr);

    return 0;
}