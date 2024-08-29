#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int counter = 0;

// Function to create the graph by reading the adjacency matrix
void createGraph(int *n) {
    printf("No. of vertices >> ");
    scanf("%d", n);
    printf("Enter adjacency matrix:\n");
    for (int i = 1; i <= *n; i++) {
        for (int j = 1; j <= *n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}

// Warshall's algorithm to find the transitive closure
void warshall(int n) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (graph[i][k] != 0) {
                for (int j = 1; j <= n; j++) {
                    graph[i][j] = (graph[i][j] || (graph[i][k] && graph[k][j]));
                    counter++;
                }
            }
        }
    }
}

// Function to plot the results
void plotter(int c) {
    FILE *f1 = fopen("warshallbest.txt", "a");
    FILE *f2 = fopen("warshallworst.txt", "a");

    for (int i = 1; i <= 10; i++) {
        int n = i;

        if (c == 1) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (i != j) {
                        graph[i][j] = 1;
                    } else {
                        graph[i][j] = 0;
                    }
                }
            }
        } else {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    graph[i][j] = 0;
                }
            }
            for (int i = 1; i < n; i++) {
                graph[i][i + 1] = 1;
            }
            graph[n][1] = 1;
        }

        counter = 0;
        warshall(n);

        if (c == 0) {
            fprintf(f1, "%d\t%d\n", n, counter);
        } else {
            fprintf(f2, "%d\t%d\n", n, counter);
        }
    }

    fclose(f1);
    fclose(f2);
}

int main() {
    int n;
    int choice;

    printf("Choose an option:\n1. Run Warshall's algorithm on user-defined graph\n2. Generate and plot graphs\n");
    scanf("%d", &choice);

    if (choice == 1) {
        createGraph(&n);
        warshall(n);
        printf("Transitive Closure Matrix:\n");
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                printf("%d ", graph[i][j]);
            }
            printf("\n");
        }
        printf("Operation Count: %d\n", counter);
    } else if (choice == 2) {
        for (int i = 0; i < 2; i++) {
            plotter(i);
        }
        printf("The graph is plotted\n");
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
