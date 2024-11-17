#include <stdio.h>

// Função auxiliar para trocar dois elementos
void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
 * QUICKSORT
 * Complexidade de tempo:
 * - Melhor caso: O(n log n)
 * - Caso médio: O(n log n)
 * - Pior caso: O(n^2)
 * Complexidade de espaço: O(log n)
 */
int particionar(int arr[], int baixo, int alto) {
    int pivo = arr[alto];
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++) {
        if (arr[j] < pivo) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i + 1], &arr[alto]);
    return (i + 1);
}

void quickSort(int arr[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = particionar(arr, baixo, alto);
        quickSort(arr, baixo, pi - 1);
        quickSort(arr, pi + 1, alto);
    }
}