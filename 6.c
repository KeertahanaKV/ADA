#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count;

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for quicksort
int partition(int *arr, int beg, int end) {
    int pivot = arr[beg];
    int i = beg, j = end + 1;

    do {
        do {
            count++;
            i++;
        } while (i <= end && arr[i] < pivot);
        
        do {
            count++;
            j--;
        } while (arr[j] > pivot);
        
        if (i < j)
            swap(&arr[i], &arr[j]);
    } while (i < j);

    swap(&arr[beg], &arr[j]);
    return j;
}

// Recursive quicksort function
void quicksort(int *arr, int beg, int end) {
    if (beg < end) {
        int split = partition(arr, beg, end);
        quicksort(arr, beg, split - 1);
        quicksort(arr, split + 1, end);
    }
}

void plotter() {
    int *arr, n;
    srand(time(NULL));
    FILE *f1, *f2, *f3;

    f1 = fopen("QUICKBEST.txt", "a");
    f2 = fopen("QUICKWORST.txt", "a");
    f3 = fopen("QUICKAVG.txt", "a");

    for (n = 4; n < 1034; n = n * 2) {
        arr = (int *)malloc(sizeof(int) * n);

        // Best case
        for (int i = 0; i < n; i++)
            arr[i] = 5; // All elements are the same
        count = 0;
        quicksort(arr, 0, n - 1);
        fprintf(f1, "%d\t%d\n", n, count);

        // Worst case
        for (int i = 0; i < n; i++)
            arr[i] = i + 1; // Sorted array
        count = 0;
        quicksort(arr, 0, n - 1);
        fprintf(f2, "%d\t%d\n", n, count);

        // Average case
        for (int i = 0; i < n; i++)
            arr[i] = rand() % n;
        count = 0;
        quicksort(arr, 0, n - 1);
        fprintf(f3, "%d\t%d\n", n, count);

        free(arr);
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);
    printf("DATA IS ENTERED INTO FILE\n");
}

void tester() {
    int *arr, n;

    printf("ENTER THE NUMBER OF ELEMENTS\n");
    scanf("%d", &n);

    arr = (int *)malloc(sizeof(int) * n);

    printf("ENTER THE ELEMENTS OF THE ARRAY\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("THE ELEMENTS OF THE ARRAY BEFORE SORTING\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    quicksort(arr, 0, n - 1);

    printf("THE ELEMENTS OF THE ARRAY AFTER SORTING\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    free(arr);
}

int main() {
    int choice;
    printf("Enter 1 for Tester, 2 for Plotter: ");
    scanf("%d", &choice);

    if (choice == 1) {
        tester();
    } else if (choice == 2) {
        plotter();
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}
