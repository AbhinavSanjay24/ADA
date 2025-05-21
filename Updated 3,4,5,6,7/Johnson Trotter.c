#include <stdio.h>
#include <stdlib.h>

#define LEFT -1
#define RIGHT 1

// Structure to store element and its direction
typedef struct {
    int value;
    int dir;
} Element;

// Function to print the current permutation
void printPermutation(Element perm[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", perm[i].value);
    }
    printf("\n");
}

// Function to find the largest mobile element
int getLargestMobile(Element perm[], int n) {
    int mobile = 0;
    int mobileIndex = -1;

    for (int i = 0; i < n; i++) {
        int nextIndex = i + perm[i].dir;

        if (nextIndex >= 0 && nextIndex < n && perm[i].value > perm[nextIndex].value) {
            if (perm[i].value > mobile) {
                mobile = perm[i].value;
                mobileIndex = i;
            }
        }
    }

    return mobileIndex;
}

// Swap two elements
void swap(Element *a, Element *b) {
    Element temp = *a;
    *a = *b;
    *b = temp;
}

// Reverse direction of all elements greater than value
void reverseDirections(Element perm[], int n, int value) {
    for (int i = 0; i < n; i++) {
        if (perm[i].value > value) {
            perm[i].dir = -perm[i].dir;
        }
    }
}

int factorial(int n) {
    return (n == 1) ? 1 : n * factorial(n - 1);
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    Element perm[n];
    for (int i = 0; i < n; i++) {
        perm[i].value = i + 1;
        perm[i].dir = LEFT;
    }

    int total = factorial(n);
    for (int count = 0; count < total; count++) {
        printPermutation(perm, n);
        int mobileIndex = getLargestMobile(perm, n);
        if (mobileIndex == -1) break;

        int moveTo = mobileIndex + perm[mobileIndex].dir;
        swap(&perm[mobileIndex], &perm[moveTo]);
        reverseDirections(perm, n, perm[moveTo].value);
    }

    return 0;
}






/*#include <stdio.h>
#include <stdlib.h>
void swap(int* a, int* b) {
int temp = *a;
*a = *b;
*b = temp;
}
void generatePermutations(int arr[], int start, int end) {
if (start == end) {
for (int i = 0; i <= end; i++) {
printf("%d ", arr[i]);
}
printf("\n");
} else {
for (int i = start; i <= end; i++) {
swap(&arr[start], &arr[i]);
generatePermutations(arr, start + 1, end);
swap(&arr[start], &arr[i]); // backtrack
}
}
}
int main() {
int n;
printf("Enter the number of elements: ");
scanf("%d", &n);
int* arr = (int*)malloc(n * sizeof(int));
printf("Enter the elements: ");
for (int i = 0; i < n; i++) {
scanf("%d", &arr[i]);
}
generatePermutations(arr, 0, n - 1);
free(arr);
return 0;
}*/
