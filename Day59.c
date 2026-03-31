#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *left, *right;
};

// Create node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Search element in inorder
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Build tree from inorder & postorder
struct Node* buildTree(int inorder[], int postorder[], int start, int end, int *postIndex) {
    if (start > end)
        return NULL;

    // Last element of postorder is root
    struct Node* root = createNode(postorder[*postIndex]);
    (*postIndex)--;

    // If single node
    if (start == end)
        return root;

    int pos = search(inorder, start, end, root->data);

    // IMPORTANT: build right first
    root->right = buildTree(inorder, postorder, pos + 1, end, postIndex);
    root->left  = buildTree(inorder, postorder, start, pos - 1, postIndex);

    return root;
}

// Preorder traversal
void preorder(struct Node* root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Driver
int main() {
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    int postIndex = n - 1;

    struct Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    preorder(root);

    return 0;
}