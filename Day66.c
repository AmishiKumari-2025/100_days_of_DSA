#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int recStack[MAX];
int n;

// DFS function to detect cycle
bool dfs(int node) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[node][i]) {
            // If not visited, recurse
            if (!visited[i]) {
                if (dfs(i))
                    return true;
            }
            // If visited and in recursion stack → cycle
            else if (recStack[i]) {
                return true;
            }
        }
    }

    recStack[node] = 0; // remove from recursion stack
    return false;
}

// Function to check cycle
bool hasCycle() {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i))
                return true;
        }
    }
    return false;
}

int main() {
    int edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize graph, visited, recStack
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        recStack[i] = 0;
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (u v) for directed graph:\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    if (hasCycle())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}