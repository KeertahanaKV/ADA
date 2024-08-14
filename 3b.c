#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count;

void insertionSort(int *arr, int n) {
    count = 0;
    for (int i = 1; i < n; i++) {
        int value = arr[i];
        int j = i - 1;
        while (j >= 0 && count++ && arr[j] > value) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = value;
    }
}

void plotter() {
    int *arr, n;
    srand(time(NULL));
    FILE *f1 = fopen("INSERTIONBEST.txt", "a");
    FILE *f2 = fopen("INSERTIONWORST.txt", "a");
    FILE *f3 = fopen("INSERTIONAVG.txt", "a");
    
    n = 10;
    while (n <= 30000) {
        arr = (int *)malloc(sizeof(int) * n);
        
        // Worst case
        for (int i = 0; i < n; i++)
            arr[i] = n - i;
        insertionSort(arr, n);
        fprintf(f2, "%d\t%d\n", n, count);
        
        // Best case
        for (int i = 0; i < n; i++)
            arr[i] = i + 1;
        insertionSort(arr, n);
        fprintf(f1, "%d\t%d\n", n, count);
        
        // Average case
        for (int i = 0; i < n; i++)
            arr[i] = rand() % n;
        insertionSort(arr, n);
        fprintf(f3, "%d\t%d\n", n, count);
        
        if (n < 10000)
            n *= 10;
        else
            n += 10000;
        
        free(arr);
    }
    
    fclose(f1);
    fclose(f2);
    fclose(f3);
}

void tester() {
    int *arr, n;
    printf("ENTER THE NUMBER OF ELEMENTS: ");
    scanf("%d", &n);
    
    arr = (int *)malloc(sizeof(int) * n);
    printf("ENTER THE ELEMENTS OF THE ARRAY: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    printf("THE ELEMENTS OF THE ARRAY BEFORE SORTING: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    insertionSort(arr, n);
    
    printf("THE ELEMENTS OF THE ARRAY AFTER SORTING: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    free(arr);
}

int main() {
    int key;
    while (1) {
        printf("ENTER THE CHOICE:\n1. TO TEST\n2. TO PLOT\n0. TO EXIT\n");
        scanf("%d", &key);
        
        switch (key) {
            case 1:
                tester();
                break;
            case 2:
                plotter();
                break;
            case 0:
                exit(0);
            default:
                printf("INVALID CHOICE! TRY AGAIN.\n");
        }
    }
    
    return 0;
}
