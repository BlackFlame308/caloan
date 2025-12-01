#include <stdio.h>

// Function to print array
void printArray(int arr[], int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf(" ]\n");
}

/* ----------------------------------------------------------
   INSERTION SORT TRACE
---------------------------------------------------------- */
void insertionSortTrace(int arr[], int size) {
    printf("\n--- Insertion Sort Trace ---\n\n");
    printf("Initial Array: ");
    printArray(arr, size);

    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        printf("\nPass %d (i=%d, Key=%d): Insert %d into sorted part [", 
               i, i, key, key);

        for (int k = 0; k < i; k++) {
            printf("%d", arr[k]);
            if (k < i - 1) printf(", ");
        }
        printf("]\n");

        // Comparison and shifting
        while (j >= 0) {
            printf("  Comparing Key (%d) < Array[%d] (%d): ", key, j, arr[j]);

            if (key < arr[j]) {
                printf("TRUE. Shift %d right to index %d.\n", arr[j], j + 1);
                arr[j + 1] = arr[j];
                j--;
            } else {
                printf("FALSE. Stop comparisons.\n");
                break;
            }
        }

        arr[j + 1] = key;
        printf("  Key %d inserted at index %d.\n", key, j + 1);

        printf("  Array State: ");
        printArray(arr, size);

        printf("  Sorted Part: [ ");
        for (int k = 0; k <= i; k++) {
            printf("%d", arr[k]);
            if (k < i) printf(", ");
        }
        printf(" ]\n");
    }

    printf("\n--- Final Sorted Array ---\n");
    printArray(arr, size);
}

/* ----------------------------------------------------------
   SELECTION SORT TRACE
---------------------------------------------------------- */
void selectionSortTrace(int arr[], int size) {
    printf("\n--- Selection Sort Trace ---\n\n");
    printf("Initial Array: ");
    printArray(arr, size);

    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;

        // Find smallest
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        printf("Pass %d: Minimum = %d at index %d\n", 
               i + 1, arr[minIndex], minIndex);

        // Swap
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;

        printf("  Array State: ");
        printArray(arr, size);
    }

    printf("\n--- Final Sorted Array ---\n");
    printArray(arr, size);
}

/* ----------------------------------------------------------
   BUBBLE SORT TRACE
---------------------------------------------------------- */
void bubbleSortTrace(int arr[], int size) {
    printf("\n--- Bubble Sort Trace ---\n\n");
    printf("Initial Array: ");
    printArray(arr, size);

    for (int i = 0; i < size - 1; i++) {
        int swapped = 0;

        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped++;
            }
        }

        printf("Pass %d: Swaps made = %d", i + 1, swapped);

        if (swapped == 0)
            printf("  (Array already sorted)\n");
        else
            printf("\n");

        printf("  Array State: ");
        printArray(arr, size);

        if (swapped == 0) break;
    }

    printf("\n--- Final Sorted Array ---\n");
    printArray(arr, size);
}

/* ----------------------------------------------------------
   MAIN PROGRAM
---------------------------------------------------------- */
int main() {
    int data1[] = { 73, 22, 95, 11, 6, 88, 34, 47, 51, 19 };
    int data2[] = { 73, 22, 95, 11, 6, 88, 34, 47, 51, 19 };
    int data3[] = { 73, 22, 95, 11, 6, 88, 34, 47, 51, 19 };
    int size = 10;

    insertionSortTrace(data1, size);
    selectionSortTrace(data2, size);
    bubbleSortTrace(data3, size);

    return 0;
}
