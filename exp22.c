#include <stdio.h>

#define MAX 20

int adj[MAX][MAX];  // Adjacency matrix
int visited[MAX];   // Visited array
int n;              // Number of vertices

// Function to perform DFS
void DFS(int v) {
    printf("%d ", v);   // Visit the node
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            DFS(i); // Recur for unvisited adjacent node
        }
    }
}

int main() {
    int edges, v1, v2, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency matrix and visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d%d", &v1, &v2);
        adj[v1][v2] = 1;
        adj[v2][v1] = 1;  // For undirected graph
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("\nDFS Traversal starting from vertex %d: ", start);
    DFS(start);

    return 0;
}
