#include <stdio.h>

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

    int bucket[10000] = {0};

    for (int i = 0; i < n; i++)
        bucket[a[i]]++;

    printf("Sorted array:\n");
    for (int i = 0; i <= max; i++)
        while (bucket[i]--)
            printf("%d ", i);

    return 0;
}
