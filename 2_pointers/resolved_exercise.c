// Exercício - Escreva um programa que tenha duas variáveis inteiras.
// Crie um ponteiro que aponte para a primeira variável e use-o para modificar o valor da segunda.

// Solução:

#include <stdio.h>

int main()
{
    int a = 10, b = 20;
    int *p;

    p = &a;  // Ponteiro 'p' aponta para 'a'
    *p = 30; // Modifica o valor de 'a' para 30

    p = &b;  // Agora 'p' aponta para 'b'
    *p = 40; // Modifica o valor de 'b' para 40

    printf("Novo valor de a: %d\n", a); // Exibe 30
    printf("Novo valor de b: %d\n", b); // Exibe 40

    return 0;
}
// Output: Novo valor de a: 30
//         Novo valor de b: 40