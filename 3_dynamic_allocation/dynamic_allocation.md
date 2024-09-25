# Alocação Dinâmica de Memória

A alocação dinâmica de memória é essencial quando o tamanho da memória necessária só pode ser determinado em tempo de execução, como quando lidamos com arrays de tamanho variável. No C, isso é feito principalmente com as funções `malloc`, `realloc` e `free`.

## 1. `malloc`: Alocação de Memória

A função `malloc` aloca um bloco de memória de tamanho especificado e retorna um ponteiro para o início desse bloco. A memória não é inicializada, ou seja, os valores podem ser aleatórios.

**Sintaxe:**

```c
void* malloc(size_t size);
```

- `size_t size`: Especifica a quantidade de bytes que você deseja alocar.
- **Retorna**: Um ponteiro para o início do bloco de memória alocado, ou `NULL` se a alocação falhar.

**Exemplo:**

```c
int *arr = (int*) malloc(5 * sizeof(int));  // Aloca espaço para 5 inteiros
```

Neste exemplo, `malloc` aloca memória suficiente para armazenar 5 inteiros e retorna um ponteiro para o início desse bloco de memória.

### Parâmetros e Funcionalidades

- **Parâmetro `size`**: Define o tamanho do bloco de memória a ser alocado em bytes. No exemplo, `5 * sizeof(int)` calcula o tamanho necessário para armazenar 5 inteiros.
- **Funcionalidade**: `malloc` é usada para alocar memória quando o tamanho necessário só é conhecido em tempo de execução.

## 2. `realloc`: Redimensionar a Memória

A função `realloc` é usada quando você já alocou um bloco de memória com `malloc` ou `calloc` e deseja redimensionar esse bloco (aumentar ou diminuir o tamanho).

**Sintaxe:**

```c
void* realloc(void* ptr, size_t new_size);
```

- `ptr`: Ponteiro para o bloco de memória previamente alocado.
- `new_size`: O novo tamanho que deseja alocar (em bytes).
- **Retorna**: Um ponteiro para o novo bloco de memória, ou `NULL` se a realocação falhar. Se o bloco original foi movido, `realloc` cuida de copiar os dados existentes para o novo bloco.

> Se `realloc` falha, o bloco original não é afetado.

**Exemplo:**

```c
int *arr = (int*) malloc(5 * sizeof(int));  // Aloca espaço para 5 inteiros

// Preenchendo o array
for (int i = 0; i < 5; i++) {
    arr[i] = i + 1;
}

// Agora, precisamos de mais espaço para 10 inteiros
arr = (int*) realloc(arr, 10 * sizeof(int));  // Redimensiona o bloco para 10 inteiros
```

- Se o novo tamanho for maior, os novos bytes alocados não serão inicializados.
- Se o novo tamanho for menor, os dados além do novo tamanho podem ser perdidos.

### Parâmetros e Funcionalidades

- **Parâmetro `ptr`**: O ponteiro para o bloco de memória previamente alocado que será redimensionado.
- **Parâmetro `new_size`**: Define o novo tamanho do bloco de memória em bytes.
- **Funcionalidade**: `realloc` é usada para ajustar o tamanho de um bloco de memória previamente alocado, permitindo aumentar ou diminuir a capacidade conforme necessário.

## 3. `free`: Liberar Memória

Toda memória alocada dinamicamente com `malloc`, `calloc` ou `realloc` deve ser liberada com a função `free` quando não for mais necessária. Caso contrário, você pode acabar com um vazamento de memória, onde o programa continua consumindo memória mesmo sem usá-la.

**Sintaxe:**

```c
void free(void* ptr);
```

- `ptr`: O ponteiro para o bloco de memória a ser liberado. Após chamar `free`, esse ponteiro não é mais válido.

**Exemplo:**

```c
free(arr);  // Libera o bloco de memória alocado para 'arr'
```

### Parâmetros e Funcionalidades

- **Parâmetro `ptr`**: O ponteiro para o bloco de memória que deve ser liberado.
- **Funcionalidade**: `free` é usada para liberar a memória alocada dinamicamente, prevenindo vazamentos de memória e garantindo que os recursos do sistema sejam utilizados de forma eficiente.

### Importância de `free`

Se você não liberar a memória, o programa pode acabar consumindo mais memória do que o necessário, levando a uma queda de desempenho ou até a falhas por falta de memória, especialmente em programas que rodam por longos períodos ou em sistemas com recursos limitados.

## Exercício Resolvido

**Problema:** Escreva um programa que:

- Aloca memória para armazenar 5 números inteiros.
- Permita que o usuário insira esses números.
- Redimensione o bloco de memória para armazenar 10 números.
- Peça ao usuário que insira mais 5 números.
- Exiba todos os 10 números.
- Libere a memória.

**Solução:**

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int i;

    // Aloca memória para 5 inteiros
    arr = (int*) malloc(5 * sizeof(int));
    if (arr == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    // Recebendo os primeiros 5 números
    printf("Digite 5 números:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    // Redimensiona a memória para armazenar mais 5 números (total 10)
    arr = (int*) realloc(arr, 10 * sizeof(int));
    if (arr == NULL) {
        printf("Erro na realocação de memória.\n");
        return 1;
    }

    // Recebendo mais 5 números
    printf("Digite mais 5 números:\n");
    for (i = 5; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    // Exibindo todos os 10 números
    printf("Os 10 números digitados são:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Libera a memória alocada
    free(arr);

    return 0;
}
```

**Explicação:**

- Inicialmente, alocamos memória para 5 inteiros usando `malloc`.
- Permitimos que o usuário insira os primeiros 5 números.
- Em seguida, redimensionamos o bloco de memória para armazenar 10 inteiros com `realloc`.
- O usuário então insere mais 5 números.
- Exibimos todos os 10 números e, no final, liberamos a memória com `free`.

