#include<stdio.h>
#include<time.h>

int a[20], n;

void simplesort(int a[], int low, int mid, int high) {
    int c[high - low + 1];
    int i = low, j = mid + 1, k = 0;

    while (i <= mid && j <= high) {
        if (a[i] < a[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = a[j++];
        }
    }

    while (i <= mid) {
        c[k++] = a[i++];
    }

    while (j <= high) {
        c[k++] = a[j++];
    }

    for (i = low, k = 0; i <= high; i++, k++) {
        a[i] = c[k];
    }
}

void mergesort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        simplesort(a, low, mid, high);
    }
}

void main() {
    clock_t start, end;
    printf("Enter the number of elements in the array\n");
    scanf("%d", &n);
    printf("Enter %d Elements\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    start = clock();
    mergesort(a, 0, n - 1);
    end = clock();
    double tt = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    printf("\nTime taken: %.3f seconds\n", tt);
}
