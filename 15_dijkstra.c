#include <stdio.h>

#define INF 999999

int main() {
    int n, graph[100][100], source;
    int d[100], used[100] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter weighted adjacency matrix (0 means no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter source vertex: ");
    scanf("%d", &source);

    for (int i = 0; i < n; i++)
        d[i] = INF;

    d[source] = 0;

    for (int count = 0; count < n; count++) {
        int u = -1;

        for (int i = 0; i < n; i++)
            if (!used[i] && (u == -1 || d[i] < d[u]))
                u = i;

        if (u == -1 || d[u] == INF)
            break;

        used[u] = 1;

        for (int v = 0; v < n; v++)
            if (graph[u][v] && d[u] + graph[u][v] < d[v])
                d[v] = d[u] + graph[u][v];
    }

    printf("Shortest distances:\n");
    for (int i = 0; i < n; i++)
        printf("%d -> %d = %d\n", source, i, d[i]);

    return 0;
}
