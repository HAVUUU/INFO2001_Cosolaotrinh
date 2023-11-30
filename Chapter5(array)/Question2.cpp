#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 1000000

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; 
        }
    }
    return -1;  
}

int binarySearch(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            return mid;  
        }

        if (arr[mid] > x) {
            return binarySearch(arr, left, mid - 1, x);  
        }

        return binarySearch(arr, mid + 1, right, x);  
    }

    return -1;  
}

int main() {
    int arr[ARR_SIZE];
    int x;

    srand(time(NULL));
    for (int i = 0; i < ARR_SIZE; i++) {
        arr[i] = rand() % 1000;
    }
    x = rand() % 1000;

 
    clock_t start_linear = clock();
    int linearIndex = linearSearch(arr, ARR_SIZE, x);
    clock_t end_linear = clock();
    double time_linear = (double)(end_linear - start_linear) / CLOCKS_PER_SEC;

    for (int i = 0; i < ARR_SIZE - 1; i++) {
        for (int j = 0; j < ARR_SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

   
    clock_t start_binary = clock();
    int binaryIndex = binarySearch(arr, 0, ARR_SIZE - 1, x);
    clock_t end_binary = clock();
    double time_binary = (double)(end_binary - start_binary) / CLOCKS_PER_SEC;

    printf("Linear Search:\n");
    if (linearIndex != -1) {
        printf("Element %d found at index %d\n", x, linearIndex);
    } else {
        printf("Element %d not found in the array\n", x);
    }
    printf("Time taken: %f seconds\n", time_linear);

    printf("\nBinary Search:\n");
    if (binaryIndex != -1) {
        printf("Element %d found at index %d\n", x, binaryIndex);
    } else {
        printf("Element %d not found in the array\n", x);
    }
    printf("Time taken: %f seconds\n", time_binary);

    return 0;
}
