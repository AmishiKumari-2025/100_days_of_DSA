#include <stdio.h>

int main() {
    int n, i, j, key;

    // Read number of elements
    scanf("%d", &n);

    int arr[n];

    // Read array elements
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Insertion Sort
    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements greater than key one position ahead
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    // Print sorted array
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}