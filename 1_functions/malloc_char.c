// Exercício - Escreva um programa em C que:

// Pergunte ao usuário quantas palavras ele deseja armazenar.
// Use malloc para alocar a memória necessária para armazenar palavras de até 50 caracteres.
// Peça ao usuárrio que insira as palavras.
// Exiba as palavras.
// Libere a memória alocada.

// Solução:

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    char **arr;

    // Pergunta ao usuário quantas palavras deseja armazenar
    printf("Quantas palavras você deseja armazenar? ");
    scanf("%d", &n);

    // Aloca memória para armazenar n ponteiros para palavras
    arr = (char **)malloc(n * sizeof(char *));

    if (arr == NULL)
    {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    // Aloca memória para cada palavra (supondo que cada palavra tenha até 50 caracteres)
    for (int i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(50 * sizeof(char));
        if (arr[i] == NULL)
        {
            printf("Erro na alocação de memória para a palavra %d.\n", i + 1);
            return 1;
        }

        // Pede ao usuário para inserir a palavra
        printf("Digite a palavra %d: ", i + 1);
        scanf("%s", arr[i]); // Lê a palavra
    }

    // Exibe todas as palavras inseridas
    printf("\nAs palavras digitadas foram:\n");
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);

    // Libera a memória alocada
    for (int i = 0; i < n; i++)
        free(arr[i]); // Libera cada palavra

    free(arr); // Libera o array de ponteiros

    return 0;
}