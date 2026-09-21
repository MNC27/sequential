#include <stdio.h>

int main() {
    int n, graph[100][100], selected[100] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 or 1):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for (int v = 0; v < n; v++) {
        int possible = 1;

        for (int u = 0; u < v; u++)
            if (selected[u] && graph[v][u]) {
                possible = 0;
                break;
            }

        if (possible)
            selected[v] = 1;
    }

    printf("Maximal independent set:\n");
    for (int i = 0; i < n; i++)
        if (selected[i])
            printf("%d ", i);

    return 0;
}
