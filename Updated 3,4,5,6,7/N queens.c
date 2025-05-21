#include <stdio.h>
#include <stdlib.h>  // Required for abs()
#include <stdbool.h>

#define MAX 20

int board[MAX];
int N;

// Function to print the solution
void printSolution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i] == j)
                printf(" Q ");
            else
                printf(" . ");
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if the queen can be placed safely
bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        // Check column and diagonal conflicts
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

// Recursive backtracking function
void solveNQueens(int row) {
    if (row == N) {
        printSolution();  // A valid solution is found
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solveNQueens(row + 1);
            // No need to reset board[row], it will be overwritten
        }
    }
}

int main() {
    printf("Enter the number of queens (N): ");
    scanf("%d", &N);

    if (N < 1 || N > MAX) {
        printf("Invalid input. N must be between 1 and %d.\n", MAX);
        return 1;
    }

    printf("Solutions for %d-Queens problem:\n\n", N);
    solveNQueens(0);

    return 0;
}
