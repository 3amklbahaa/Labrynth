#include <stdio.h>

void readarray(int t[100][100], int r, int c) {
    int i, j;

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            do {
                printf("Please enter t[%d][%d] (0 or 1): ", i, j);
                scanf("%d", &t[i][j]);
            } while (t[i][j] != 0 && t[i][j] != 1);
        }
    }
}

void print(int t[100][100], int r, int c) {
    int i, j;

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if(t[i][j]==2){
                printf("X ");
            }
            else{
                printf("%d ", t[i][j]);
            }
        }
        printf("\n");
    }
}

int findpath(int t[100][100], int r, int c, int x, int y, int x2, int y2) {
    if (x == x2 && y == y2) {
        t[x][y]=2;
        // Reached the target cell, return success.
        return 1;
    }

    if (x < 0 || x >= r || y < 0 || y >= c || t[x][y] != 0) {
        // Out of bounds or blocked cell, return failure.
        return 0;
    }

    // Mark the cell as visited by changing its value to 2.
    t[x][y] = 2;

    // Try moving in all four directions: up, down, left, and right.
    if (findpath(t, r, c, x - 1, y, x2, y2) ||
        findpath(t, r, c, x + 1, y, x2, y2) ||
        findpath(t, r, c, x, y - 1, x2, y2) ||
        findpath(t, r, c, x, y + 1, x2, y2)) {
        // If any of the recursive calls finds a path to the target, return success.
        return 1;
    }

    // If none of the directions leads to the target, unmark the cell and return failure.
    t[x][y] = 0;
    return 0;
}

int main() {
    int n;
    do {
        printf("Enter the maze dimension: ");
        scanf("%d", &n);
    } while (n <= 0);

    int t[100][100];
    readarray(t, n, n);
    printf("Maze:\n");
    print(t, n, n);

    int x, y, x2, y2;
    printf("Enter the source cell coordinates (x y): ");
    scanf("%d %d", &x, &y);
    printf("Enter the target cell coordinates (x y): ");
    scanf("%d %d", &x2, &y2);

    if (findpath(t, n, n, x, y, x2, y2)) {
        printf("Path found!\n");
        printf("Maze with path marked:\n");
        print(t, n, n);
    } else {
        printf("No path found.\n");
    }

    return 0;
}
