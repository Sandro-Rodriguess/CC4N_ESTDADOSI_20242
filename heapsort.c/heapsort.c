#include <stdio.h>

// Função auxiliar para trocar elementos
void trocar_heap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
 * HEAPSORT
 * Complexidade de tempo:
 * - Melhor caso: O(n log n)
 * - Caso médio: O(n log n)
 * - Pior caso: O(n log n)
 * Complexidade de espaço: O(1)
 */
void heapify(int arr[], int n, int i) {
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if (esquerda < n && arr[esquerda] > arr[maior])
        maior = esquerda;

    if (direita < n && arr[direita] > arr[maior])
        maior = direita;

    if (maior != i) {
        trocar_heap(&arr[i], &arr[maior]);
        heapify(arr, n, maior);
    }
}

void heapSort(int arr[], int n) {
    // Constrói o heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extrai elementos do heap um por um
    for (int i = n - 1; i > 0; i--) {
        trocar_heap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}