# Manipulação de Strings em C

As strings em C são representadas como arrays de caracteres terminados pelo caractere nulo (`\0`). Como os arrays em C são tratados como ponteiros, podemos manipular strings diretamente com ponteiros, o que dá ao programador bastante flexibilidade.

## 1. Strings como Arrays de Caracteres

Uma string em C é basicamente um array de caracteres. Por exemplo:

```c
char str[6] = "hello";
```

Aqui, `str` é um array de 6 caracteres, onde o último caractere é `'\0'` (o caractere nulo). Esse caractere de terminação é necessário para indicar o final da string.

### Exemplo básico:

```c
#include <stdio.h>

int main() {
    char str[6] = "hello";
    printf("%s\n", str);  // Exibe a string "hello"
    return 0;
}
```

**Parâmetros e Funcionalidades:**

- `char str[6]`: Declara um array de 6 caracteres, incluindo o espaço para o caractere nulo.
- `%s` no `printf`: Utilizamos o formato `%s` para exibir strings em C.

## 2. Strings como Ponteiros

Em C, o nome de um array é um ponteiro para o primeiro elemento do array. Isso significa que podemos usar ponteiros para acessar e modificar strings.

```c
char *str = "hello";
```

Neste caso, `str` é um ponteiro para o primeiro caractere da string "hello". Podemos acessar e modificar a string usando notação de ponteiros.

### Exemplo:

```c
#include <stdio.h>

int main() {
    char *str = "hello";
    printf("Primeiro caractere: %c\n", *str);  // Exibe 'h'
    printf("Segundo caractere: %c\n", *(str + 1));  // Exibe 'e'
    return 0;
}
```

Aqui, `*str` acessa o primeiro caractere ('h'), e `*(str + 1)` acessa o segundo caractere ('e').

## 3. Funções Úteis para Manipulação de Strings

### 3.1 `strlen`: Comprimento da String

A função `strlen` retorna o número de caracteres em uma string, excluindo o caractere nulo (`'\0'`).

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "hello";
    printf("Comprimento da string: %lu\n", strlen(str));  // Exibe 5
    return 0;
}
```

### 3.2 `strcpy`: Copiar Strings

A função `strcpy` copia o conteúdo de uma string para outra. É importante garantir que a string de destino tenha espaço suficiente para armazenar a string de origem, incluindo o caractere nulo.

```c
#include <stdio.h>
#include <string.h>

int main() {
    char origem[] = "hello";
    char destino[6];

    strcpy(destino, origem);
    printf("String copiada: %s\n", destino);  // Exibe "hello"
    return 0;
}
```

### 3.3 `strcat`: Concatenar Strings

A função `strcat` concatena uma string ao final de outra string. Novamente, certifique-se de que a string de destino tenha espaço suficiente para armazenar o resultado.

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[20] = "Hello, ";
    char str2[] = "world!";

    strcat(str1, str2);
    printf("Resultado da concatenação: %s\n", str1);  // Exibe "Hello, world!"
    return 0;
}
```

## Exercício Resolvido

**Problema:** Escreva um programa que:

1. Declare uma string e use um ponteiro para acessar cada caractere individualmente.
2. Substitua todos os caracteres de uma string por letras maiúsculas (use a função `toupper` da biblioteca `ctype.h`).

**Solução:**

```c
#include <stdio.h>
#include <ctype.h>  // Para usar toupper

int main() {
    char str[] = "hello world";
    char *p = str;

    // Percorre cada caractere e converte para maiúsculas
    while (*p != '\0') {
        *p = toupper(*p);
        p++;
    }

    printf("String em maiúsculas: %s\n", str);  // Exibe "HELLO WORLD"
    return 0;
}
```

**Explicação:**

Usamos um ponteiro `p` para percorrer a string `str` e converter cada caractere para maiúsculas com a função `toupper`.