#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure
struct Graph {
    int numVertices;
    struct Node* adjList[MAX];
};

// Queue structure
struct Queue {
    int items[MAX];
    int front, rear;
};

// Create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge u -> v
void addEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = graph->adjList[u];
    graph->adjList[u] = newNode;
}

// Initialize queue
void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check empty
int isEmpty(struct Queue* q) {
    return q->front == -1;
}

// Enqueue
void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1) return;

    if (q->front == -1)
        q->front = 0;

    q->items[++q->rear] = value;
}

// Dequeue
int dequeue(struct Queue* q) {
    if (isEmpty(q))
        return -1;

    int item = q->items[q->front];

    if (q->front >= q->rear)
        q->front = q->rear = -1;
    else
        q->front++;

    return item;
}

// Topological Sort using Kahn's Algorithm
void topologicalSort(struct Graph* graph) {
    int inDegree[MAX] = {0};

    // Step 1: Calculate in-degree of each vertex
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjList[i];
        while (temp) {
            inDegree[temp->vertex]++;
            temp = temp->next;
        }
    }

    // Step 2: Add vertices with in-degree 0 to queue
    struct Queue q;
    initQueue(&q);

    for (int i = 0; i < graph->numVertices; i++) {
        if (inDegree[i] == 0)
            enqueue(&q, i);
    }

    // Step 3: Process queue
    int count = 0;

    printf("Topological Order: ");

    while (!isEmpty(&q)) {
        int current = dequeue(&q);
        printf("%d ", current);

        struct Node* temp = graph->adjList[current];
        while (temp) {
            inDegree[temp->vertex]--;
            if (inDegree[temp->vertex] == 0)
                enqueue(&q, temp->vertex);
            temp = temp->next;
        }
        count++;
    }

    // Step 4: Check for cycle
    if (count != graph->numVertices) {
        printf("\nGraph contains a cycle!\n");
    }
}

// Main function
int main() {
    int vertices, edges;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    struct Graph* graph = createGraph(vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v) meaning u -> v:\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    topologicalSort(graph);

    return 0;
}