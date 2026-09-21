#include <stdio.h>

int main() {
    int n;
    double a[100][101], x[100];

    printf("Enter number of equations: ");
    scanf("%d", &n);

    printf("Enter augmented matrix [A | b]:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n; j++)
            scanf("%lf", &a[i][j]);

    for (int k = 0; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            double factor = a[i][k] / a[k][k];
            for (int j = k; j <= n; j++)
                a[i][j] -= factor * a[k][j];
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        x[i] = a[i][n];
        for (int j = i + 1; j < n; j++)
            x[i] -= a[i][j] * x[j];
        x[i] /= a[i][i];
    }

    printf("Solution:\n");
    for (int i = 0; i < n; i++)
        printf("x%d = %.3lf\n", i + 1, x[i]);

    return 0;
}
