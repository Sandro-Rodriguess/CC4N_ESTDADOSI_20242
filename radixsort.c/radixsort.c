#include <stdio.h>
#include <stdlib.h>

/*
 * RADIXSORT
 * Complexidade de tempo:
 * - Melhor caso: O(nk) onde k é o número de dígitos
 * - Caso médio: O(nk)
 * - Pior caso: O(nk)
 * Complexidade de espaço: O(n + k)
 * 
 * Obs: Para números de d dígitos, k = d. Para n números de até d dígitos,
 * a complexidade é O(d * n)
 */

// Função auxiliar para encontrar o maior número no array
int obterMaximo(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Função para realizar o counting sort para cada dígito
void countingSort(int arr[], int n, int exp) {
    int* saida = (int*)malloc(n * sizeof(int));
    int contagem[10] = {0}; // Array para contar os dígitos (0-9)
    
    // Armazena a contagem de ocorrências no array contagem
    for (int i = 0; i < n; i++) {
        contagem[(arr[i] / exp) % 10]++;
    }
    
    // Modifica contagem[i] para conter a posição atual do dígito
    for (int i = 1; i < 10; i++) {
        contagem[i] += contagem[i - 1];
    }
    
    // Constrói o array de saída
    for (int i = n - 1; i >= 0; i--) {
        saida[contagem[(arr[i] / exp) % 10] - 1] = arr[i];
        contagem[(arr[i] / exp) % 10]--;
    }
    
    // Copia o array de saída para arr[]
    for (int i = 0; i < n; i++) {
        arr[i] = saida[i];
    }
    
    free(saida);
}

void radixSort(int arr[], int n) {
    // Encontra o número máximo para saber o número de dígitos
    int max = obterMaximo(arr, n);
    
    // Realiza counting sort para cada dígito
    // exp é 10^i onde i é o dígito atual
    for (int exp = 1; max/exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}