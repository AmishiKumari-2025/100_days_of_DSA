#include <stdio.h>

int main() {
    int n, i, j, min_index, temp;

    // Input size
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Selection Sort
    for(i = 0; i < n - 1; i++) {
        min_index = i;

        for(j = i + 1; j < n; j++) {
            if(arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        // Swap
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }

    // Print sorted array
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}