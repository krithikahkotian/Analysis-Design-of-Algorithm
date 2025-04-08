#include <stdio.h>

int i, j, n, c, w[10], p[10], v[10][10];

void knapsack(int n, int w[10], int p[10], int c) {
    int max(int, int);
    for (i=0; i<= n; i++) {
        for (j=0; j<= c; j++) {
            if (i == 0 || j == 0)
                v[i][j] = 0;
            else if (w[i] > j)
                v[i][j] = v[i - 1][j];
            else
                v[i][j] = max(v[i - 1][j], (v[i - 1][j - w[i]] + p[i]));
        }
    }
    printf("\n\nMaximum Profit is : %d", v[n][c]);
    printf("\n\n\nTable :\n\n");
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= c; j++) {
            printf("\t%d", v[i][j]);
        }
        printf("\n");
    }
}

int max(int a, int b) {
    return ((a > b) ? a : b);
}

int main() {
    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &c);

    printf("Enter the weights and profits of the items:\n");
    for (i = 1; i <= n; i++) {
        printf("Item %d weight: ", i);
        scanf("%d", &w[i]);
        printf("Item %d profit: ", i);
        scanf("%d", &p[i]);
    }

    knapsack(n, w, p, c);

    return 0;
}
