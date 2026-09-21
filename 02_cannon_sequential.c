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

    for (int bi = 0; bi < q; bi++) {
        for (int bj = 0; bj < q; bj++) {
            for (int bk = 0; bk < q; bk++) {
                int shiftedA = (bj + bk) % q;
                int shiftedB = (bi + bk) % q;

                for (int i = 0; i < b; i++) {
                    for (int j = 0; j < b; j++) {
                        for (int k = 0; k < b; k++) {
                            C[bi*b+i][bj*b+j] +=
                                A[bi*b+i][shiftedA*b+k] *
                                B[shiftedB*b+k][bj*b+j];
                        }
                    }
                }
            }
        }
    }

    printf("Result using sequential Cannon-style block computation:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    return 0;
}
