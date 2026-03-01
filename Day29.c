#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to rotate list
struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || k == 0)
        return head;

    struct Node* temp = head;
    int length = 1;

    // Find length and last node
    while (temp->next != NULL) {
        temp = temp->next;
        length++;
    }

    // Make it circular
    temp->next = head;

    // If k > length
    k = k % length;

    int steps = length - k;
    struct Node* newTail = head;

    // Move to (length-k)th node
    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    struct Node* newHead = newTail->next;

    // Break the circular link
    newTail->next = NULL;

    return newHead;
}

// Function to print list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, k, value;
    struct Node* head = NULL;
    struct Node* tail = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    scanf("%d", &k);

    head = rotateRight(head, k);

    printList(head);

    return 0;
}