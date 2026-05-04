#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

// Comparator for sorting
int compare(const void *a, const void *b) {
    return ((Interval *)a)->start - ((Interval *)b)->start;
}

// Function to merge intervals
void mergeIntervals(Interval arr[], int n) {
    if (n <= 0) return;

    // Step 1: Sort intervals
    qsort(arr, n, sizeof(Interval), compare);

    // Temporary array to store result
    Interval result[n];
    int index = 0;

    // Add first interval
    result[index] = arr[0];

    // Step 2: Traverse and merge
    for (int i = 1; i < n; i++) {
        // If overlapping
        if (arr[i].start <= result[index].end) {
            // Merge by updating end
            if (arr[i].end > result[index].end)
                result[index].end = arr[i].end;
        } else {
            // No overlap → new interval
            index++;
            result[index] = arr[i];
        }
    }

    // Print merged intervals
    printf("Merged Intervals:\n");
    for (int i = 0; i <= index; i++) {
        printf("[%d, %d]\n", result[i].start, result[i].end);
    }
}

// Driver code
int main() {
    Interval arr[] = {
        {1, 3},
        {2, 6},
        {8, 10},
        {15, 18}
    };

    int n = sizeof(arr) / sizeof(arr[0]);

    mergeIntervals(arr, n);

    return 0;
}