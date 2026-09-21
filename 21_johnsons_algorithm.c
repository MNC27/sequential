#include <stdio.h>

#define INF 999999

struct Edge {
    int u, v, w;
};

int main() {
    int n, m;
    struct Edge e[1000];
    int h[100], result[100][100];

    printf("Enter number of vertices and edges: ");
    scanf("%d%d", &n, &m);

    printf("Enter each directed edge as: source destination weight\n");
    for (int i = 0; i < m; i++)
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);

    for (int i = 0; i < n; i++)
        h[i] = 0;

    for (int k = 0; k < n - 1; k++)
        for (int i = 0; i < m; i++)
            if (h[e[i].u] + e[i].w < h[e[i].v])
                h[e[i].v] = h[e[i].u] + e[i].w;

    for (int s = 0; s < n; s++) {
        int d[100], used[100] = {0};

        for (int i = 0; i < n; i++)
            d[i] = INF;

        d[s] = 0;

        for (int count = 0; count < n; count++) {
            int u = -1;

            for (int i = 0; i < n; i++)
                if (!used[i] && (u == -1 || d[i] < d[u]))
                    u = i;

            if (u == -1 || d[u] == INF)
                break;

            used[u] = 1;

            for (int i = 0; i < m; i++) {
                if (e[i].u == u) {
                    int v = e[i].v;
                    int w = e[i].w + h[u] - h[v];

                    if (d[u] + w < d[v])
                        d[v] = d[u] + w;
                }
            }
        }

        for (int v = 0; v < n; v++) {
            if (d[v] == INF)
                result[s][v] = INF;
            else
                result[s][v] = d[v] - h[s] + h[v];
        }
    }

    printf("All-pairs shortest path matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            if (result[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", result[i][j]);
        printf("\n");
    }

    return 0;
}
