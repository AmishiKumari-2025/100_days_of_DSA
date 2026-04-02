#include <stdio.h>

int main() {
    int n, m, i, u, v, choice;

    // Input number of vertices and edges
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    // Adjacency matrix initialization
    int adj[n][n];

    for(i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    // Choose graph type
    printf("Enter 1 for Directed Graph or 2 for Undirected Graph: ");
    scanf("%d", &choice);

    // Input edges
    printf("Enter %d edges (u v):\n", m);
    for(i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        // Add edge
        adj[u][v] = 1;

        // If undirected, add reverse edge
        if(choice == 2) {
            adj[v][u] = 1;
        }
    }

    // Print adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for(i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}