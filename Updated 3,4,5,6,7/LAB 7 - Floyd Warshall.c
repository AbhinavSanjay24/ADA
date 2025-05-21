#include <stdio.h>
#include <limits.h>

#define INF INT_MAX
#define MAX 100

void floydWarshall(int V) {
    int graph[MAX][MAX], dist[MAX][MAX];

    // Read the graph
    printf("Enter the adjacency matrix (use 0 for no edge):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize dist matrix using if statements
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j) {   //self distance is 0
                dist[i][j] = 0;
            } else {
                if (graph[i][j]) { // if there is a edge use it
                    dist[i][j] = graph[i][j];
                } else {
                    dist[i][j] = INF;  // no edge means INF
                }
            }
        }
    }

    // Apply Floyd-Warshall algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF &&dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the distance matrix
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    floydWarshall(V);

    return 0;
}
