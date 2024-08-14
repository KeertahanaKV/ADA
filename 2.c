#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count;

// Sequential search
int linearSearch(int *a, int k, int n) {
    count = 0;
    for (int i = 0; i < n; i++) {
        count++;
        if (*(a + i) == k) {
            return count;
        }
    }
    return count;
}

// Binary search (recursive)
int binarySearch(int key, int *a, int high, int low) {
    int mid;
    count++;
    mid = low + (high - low) / 2; // To avoid potential overflow
    if (low > high)
        return count - 1;
    if (*(a + mid) == key)
        return count;
    else if (*(a + mid) > key)
        return binarySearch(key, a, mid - 1, low);
    else
        return binarySearch(key, a, high, mid + 1);
}

// Plotter function for linear search
void plotterLinearSearch() {
    srand(time(NULL));
    int *arr;
    int n, key, r;
    FILE *f1, *f2, *f3;
    
    f1 = fopen("linearbest.txt", "a");
    f2 = fopen("linearavg.txt", "a");
    f3 = fopen("linearworst.txt", "a");
    
    n = 2;
    while (n <= 1024) {
        arr = (int *)malloc(n * sizeof(int));
        
        // Linear Search Analysis
        // Best case: key is the first element
        for (int i = 0; i < n; i++)
            *(arr + i) = 1;
        r = linearSearch(arr, 1, n);
        fprintf(f1, "%d\t%d\n", n, r);
        
        // Average case: key is a random element
        for (int i = 0; i < n; i++)
            *(arr + i) = rand() % n;
        key = rand() % n;
        r = linearSearch(arr, key, n);
        fprintf(f2, "%d\t%d\n", n, r);
        
        // Worst case: key is not in the array
        for (int i = 0; i < n; i++)
            *(arr + i) = 0;
        r = linearSearch(arr, 1, n);
        fprintf(f3, "%d\t%d\n", n, r);
        
        n = n * 2;
        free(arr);
    }
    
    fclose(f1);
    fclose(f2);
    fclose(f3);
}

// Plotter function for binary search
void plotterBinarySearch() {
    srand(time(NULL));
    int *arr;
    int n, key, r;
    FILE *f1, *f2, *f3;
    
    f1 = fopen("binarybest.txt", "a");
    f2 = fopen("binaryavg.txt", "a");
    f3 = fopen("binaryworst.txt", "a");
    
    n = 2;
    while (n <= 1024) {
        arr = (int *)malloc(n * sizeof(int));
        
        // Binary Search Analysis
        // Best case: key is the middle element
        for (int i = 0; i < n; i++)
            *(arr + i) = 1;
        int mid = (n - 1) / 2;
        *(arr + mid) = 0;
        count = 0;
        r = binarySearch(0, arr, n - 1, 0);
        fprintf(f1, "%d\t%d\n", n, r);
        
        // Average case: key is a random element
        for (int i = 0; i < n; i++)
            *(arr + i) = rand() % n;
        key = rand() % n + 1;
        count = 0;
        r = binarySearch(-1, arr, n - 1, 0);
        fprintf(f2, "%d\t%d\n", n, r);
        
        // Worst case: key is not in the array
        for (int i = 0; i < n; i++)
            *(arr + i) = 0;
        count = 0;
        r = binarySearch(1, arr, n - 1, 0);
        fprintf(f3, "%d\t%d\n", n, r);
        
        n = n * 2;
        free(arr);
    }
    
    fclose(f1);
    fclose(f2);
    fclose(f3);
}

int main() {
    int arr[100];
    int n, key, r;
    for (;;) {
        printf("ENTER 1. TO LINEAR SEARCH\n2. TO BINARY SEARCH\n3. RUN PLOTTER \n0. Exit\n");
        int ch;
        scanf("%d", &ch);
        switch (ch) {
            case 0:printf("\nExiting from the program\n");
            	   exit(0);
            case 1:
                printf("ENTER THE NUMBER OF ELEMENTS\n");
                scanf("%d", &n);
                printf("ENTER THE ELEMENTS OF THE ARRAY\n");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                printf("ENTER THE KEY ELEMENT\n");
                scanf("%d", &key);
                r = linearSearch(arr, key, n);
                if (r != -1) {
                    printf("The element is present at the index %d\n", r);
                } else {
                    printf("Element not found\n");
                }
                break;
            case 2:
                printf("ENTER THE NUMBER OF ELEMENTS\n");
                scanf("%d", &n);
                printf("ENTER THE ELEMENTS OF THE ARRAY\n");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                printf("ENTER THE KEY ELEMENT\n");
                scanf("%d", &key);
                r = binarySearch(key, arr, n - 1, 0);
                if (r != -1) {
                    printf("The element is present at the index %d\n", r);
                } else {
                    printf("Element not found\n");
                }
                break;
            case 3:
                plotterLinearSearch();
                printf("Linear search plotter executed.\n");
                plotterBinarySearch();
                printf("Binary search plotter executed.\n");
                break;
            default:
                exit(0);
        }
    }
    return 0;
}
