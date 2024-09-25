// Exercício - Escreva um programa em C que:

// Declare um array de inteiros com 5 elementos.
// Crie um ponteiro que aponte para o primeiro elemento do array.
// Use o ponteiro para percorrer o array e multiplicar cada elemento por 2.
// Exiba o array modificado.

// Solução:

#include <stdio.h>

int main()
{
    // Declarando um array de 5 inteiros
    int arr[5] = {1, 2, 3, 4, 5};

    // Criando um ponteiro que aponta para o primeiro elemento do array
    int *p = arr;

    // Percorrendo o array e multiplicando cada elemento por 2
    for (int i = 0; i < 5; i++)
    {
        *p = (*p) * 2; // Multiplica o valor apontado pelo ponteiro por 2
        p++;           // Move o ponteiro para o próximo elemento
    }

    // Exibindo o array modificado
    printf("Array modificado: \n");
    for (int i = 0; i < 5; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}
