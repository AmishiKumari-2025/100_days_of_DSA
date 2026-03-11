#include <stdio.h>

int heap[100];
int size = 0;

void insert(int x) {
    heap[size] = x;
    int i = size;
    size++;

    while(i > 0 && heap[(i-1)/2] > heap[i]) {
        int temp = heap[i];
        heap[i] = heap[(i-1)/2];
        heap[(i-1)/2] = temp;
        i = (i-1)/2;
    }
}

void extractMin() {
    if(size == 0) {
        printf("-1\n");
        return;
    }

    printf("%d\n", heap[0]);
    heap[0] = heap[size-1];
    size--;

    int i = 0;
    while(2*i + 1 < size) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = left;

        if(right < size && heap[right] < heap[left])
            smallest = right;

        if(heap[i] <= heap[smallest])
            break;

        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;

        i = smallest;
    }
}

void peek() {
    if(size == 0)
        printf("-1\n");
    else
        printf("%d\n", heap[0]);
}

int main() {
    int n;
    scanf("%d", &n);

    for(int i=0;i<n;i++) {
        char op[20];
        scanf("%s", op);

        if(op[0]=='i') {
            int x;
            scanf("%d", &x);
            insert(x);
        }
        else if(op[0]=='p') {
            peek();
        }
        else {
            extractMin();
        }
    }
}