#include <stdio.h>

void countingSort(int a[], int n, int exp) {
    int output[1000];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i-1];

    for (int i = n-1; i >= 0; i--) {
        int d = (a[i] / exp) % 10;
        output[count[d]-1] = a[i];
        count[d]--;
    }

    for (int i = 0; i < n; i++)
        a[i] = output[i];
}

int main() {
    int n, a[1000], max = 0;

    printf("Enter number of non-negative integers: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] > max)
            max = a[i];
    }

    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(a, n, exp);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
