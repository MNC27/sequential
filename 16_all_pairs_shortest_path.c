#include <stdio.h>

#define INF 999999

int main() {
    int n, d[100][100];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter weighted adjacency matrix (0 means no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &d[i][j]);
            if (i != j && d[i][j] == 0)
                d[i][j] = INF;
        }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (d[i][k] < INF && d[k][j] < INF &&
                    d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];

    printf("All-pairs shortest path matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            if (d[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", d[i][j]);
        printf("\n");
    }

    return 0;
}
