// Exercício - Escreva um programa em C que:

// Declare uma string e use um ponteiro para acessar cada caractere da string.
// Substitua todos os caracteres minúsculos por maiúsculos, e vice-versa, e exiba a string modificada.

// Solução:

#include <stdio.h>
#include <ctype.h>

int main()
{
    char str[] = "Hello, World!";
    char *p = str;

    printf("String original: %s\n", str);

    while (*p)
    {
        if (islower(*p))
            *p = toupper(*p);
        else if (isupper(*p))
            *p = tolower(*p);
        p++;
    }

    printf("String modificada: %s\n", str);

    return 0;
}