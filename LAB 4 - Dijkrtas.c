#include <stdio.h>
#include <limits.h>

#define MAX 100

void dijkstra(int graph[MAX][MAX], int n, int start) {
    int dist[MAX], visited[MAX] = {0};

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;  // Use INT_MAX as a large value for infinity
    }
    dist[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        int min = INT_MAX, u;

        // Find the vertex with the minimum distance from the unvisited vertices
        for (int v = 0; v < n; v++) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                u = v;
            }
        }

        visited[u] = 1;

        // Update the distances for adjacent vertices
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != INT_MAX && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Vertex\tDistance from Source %d\n", start);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) {
            printf("%d\t\tINF\n", i);  // If the distance is still INT_MAX, it's unreachable
        } else {
            printf("%d\t\t%d\n", i, dist[i]);
        }
    }
}

int main() {
    int n, graph[MAX][MAX], start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (0 for no edge, positive integers for edge weights):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j) {
                graph[i][j] = INT_MAX;  // Use INT_MAX to represent no edge between vertices
            }
        }
    }

    printf("Enter the starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    dijkstra(graph, n, start);

    return 0;
}
