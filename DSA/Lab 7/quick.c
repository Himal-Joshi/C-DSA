#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function that places the pivot in the correct position
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choose the last element as pivot
    int i = low - 1;  // Index of smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;  // Increment index of smaller element
            swap(&arr[i], &arr[j]);  // Swap elements
        }
    }
    swap(&arr[i + 1], &arr[high]);  // Place the pivot in the correct position
    return i + 1;  // Return the index of the pivot
}

// Quick Sort function that recursively sorts the array
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array into two sub-arrays and get the pivot index
        int pi = partition(arr, low, high);

        // Recursively sort the two sub-arrays
        quickSort(arr, low, pi - 1);  // Sort the left sub-array
        quickSort(arr, pi + 1, high);  // Sort the right sub-array
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
    int arr[] = {64, 34, 25, 12, 22, 11, 90};  // Example array
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);  // Sorting the array using Quick Sort

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
