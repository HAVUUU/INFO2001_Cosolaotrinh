#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 10000


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, minIndex;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(&arr[minIndex], &arr[i]);
    }
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr_bubble[ARR_SIZE];
    int arr_selection[ARR_SIZE];

    
    srand(time(NULL));
    for (int i = 0; i < ARR_SIZE; i++) {
        int num = rand() % 1000;
        arr_bubble[i] = num;
        arr_selection[i] = num;
    }

    // Bubble Sort
    clock_t start_bubble = clock();
    bubbleSort(arr_bubble, ARR_SIZE);
    clock_t end_bubble = clock();
    double time_bubble = (double)(end_bubble - start_bubble) / CLOCKS_PER_SEC;

    // Selection Sort
    clock_t start_selection = clock();
    selectionSort(arr_selection, ARR_SIZE);
    clock_t end_selection = clock();
    double time_selection = (double)(end_selection - start_selection) / CLOCKS_PER_SEC;

    printf("Bubble Sort:\n");
    printf("Thoi gian thuc thi: %f seconds\n", time_bubble);

    printf("\nSelection Sort:\n");
    printf("Thoi gian thuc thi: %f seconds\n", time_selection);

    return 0;
}



