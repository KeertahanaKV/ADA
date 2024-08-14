#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count;

// Bubble sort with count of comparisons
int bubbleSort(int *a, int n) {
    count = 0;
    int i, j, t, flag;
    for (i = 0; i < n - 1; i++) {
        flag = 0;
        for (j = 0; j < n - i - 1; j++) {
            count++;
            if (a[j] > a[j + 1]) {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
    return count;
}

// Plotter function to analyze bubble sort
void plotter() {
    int *arr, n;
    srand(time(NULL));
    FILE *f1 = fopen("BUBBLEBEST.txt", "a");
    FILE *f2 = fopen("BUBBLEWORST.txt", "a");
    FILE *f3 = fopen("BUBBLEAVG.txt", "a");
    
    n = 10;
    while (n <= 30000) {
        arr = (int *)malloc(sizeof(int) * n);
        
        // Worst case
        for (int i = 0; i < n; i++)
            arr[i] = n - i;
        bubbleSort(arr, n);
        fprintf(f2, "%d\t%d\n", n, count);
        
        // Best case
        for (int i = 0; i < n; i++)
            arr[i] = i + 1;
        bubbleSort(arr, n);
        fprintf(f1, "%d\t%d\n", n, count);
        
        // Average case
        for (int i = 0; i < n; i++)
            arr[i] = rand() % n;
        bubbleSort(arr, n);
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

// Tester function to demonstrate bubble sort
void tester() {
    int *arr, n;
    printf("ENTER THE NUMBER OF ELEMENTS: ");
    scanf("%d", &n);
    
    arr = (int *)malloc(sizeof(int) * n);
    printf("ENTER THE ELEMENTS OF THE ARRAY: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    printf("ELEMENTS OF THE ARRAY BEFORE SORTING: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    bubbleSort(arr, n);
    
    printf("ELEMENTS OF THE ARRAY AFTER SORTING: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    free(arr);
}

int main() {
    int key;
    while (1) {
        printf("\nBubble sort\nENTER THE CHOICE:\n1. TO TEST\n2. TO PLOT\n0. TO EXIT\n");
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
