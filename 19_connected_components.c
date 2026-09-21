#include <stdio.h>

int n, graph[100][100], visited[100];

void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < n; i++)
        if (graph[v][i] && !visited[i])
            dfs(i);
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 or 1):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    int count = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            count++;
            printf("Component %d: ", count);
            dfs(i);
            printf("\n");
        }
    }

    printf("Number of connected components = %d\n", count);
    return 0;
}
