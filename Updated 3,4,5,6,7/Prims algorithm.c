#include <stdio.h>
#define MAX 100
#define INF 9999999

int main() {
    int n;
    int cost[MAX][MAX];
    int visited[MAX] = {0};
    int i, j, edges = 0;
    int minCost = 0;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (0 if no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF; // No connection
        }
    }

    visited[0] = 1; // Start from vertex 0

    printf("\nEdges in the Minimum Spanning Tree:\n");

    while (edges < n - 1) {
        int min = INF, u = -1, v = -1;

        for (i = 0; i < n; i++) {
            if (visited[i]) {
                for (j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u != -1 && v != -1) {
            printf("%d - %d : %d\n", u, v, cost[u][v]);
            visited[v] = 1;
            minCost += cost[u][v];
            edges++;
        }
    }

    printf("Total cost of MST: %d\n", minCost);
    return 0;
}
