#include <stdio.h>
#include <limits.h>

#define V 10   // Maximum number of vertices

// Find vertex with minimum key value not yet included in MST
int minKey(int key[], int mstSet[], int n) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Print the constructed MST
void printMST(int parent[], int graph[V][V], int n) {
    int totalWeight = 0;
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++) {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
        totalWeight += graph[i][parent[i]];
    }
    printf("Total weight of MST = %d\n", totalWeight);
}

// Prim’s Algorithm
void primMST(int graph[V][V], int n) {
    int parent[V]; // Array to store constructed MST
    int key[V];    // Key values to pick minimum weight edge
    int mstSet[V]; // Set of vertices included in MST

    // Initialize all keys as infinite
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    // Start from first vertex
    key[0] = 0;
    parent[0] = -1; // First node is root of MST

    // Construct MST with n-1 edges
    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = 1;

        // Update key values for adjacent vertices
        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print MST
    printMST(parent, graph, n);
}

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[V][V];
    printf("Enter adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST(graph, n);

    return 0;
}
