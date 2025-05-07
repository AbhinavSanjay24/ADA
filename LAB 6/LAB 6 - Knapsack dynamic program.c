#include <stdio.h>

int i, j, n, c, w[10], p[10], v[10][10];

void knapsack(int n, int w[10], int p[10], int c) {
    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= c; j++) {
            if (i == 0 || j == 0)
                v[i][j] = 0;
            else if (w[i] > j)
                v[i][j] = v[i - 1][j];
            else
                v[i][j] = max(v[i - 1][j], v[i - 1][j - w[i]] + p[i]);
        }
    }

    printf("\n\nMaximum Profit is : %d\n\n", v[n][c]);
    printf("Table:\n\n");
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= c; j++) {
            printf("\t%d", v[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("\nEnter the number of objects: ");
    scanf("%d", &n);

    printf("\nEnter the weights: ");
    for (i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }

    printf("\nEnter the profits: ");
    for (i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    printf("\nEnter the capacity: ");
    scanf("%d", &c);

    knapsack(n, w, p, c);
    return 0;
}
