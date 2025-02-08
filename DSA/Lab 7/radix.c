#include <stdio.h>
#include <stdlib.h>  // For malloc() function

// Counting sort based on digit represented by exp (1s, 10s, 100s, etc.)
void countingSort(int arr[], int n, int exp) {
    int* output = (int*)malloc(n * sizeof(int));  // Dynamically allocate memory for output array
    int* count = (int*)malloc(10 * sizeof(int));  // Dynamically allocate memory for count array

    if (output == NULL || count == NULL) {  // Check for memory allocation failure
        printf("Memory allocation failed.\n");
        exit(1);  // Exit if memory allocation fails
    }

    // Initialize count array to 0
    for (int i = 0; i < 10; i++) {
        count[i] = 0;
    }

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Change count[i] to contain the actual position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array using the count positions
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the sorted numbers into the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    // Free dynamically allocated memory
    free(output);
    free(count);
}

// Function to perform Radix Sort
void radixSort(int arr[], int n) {
    // Find the maximum number to know the number of digits
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Do counting sort for every digit. The exp is 10^i where i is the current digit number
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};  // Example array
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    radixSort(arr, n);  // Sorting the array using Radix Sort

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
