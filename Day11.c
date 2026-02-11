#include <stdio.h>

int main() {
    int m, n;

    printf("=== Matrix Addition Program ===\n\n");

    printf("Enter number of rows: ");
    scanf("%d", &m);

    printf("Enter number of columns: ");
    scanf("%d", &n);

    int a[m][n], b[m][n], sum[m][n];

    printf("\nEnter elements of First Matrix:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nEnter elements of Second Matrix:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("\nResultant Matrix after Addition:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d\t", sum[i][j]);
        }
        printf("\n");
    }

    printf("\nProgram completed successfully!\n");

    return 0;
}