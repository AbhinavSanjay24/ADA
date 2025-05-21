#include <stdio.h>

#define MAX 100
#define INF 9999999

int cost[MAX][MAX];    // Adjacency matrix
int dist[MAX];         // Stores shortest distances from source
int visited[MAX];      // Marks visited vertices
int n;                 // Number of vertices

void dijkstra(int src) {
    int i, j, u;

    // Initialize distances and visited array
    for (i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[src] = 0;

    for (i = 0; i < n - 1; i++) {
        int min = INF;

        // Find the unvisited node with the smallest distance
        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        // Update distances of adjacent vertices
        for (j = 0; j < n; j++) {
            if (!visited[j] && cost[u][j] != INF && dist[u] + cost[u][j] < dist[j]) {
                dist[j] = dist[u] + cost[u][j];
            }
        }
    }

    // Print shortest distances
    printf("\nShortest distances from source vertex %d:\n", src);
    for (i = 0; i < n; i++) {
        printf("To vertex %d: %d\n", i, dist[i]);
    }
}

int main() {
    int i, j, src;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (0 if no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j)
                cost[i][j] = INF;
        }
    }

    printf("Enter the source vertex (0 to %d): ", n - 1);
    scanf("%d", &src);

    dijkstra(src);

    return 0;
}
