#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int count = 0;

int stringmatching(char *text, char *pattern, int n, int m) {
    count = 0;
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m) {
            count++;
            if (pattern[j] != text[i + j])
                break;
            j++;
        }
        if (j == m) {
            printf("THE PATTERN FOUND\n");
            printf("Found at position %d\n",i+1);
            return count;
        }
    }
    printf("THE PATTERN NOT FOUND\n");
    return count;
}

void plotter() {
    FILE *f1 = fopen("stringbest.txt", "a");
    FILE *f2 = fopen("stringworst.txt", "a");
    FILE *f3 = fopen("stringavg.txt", "a");
    char *text = (char *)malloc(1000 * sizeof(char));
    char *pattern;
    for (int i = 0; i < 1000; i++)
        *(text + i) = 'a';

    int m = 10;
    int n = 1000;
    printf("\nPlotter fucntion output\n");
    while (m <= 1000) {
        pattern = (char *)malloc(m * sizeof(char));
        
        // Best case
        for (int i = 0; i < m; i++)
            pattern[i] = 'a';
        count = 0;
        stringmatching(text, pattern, n, m);
        fprintf(f1, "%d\t%d\n", m, count);
        
        // Worst case
        pattern[m - 1] = 'b';
        count = 0;
        stringmatching(text, pattern, n, m);
        fprintf(f2, "%d\t%d\n", m, count);
        
        // Average case
        for (int i = 0; i < m; i++)
            pattern[i] = 97 + rand() % 3;
        count = 0;
        stringmatching(text, pattern, n, m);
        fprintf(f3, "%d\t%d\n", m, count);
        
        free(pattern);
        if (m < 100)
            m += 10;
        else
            m += 100;
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
    free(text);
}

int main() {
    int m, n;
    char text[100], pattern[100];
    
    printf("ENTER THE PATTERN LENGTH: ");
    scanf("%d", &m);
    printf("ENTER THE PATTERN: ");
    getchar(); // Consume the newline character left in the input buffer
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = '\0'; // Remove the newline character from the input
    
    printf("ENTER THE TEXT LENGTH: ");
    scanf("%d", &n);
    printf("ENTER THE TEXT: ");
    getchar(); // Consume the newline character left in the input buffer
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; // Remove the newline character from the input
    
    int comparisons = stringmatching(text, pattern, n, m);
    printf("Number of comparisons: %d\n", comparisons);
    
    // To run the plotter
    plotter();
    
    return 0;
}
