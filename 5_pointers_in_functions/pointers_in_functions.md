# Passagem de Ponteiros para Funções em C

A passagem de ponteiros para funções é um conceito importante em C, pois permite que você modifique diretamente os dados fora do escopo da função. Ao contrário da passagem por valor, onde uma cópia da variável é feita, a passagem por ponteiro permite manipular o endereço da variável original, evitando cópias desnecessárias e possibilitando a alteração direta do valor original.

## 1. Passagem por Valor vs Passagem por Referência

### Passagem por Valor

A função recebe uma cópia da variável. Alterações feitas na cópia não afetam a variável original.

**Exemplo:**

```c
void alteraValor(int x) {
    x = 10;  // Altera a cópia, não o valor original
}

int main() {
    int a = 5;
    alteraValor(a);
    printf("Valor de a: %d\n", a);  // Exibe 5, pois 'a' não foi alterado
    return 0;
}
```

### Passagem por Ponteiro (Referência)

A função recebe um ponteiro para a variável original. Isso permite modificar o valor da variável diretamente.

**Exemplo:**

```c
void alteraValor(int *p) {
    *p = 10;  // Altera o valor da variável original
}

int main() {
    int a = 5;
    alteraValor(&a);
    printf("Valor de a: %d\n", a);  // Exibe 10, pois 'a' foi alterado pela função
    return 0;
}
```

**Explicação:**

- **Passagem por Valor:** `alteraValor(int x)` recebe uma cópia do valor de `a`. Alterar `x` não afeta `a`.
- **Passagem por Ponteiro:** `alteraValor(int *p)` recebe um ponteiro para `a`. Alterar `*p` modifica diretamente o valor de `a`.

## 2. Passagem de Arrays para Funções

Como o nome de um array é um ponteiro para o primeiro elemento, passar um array para uma função é equivalente a passar um ponteiro. Isso significa que você pode modificar o conteúdo de um array dentro de uma função sem precisar retornar os valores.

**Exemplo:**

```c
void dobraValores(int *arr, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        arr[i] *= 2;  // Dobra cada valor no array
    }
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    dobraValores(arr, 5);  // Passa o array (na verdade, o ponteiro para o primeiro elemento)
    
    // Exibe o array modificado
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
```

**Explicação:**

`dobraValores` recebe um ponteiro `arr` para o primeiro elemento do array e o tamanho do array. A função dobra os valores de cada elemento, e o array original é modificado diretamente.

## 3. Ponteiros como Parâmetros para Manipular Várias Variáveis

Quando passamos múltiplos ponteiros para uma função, podemos modificar várias variáveis ao mesmo tempo.

**Exemplo:**

```c
void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 10;
    troca(&x, &y);  // Troca os valores de 'x' e 'y'
    printf("x = %d, y = %d\n", x, y);  // Exibe "x = 10, y = 5"
    return 0;
}
```

**Explicação:**

`troca` recebe os ponteiros `a` e `b`, que apontam para as variáveis `x` e `y`. Ao modificar `*a` e `*b`, os valores de `x` e `y` são trocados diretamente.
