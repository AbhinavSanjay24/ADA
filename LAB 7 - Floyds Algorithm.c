#include <stdio.h>
#include <limits.h>

#define INF INT_MAX

void floydWarshall(int graph[][4], int V) {
    int dist[V][V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = (i == j) ? 0 : (graph[i][j] ? graph[i][j] : INF);

    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            printf("%s%d ", dist[i][j] == INF ? "INF" : "", dist[i][j] == INF ? 0 : dist[i][j]);
        printf("\n");
    }
}

int main() {
    int V, i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int graph[V][V];
    printf("Enter the adjacency matrix (0 for no edge, INF for no direct path):\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    floydWarshall(graph, V);
    return 0;
}
