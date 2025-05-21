/*#include <stdio.h>
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
}*/


#include <stdio.h>

typedef struct {
    int weight;
    int profit;
    float ratio;
} Item;

void sortItems(Item items[], int n) {
    // Sort by ratio in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

void fractionalKnapsack(Item items[], int n, int capacity) {
    sortItems(items, n);

    float totalProfit = 0.0;
    int remainingCapacity = capacity;

    printf("\nItems taken:\n");
    for (int i = 0; i < n && remainingCapacity > 0; i++) {
        if (items[i].weight <= remainingCapacity) {
            // Take the full item
            printf("Item %d: 100%% (Profit: %d)\n", i + 1, items[i].profit);
            totalProfit += items[i].profit;
            remainingCapacity -= items[i].weight;
        } else {
            // Take fraction of item
            float fraction = (float)remainingCapacity / items[i].weight;
            float profitFromFraction = items[i].profit * fraction;
            printf("Item %d: %.2f%% (Profit: %.2f)\n", i + 1, fraction * 100, profitFromFraction);
            totalProfit += profitFromFraction;
            remainingCapacity = 0;
        }
    }

    printf("\nMaximum Profit (Fractional): %.2f\n", totalProfit);
}

int main() {
    int n, c;
    Item items[10];

    printf("\nEnter the number of items: ");
    scanf("%d", &n);

    printf("Enter weights of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &items[i].weight);
    }

    printf("Enter profits of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &items[i].profit);
        items[i].ratio = (float)items[i].profit / items[i].weight;  // Calculate ratio
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &c);

    fractionalKnapsack(items, n, c);

    return 0;
}

