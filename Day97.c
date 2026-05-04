#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Meeting;

// Comparator for sorting by start time
int compare(const void *a, const void *b) {
    return ((Meeting *)a)->start - ((Meeting *)b)->start;
}

// Min Heap functions
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int heap[], int index) {
    while (index > 0 && heap[index] < heap[(index - 1) / 2]) {
        swap(&heap[index], &heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void heapifyDown(int heap[], int size, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

void insertHeap(int heap[], int *size, int value) {
    heap[*size] = value;
    (*size)++;
    heapifyUp(heap, *size - 1);
}

int extractMin(int heap[], int *size) {
    int min = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
    return min;
}

// Main function to find minimum rooms
int minMeetingRooms(Meeting meetings[], int n) {
    if (n == 0) return 0;

    // Step 1: Sort by start time
    qsort(meetings, n, sizeof(Meeting), compare);

    int heap[n]; // Min heap for end times
    int heapSize = 0;

    // Add first meeting
    insertHeap(heap, &heapSize, meetings[0].end);

    // Process remaining meetings
    for (int i = 1; i < n; i++) {
        // If room is free, reuse it
        if (meetings[i].start >= heap[0]) {
            extractMin(heap, &heapSize);
        }
        // Allocate new room (insert end time)
        insertHeap(heap, &heapSize, meetings[i].end);
    }

    return heapSize;
}

// Driver code
int main() {
    Meeting meetings[] = {
        {0, 30},
        {5, 10},
        {15, 20}
    };

    int n = sizeof(meetings) / sizeof(meetings[0]);

    int rooms = minMeetingRooms(meetings, n);

    printf("Minimum meeting rooms required: %d\n", rooms);

    return 0;
}