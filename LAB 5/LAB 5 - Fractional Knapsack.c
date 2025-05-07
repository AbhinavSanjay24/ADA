#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value, weight;
};

int compare(const void* a, const void* b) {
    struct Item* item1 = (struct Item*)a;
    struct Item* item2 = (struct Item*)b;
    return item2->value * item1->weight - item1->value * item2->weight;
}

double fractionalKnapsack(int W, struct Item arr[], int n) {
    qsort(arr, n, sizeof(arr[0]), compare);
    double finalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            finalValue += arr[i].value;
        } else {
            finalValue += arr[i].value * ((double)W / arr[i].weight);
            break;
        }
    }

    return finalValue;
}

void main() {
    int n, W;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item arr[n];

    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &arr[i].value, &arr[i].weight);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    double maxValue = fractionalKnapsack(W, arr, n);
    printf("Maximum value in Knapsack = %.2f\n", maxValue);
}
