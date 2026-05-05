#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int index[], int count[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = 0;

    int temp[right - left + 1];
    int tempIndex[right - left + 1];

    int rightCount = 0;

    while (i <= mid && j <= right) {
        if (arr[index[j]] < arr[index[i]]) {
            // right element is smaller
            temp[k] = arr[index[j]];
            tempIndex[k] = index[j];
            rightCount++;
            j++;
        } else {
            // left element
            temp[k] = arr[index[i]];
            tempIndex[k] = index[i];
            count[index[i]] += rightCount;
            i++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = arr[index[i]];
        tempIndex[k] = index[i];
        count[index[i]] += rightCount;
        i++; k++;
    }

    while (j <= right) {
        temp[k] = arr[index[j]];
        tempIndex[k] = index[j];
        j++; k++;
    }

    for (int p = left; p <= right; p++) {
        index[p] = tempIndex[p - left];
    }
}

void mergeSort(int arr[], int index[], int count[], int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;

    mergeSort(arr, index, count, left, mid);
    mergeSort(arr, index, count, mid + 1, right);
    merge(arr, index, count, left, mid, right);
}

void countSmaller(int arr[], int n, int result[]) {
    int index[n];
    int count[n];

    for (int i = 0; i < n; i++) {
        index[i] = i;
        count[i] = 0;
    }

    mergeSort(arr, index, count, 0, n - 1);

    for (int i = 0; i < n; i++) {
        result[i] = count[i];
    }
}

// Driver
int main() {
    int arr[] = {5, 2, 6, 1};
    int n = 4;
    int result[n];

    countSmaller(arr, n, result);

    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
}