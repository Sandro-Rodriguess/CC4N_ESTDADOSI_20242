#include <stdio.h>

/*
 * SHELLSORT
 * Complexidade de tempo:
 * - Melhor caso: O(n log n)
 * - Caso médio: O(n^1.3)
 * - Pior caso: O(n^2)
 * Complexidade de espaço: O(1)
 */
void shellSort(int arr[], int n) {
    // Começa com um gap grande e vai reduzindo
    for (int gap = n/2; gap > 0; gap /= 2) {
        // Realiza insertion sort para cada gap
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            
            // Move os elementos que são maiores que temp
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}