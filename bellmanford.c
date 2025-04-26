#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

struct Edge {
    int src, dest, weight;
};

void bellmanFord(int vertices, int edgesCount, struct Edge edgeList[], int source) {
    int *dist = (int *)malloc(vertices * sizeof(int));
    for (int i = 0; i < vertices; i++) {
        dist[i] = INF;
    }
    dist[source] = 0;

    // Step 2: Relax all edges |V| - 1 times
    for (int i = 1; i <= vertices - 1; i++) {
        for (int j = 0; j < edgesCount; j++) {
            int u = edgeList[j].src;
            int v = edgeList[j].dest;
            int weight = edgeList[j].weight;
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    
    for (int j = 0; j < edgesCount; j++) {
        int u = edgeList[j].src;
        int v = edgeList[j].dest;
        int weight = edgeList[j].weight;
        if (dist[u] != INF && dist[u] + weight < dist[v]) {
            printf("Graph contains a negative weight cycle\n");
            free(dist);
            return;
        }
    }

    printf("Vertex\tDistance from Source %d\n", source);
    for (int i = 0; i < vertices; i++) {
        if (dist[i] == INF)
            printf("%d\t\tINF\n", i);
        else
            printf("%d\t\t%d\n", i, dist[i]);
    }

    free(dist);
}

int main() {
    int V, E, source;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    struct Edge *edgeList = (struct Edge *)malloc(E * sizeof(struct Edge));

    printf("Enter each edge in the format: source destination weight\n");
    for (int i = 0; i < E; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &edgeList[i].src, &edgeList[i].dest, &edgeList[i].weight);
    }

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    bellmanFord(V, E, edgeList, source);

    free(edgeList);
    return 0;
}

