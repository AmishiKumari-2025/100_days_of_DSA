#include <stdio.h>

int main() {
    int a[100], n, pos, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter position to delete (1-based): ");
    scanf("%d", &pos);

    if (pos < 1 || pos > n) {
        printf("Invalid position!\n");
        return 0;
    }

    for (i = pos - 1; i < n - 1; i++) {
        a[i] = a[i + 1];
    }

    n--;  

    printf("Array after deletion:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
