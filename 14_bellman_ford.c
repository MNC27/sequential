#include <stdio.h>

#define INF 999999

struct Edge {
    int u, v, w;
};

int main() {
    int n, m, source;
    struct Edge e[1000];
    int d[100];

    printf("Enter number of vertices and edges: ");
    scanf("%d%d", &n, &m);

    printf("Enter each directed edge as: source destination weight\n");
    for (int i = 0; i < m; i++)
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);

    printf("Enter source vertex: ");
    scanf("%d", &source);

    for (int i = 0; i < n; i++)
        d[i] = INF;

    d[source] = 0;

    for (int i = 1; i < n; i++)
        for (int j = 0; j < m; j++)
            if (d[e[j].u] != INF &&
                d[e[j].u] + e[j].w < d[e[j].v])
                d[e[j].v] = d[e[j].u] + e[j].w;

    for (int i = 0; i < m; i++)
        if (d[e[i].u] != INF &&
            d[e[i].u] + e[i].w < d[e[i].v]) {
            printf("Negative weight cycle exists.\n");
            return 0;
        }

    printf("Shortest distances:\n");
    for (int i = 0; i < n; i++)
        printf("%d -> %d = %d\n", source, i, d[i]);

    return 0;
}
