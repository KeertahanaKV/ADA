#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 15
#define INF 999

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int n, int start) {
    int dist[MAX_VERTICES];
    int s[MAX_VERTICES] = {0}; // Shortest path set
    int u, v, min, i, j;
    int count=0;

    // Initialize distances and shortest path set
    for (i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;

    for (i = 0; i < n - 1; i++) {
        // Find the vertex with the minimum distance that hasn't been processed
        min = INF;
        for (j = 0; j < n; j++) {
        	count++;
            if (!s[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        // Mark the chosen vertex as processed
        s[u] = 1;

        // Update the distances to the neighboring vertices
        for (v = 0; v < n; v++) {
            if (!s[v] && graph[u][v] != INF && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the results
    printf("Vertex\tDistance from Source\n");
    for (i = 0; i < n; i++) {
        if (dist[i] == INF) {
            printf("%d\t\tINF\n", i);
        } else {
            printf("%d\t\t%d\n", i, dist[i]);
        }
    }
    printf("No of operations=%d\n",count);
}

int main() {
    int n, graph[MAX_VERTICES][MAX_VERTICES], i, j, cost;

    // Input number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input the cost matrix
    printf("Enter the cost matrix (enter %d for no edge):\n", INF);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 999) {
                graph[i][j] = INF;
            }
        }
    }

    // Input the source vertex
    int start;
    printf("Enter the source vertex: ");
    scanf("%d", &start);

    // Run Dijkstra's algorithm
    dijkstra(graph, n, start);

    return 0;
}
}
