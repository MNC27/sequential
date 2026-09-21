#include <stdio.h>

int main() {
    int n, a[1000];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int phase = 0; phase < n; phase++) {
        int start = phase % 2;

        for (int i = start; i < n - 1; i += 2) {
            if (a[i] > a[i+1]) {
                int t = a[i];
                a[i] = a[i+1];
                a[i+1] = t;
            }
        }
    }

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
