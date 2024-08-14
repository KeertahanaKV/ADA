#include <stdio.h>
#include <stdlib.h>
#include <limits.h>  // For INT_MAX

#define MAX 40

int graph[MAX][MAX], n, count = 0;

// Function to create a graph by reading the adjacency matrix from user input
void createGraph() {
    printf("Number of vertices >> ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j) {
                graph[i][j] = INT_MAX;  // Use a large number to represent infinity
            }
        }
    }
}

// Function to apply Floyd-Warshall's algorithm and compute shortest paths
void floydWarshall() {
    int temp;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            temp = graph[i][k];
            for (int j = 0; j < n; j++) {
                if (graph[i][j] > temp) {
                    count++;
                    if (temp + graph[k][j] < graph[i][j]) {
                        graph[i][j] = temp + graph[k][j];
                    }
                }
            }
        }
    }
}

// Function to generate random graphs for testing
void createRandomGraph(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = rand() % 100 + 1;  // Random weights between 1 and 100
            }
        }
    }
}

// Main function for user input or performance testing
int main() {
    int choice;
    
    printf("Choose an option:\n1. Run Floyd-Warshall's algorithm on user-defined graph\n2. Generate and test random graphs\n");
    scanf("%d", &choice);

    if (choice == 1) {
        createGraph();
        floydWarshall();
        printf("Applying Floyd's algorithm\n");
        printf("All pair shortest path matrix:\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j] == INT_MAX) {
                    printf("INF ");
                } else {
                    printf("%d ", graph[i][j]);
                }
            }
            printf("\n");
        }
        printf("Operation count: %d\n", count);
    } else if (choice == 2) {
        FILE *fp = fopen("floyd_general.txt", "w");
        if (fp == NULL) {
            printf("Error opening file!\n");
            return 1;
        }
        for (n = 2; n < 12; n++) {
            count = 0;
            createRandomGraph(n);
            floydWarshall();
            fprintf(fp, "%d\t%d\n", n, count);
        }
        fclose(fp);
        printf("Performance data has been saved to 'floyd_general.txt'\n");
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
