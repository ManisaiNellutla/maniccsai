#include<stdio.h>

#define MAX 5  // Number of nodes

void main() {
    int cost[MAX][MAX];  // Cost matrix
    int path[10][MAX];   // Paths array (up to 10 paths of length 5)
    int total_cost[10];  // Total costs for each path
    int num_paths, i, j, min_cost, min_index;

    // Input the cost matrix
    printf("Enter the cost matrix (%dx%d):\n", MAX, MAX);
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    // Input number of paths
    printf("Enter the number of paths:\n");
    scanf("%d", &num_paths);

    // Input the paths
    printf("Enter the paths (each path must have %d nodes):\n", MAX);
    for (i = 0; i < num_paths; i++) {
        for (j = 0; j < MAX; j++) {
            scanf("%d", &path[i][j]);
        }
    }

    // Calculate costs for each path
    for (i = 0; i < num_paths; i++) {
        total_cost[i] = 0;  // Initialize cost to 0
        for (j = 0; j < MAX - 1; j++) {
            int from = path[i][j] - 1;  // Convert to 0-based index
            int to = path[i][j + 1] - 1;  // Convert to 0-based index
            total_cost[i] += cost[from][to];
        }
    }

    // Find the minimum cost path
    min_cost = total_cost[0];
    min_index = 0;
    for (i = 1; i < num_paths; i++) {
        if (total_cost[i] < min_cost) {
            min_cost = total_cost[i];
            min_index = i;
        }
    }

    // Output the results
    printf("Minimum cost: %d\n", min_cost);
    printf("Minimum cost path: ");
    for (i = 0; i < MAX; i++) {
        printf("%d ", path[min_index][i]);
    }
    printf("\n");
}
