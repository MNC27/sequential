#include <stdio.h>

int main() {
    int n, m, p;
    int A[100][100], B[100][100], C[100][100] = {0};

    printf("Enter rows of A, columns of A, and columns of B: ");
    scanf("%d%d%d", &n, &m, &p);

    printf("Enter matrix A:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &A[i][j]);

    printf("Enter matrix B:\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++)
            scanf("%d", &B[i][j]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++)
            for (int k = 0; k < m; k++)
                C[i][j] += A[i][k] * B[k][j];

    printf("Result:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }
    return 0;
}
