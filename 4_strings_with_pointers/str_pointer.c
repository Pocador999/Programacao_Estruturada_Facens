// Exercício - Escreva um programa em C que:

// Peça ao usuário para inserir uma string.
// Use um ponteiro para contar o número de vogais na string(maiúsculas e minúsculas).
// Exiba o número de vogais na string.

// Solução:

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char str[100];
    char *p;
    int count = 0;

    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);

    // Remove o '\n' se ele existir
    str[strcspn(str, "\n")] = 0;

    p = str;

    // Conta as vogais
    while (*p)
    {
        if (tolower(*p) == 'a' || tolower(*p) == 'e' || tolower(*p) == 'i' || tolower(*p) == 'o' || tolower(*p) == 'u')
            count++;
        p++;
    }

    printf("Número de vogais na string: %d\n", count);

    return 0;
}