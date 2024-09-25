# Funções de Alocação Dinâmica de Memória em C

### As principais funções para alocação dinâmica de memória em C são:

## `malloc`

A função `malloc` (memory allocation) é usada para alocar um bloco de memória de um tamanho especificado em bytes. O conteúdo da memória alocada não é inicializado, ou seja, os valores armazenados na memória são indefinidos até que sejam explicitamente inicializados pelo programador.

**Sintaxe:**
```c
void* malloc(size_t size);
```

- `size_t size`: O número de bytes a serem alocados. Este valor é geralmente calculado usando o operador `sizeof` para garantir que a quantidade correta de memória seja alocada para o tipo de dado desejado.

**Exemplo:**
```c
int *ptr = (int*) malloc(10 * sizeof(int)); // Aloca espaço para 10 inteiros
```

- `int *ptr`: Ponteiro para o bloco de memória alocado. O tipo `void*` retornado por `malloc` é convertido para o tipo de ponteiro apropriado.
- `sizeof(int)`: Retorna o tamanho em bytes de um inteiro. Multiplicando por 10, alocamos espaço suficiente para armazenar 10 inteiros.

## `realloc`

A função `realloc` (reallocation) é usada para redimensionar um bloco de memória previamente alocado com `malloc` ou `calloc`. Isso é útil quando você precisa aumentar ou diminuir o tamanho de um bloco de memória existente.

**Sintaxe:**
```c
void* realloc(void* ptr, size_t new_size);
```

- `void* ptr`: Ponteiro para o bloco de memória previamente alocado. Se `ptr` for `NULL`, `realloc` se comporta como `malloc`.
- `size_t new_size`: O novo tamanho em bytes do bloco de memória. Se `new_size` for zero e `ptr` não for `NULL`, a memória apontada por `ptr` é liberada.

**Exemplo:**
```c
ptr = (int*) realloc(ptr, 20 * sizeof(int)); // Redimensiona o bloco para 20 inteiros
```

- `ptr`: Ponteiro para o bloco de memória redimensionado. Se a realocação falhar, `realloc` retorna `NULL` e o bloco de memória original permanece inalterado.

## `free`

A função `free` é usada para liberar a memória alocada dinamicamente. É importante liberar a memória quando ela não é mais necessária para evitar vazamentos de memória, que podem levar a um consumo excessivo de recursos.

**Sintaxe:**
```c
void free(void* ptr);
```

- `void* ptr`: Ponteiro para o bloco de memória a ser liberado. Se `ptr` for `NULL`, nenhuma ação é realizada.

**Exemplo:**
```c
free(ptr); // Libera a memória alocada
```

- `ptr`: Após a chamada para `free`, o ponteiro `ptr` não deve ser mais usado a menos que seja reassociado a um novo bloco de memória.

## `calloc`

A função `calloc` (contiguous allocation) é usada para alocar memória para um array de elementos e inicializa todos os bytes com zero. Isso é útil quando você precisa garantir que a memória alocada esteja zerada.

**Sintaxe:**
```c
void* calloc(size_t num, size_t size);
```

- `size_t num`: Número de elementos a serem alocados.
- `size_t size`: Tamanho em bytes de cada elemento.

**Exemplo:**
```c
int *ptr = (int*) calloc(10, sizeof(int)); // Aloca espaço para 10 inteiros e inicializa todos com 0
```

- `int *ptr`: Ponteiro para o bloco de memória alocado. A memória é inicializada com zeros.
- `sizeof(int)`: Retorna o tamanho em bytes de um inteiro. Multiplicando por 10, alocamos espaço suficiente para armazenar 10 inteiros.

