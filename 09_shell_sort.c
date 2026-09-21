#include <stdio.h>

int main() {
    int n, a[1000];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = a[i];
            int j;

            for (j = i; j >= gap && a[j-gap] > temp; j -= gap)
                a[j] = a[j-gap];

            a[j] = temp;
        }
    }

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
