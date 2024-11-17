#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declarações de funções externas
void shellSort(int arr[], int n);
void quickSort(int arr[], int baixo, int alto);
void heapSort(int arr[], int n);
void radixSort(int arr[], int n);

// Função para gerar array aleatório
void gerarArrayAleatorio(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;  // Números entre 0 e 999
    }
}

// Função para imprimir array
void imprimirArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função para verificar se o array está ordenado
int estaOrdenado(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        if (arr[i] > arr[i+1]) return 0;
    }
    return 1;
}

int main() {
    srand(time(NULL));
    
    // Tamanhos de teste
    int tamanhos[] = {100, 1000, 10000};
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);
    
    printf("=== TESTES DE ALGORITMOS DE ORDENAÇÃO ===\n\n");
    
    for (int i = 0; i < num_tamanhos; i++) {
        int n = tamanhos[i];
        int* arr = (int*)malloc(n * sizeof(int));
        int* arr_copia1 = (int*)malloc(n * sizeof(int));
        int* arr_copia2 = (int*)malloc(n * sizeof(int));
        int* arr_copia3 = (int*)malloc(n * sizeof(int));
        
        printf("Testando com array de tamanho %d\n", n);
        
        // Gera array aleatório
        gerarArrayAleatorio(arr, n);
        
        // Copia para testar todos os algoritmos com os mesmos dados
        for(int j = 0; j < n; j++) {
            arr_copia1[j] = arr[j];
            arr_copia2[j] = arr[j];
            arr_copia3[j] = arr[j];
        }
        
        // Teste ShellSort
        clock_t inicio = clock();
        shellSort(arr, n);
        clock_t fim = clock();
        double tempo_shell = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("ShellSort: %.4f segundos - %s\n", 
               tempo_shell, 
               estaOrdenado(arr, n) ? "Ordenado corretamente" : "Erro na ordenação");
        
        // Teste QuickSort
        inicio = clock();
        quickSort(arr_copia1, 0, n-1);
        fim = clock();
        double tempo_quick = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("QuickSort: %.4f segundos - %s\n", 
               tempo_quick, 
               estaOrdenado(arr_copia1, n) ? "Ordenado corretamente" : "Erro na ordenação");
        
        // Teste HeapSort
        inicio = clock();
        heapSort(arr_copia2, n);
        fim = clock();
        double tempo_heap = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("HeapSort: %.4f segundos - %s\n", 
               tempo_heap, 
               estaOrdenado(arr_copia2, n) ? "Ordenado corretamente" : "Erro na ordenação");
        
        // Teste RadixSort
        inicio = clock();
        radixSort(arr_copia3, n);
        fim = clock();
        double tempo_radix = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("RadixSort: %.4f segundos - %s\n\n", 
               tempo_radix, 
               estaOrdenado(arr_copia3, n) ? "Ordenado corretamente" : "Erro na ordenação");
        
        free(arr);
        free(arr_copia1);
        free(arr_copia2);
        free(arr_copia3);
    }
    
    return 0;
}