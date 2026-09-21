#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void merge(int a[], int low, int count, int direction) {
    if (count > 1) {
        int k = count / 2;

        for (int i = low; i < low + k; i++)
            if ((direction && a[i] > a[i+k]) ||
                (!direction && a[i] < a[i+k]))
                swap(&a[i], &a[i+k]);

        merge(a, low, k, direction);
        merge(a, low+k, k, direction);
    }
}

void sort(int a[], int low, int count, int direction) {
    if (count > 1) {
        int k = count / 2;
        sort(a, low, k, 1);
        sort(a, low+k, k, 0);
        merge(a, low, count, direction);
    }
}

int main() {
    int n, a[1024];

    printf("Enter number of elements (power of 2): ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    sort(a, 0, n, 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
