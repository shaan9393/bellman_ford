#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define INF INT_MAX


int minDistance(int dist[], bool visited[], int V) {
    int min = INF, min_index;

    for (int v = 0; v < V; v++)
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }

    return min_index;
}


void dijkstra(int graph[100][100], int V, int src) {
    int dist[V];         
    bool visited[V];     
   
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[src] = 0;

   
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited, V);
        visited[u] = true;

        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INF
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printf("Vertex\tDistance from Source %d\n", src);
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            printf("%d\t\tINF\n", i);
        else
            printf("%d\t\t%d\n", i, dist[i]);
    }
}

int main() {
    int V;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    int graph[100][100];

    printf("Enter the adjacency matrix (use 0 for no edge):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
            if (i != j && graph[i][j] == 0)
                graph[i][j] = INF;  
        }
    }

    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    dijkstra(graph, V, source);

    return 0;
}

