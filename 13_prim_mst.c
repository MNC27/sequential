#include <stdio.h>

#define INF 999999

int main() {
    int n, graph[100][100], selected[100] = {0};
    int total = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter weighted adjacency matrix (0 means no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    selected[0] = 1;

    printf("Edges in MST:\n");

    for (int edge = 0; edge < n-1; edge++) {
        int min = INF, x = -1, y = -1;

        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && graph[i][j] &&
                        graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        if (x == -1) {
            printf("Graph is disconnected.\n");
            return 0;
        }

        printf("%d - %d : %d\n", x, y, min);
        total += min;
        selected[y] = 1;
    }

    printf("Total MST weight = %d\n", total);
    return 0;
}
