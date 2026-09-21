#include <stdio.h>

int main() {
    int n, b;
    int A[100][100], B[100][100], C[100][100] = {0};

    printf("Enter matrix size N: ");
    scanf("%d", &n);

    printf("Enter block size: ");
    scanf("%d", &b);

    if (n % b != 0) {
        printf("Matrix size must be divisible by block size.\n");
        return 0;
    }

    printf("Enter matrix A:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter matrix B:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    int q = n / b;

    for (int i = 0; i < q; i++) {
        for (int j = 0; j < q; j++) {
            for (int k = 0; k < q; k++) {
                for (int x = 0; x < b; x++) {
                    for (int y = 0; y < b; y++) {
                        for (int z = 0; z < b; z++) {
                            C[i*b+x][j*b+y] +=
                                A[i*b+x][k*b+z] *
                                B[k*b+z][j*b+y];
                        }
                    }
                }
            }
        }
    }

    printf("Result using sequential DNS-style 3D block computation:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    return 0;
}
