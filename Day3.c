#include <stdio.h>

int main() {
    int n, k, i;
    int comparisons = 0;

    printf("Enter array size:\n");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter key to search:\n");
    scanf("%d", &k);

    for (i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == k) {
            printf("Found at index %d\n", i);
            printf("Comparisons = %d", comparisons);
            return 0;
        }
    }

    printf("Not Found\n");
    printf("Comparisons = %d", comparisons);

    return 0;
}