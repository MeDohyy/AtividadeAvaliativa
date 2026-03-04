#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int maior = i;
    int esquerda = 2*i + 1;
    int direita = 2*i + 2;

    if (esquerda < n && arr[esquerda] > arr[maior])
        maior = esquerda;

    if (direita < n && arr[direita] > arr[maior])
        maior = direita;

    if (maior != i) {
        swap(&arr[i], &arr[maior]);
        heapify(arr, n, maior);
    }
}

void heapSort(int arr[], int n) {
    int i;

    for (i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void shellSort(int arr[], int n) {
    int gap, i, j, temp;

    for (gap = n/2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = arr[i];

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            arr[j] = temp;
        }
    }
}

void imprimir(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int vetor1[] = {30, 12, 45, 6, 18, 3};
    int vetor2[] = {30, 12, 45, 6, 18, 3};
    int n = 6;

    printf("Vetor original:\n");
    imprimir(vetor1, n);

    heapSort(vetor1, n);
    printf("HeapSort:\n");
    imprimir(vetor1, n);

    shellSort(vetor2, n);
    printf("ShellSort:\n");
    imprimir(vetor2, n);

    return 0;
}
