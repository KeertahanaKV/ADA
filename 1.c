#include <stdio.h>
#include <stdlib.h>

#define X 10
#define Y 100
int gcd;

// Euclid's algorithm
float euclid(int m, int n) {
  gcd=0;
    int r;
    float count = 0;
    while (n) {
        count++;
        r = m % n;
        m = n;
        n = r;
    }
    gcd=m;
    return count;
}

// Consecutive integer checking algorithm
float consec(int m, int n) {
  gcd=0;
    int min;
    float count = 0;
    min = m;
    if (n < min)
        min = n;
    while (1) {
        count++;
        if (m % min == 0) {
            count++;
            if (n % min == 0)
                break;
            min -= 1;
        } else
            min -= 1;
    }
  gcd=min;
    return count;
}

// Modified Euclid's algorithm
float modified(int m, int n) {
    int temp;
    float count = 0;
    while (n > 0) {
        if (n > m) {
            temp = m;
            m = n;
            n = temp;
        }
        m = m - n;
        count += 1;
    }
  gcd=m;
    return count; // m is the GCD
}

// Analysis function to generate best and worst case data
void analysis(int ch) {
    int m, n, i, j, k;
    float count, maxcount, mincount;
    FILE *fp1, *fp2;
    for (i = X; i <= Y; i += 10) {
        maxcount = 0;
        mincount = 10000;
        for (j = 2; j <= i; j++) {
            for (k = 2; k <= i; k++) {
                count = 0;
                m = j;
                n = k;
                switch (ch) {
                    case 1:
                        count = euclid(m, n);
                        break;
                    case 2:
                        count = consec(m, n);
                        break;
                    case 3:
                        count = modified(m, n);
                        break;
                }
                if (count > maxcount)
                    maxcount = count;
                if (count < mincount)
                    mincount = count;
            }
        }
        switch (ch) {
            case 1:
                fp2 = fopen("e_b.txt", "a");
                fp1 = fopen("e_w.txt", "a");
                break;
            case 2:
                fp2 = fopen("c_b.txt", "a");
                fp1 = fopen("c_w.txt", "a");
                break;
            case 3:
                fp2 = fopen("m_b.txt", "a");
                fp1 = fopen("m_w.txt", "a");
                break;
        }
        fprintf(fp2, "%d %.2f\n", i, mincount);
        fclose(fp2);
        fprintf(fp1, "%d %.2f\n", i, maxcount);
        fclose(fp1);
    }
}

int main() {
    int ch;
    while (1) {
        printf("GCD\n");
        printf("1. Euclid\n2. Modified Euclid\n3. Consecutive integer method\n4. Run Analysis\n0 to exit\n");
        scanf("%d", &ch);
        if (ch == 0)
            break;
        if (ch >= 1 && ch <= 3) {
            printf("ENTER THE VALUES M AND N\n");
            int m, n;
            scanf("%d", &m);
            scanf("%d", &n);
            float count = 0;
            switch (ch) {
                case 1:
                    count = euclid(m, n);
                    printf("THE GCD IS %d\n", gcd);
                    break;
                case 2:
                    count = modified(m, n);
                    printf("THE GCD IS %d\n", gcd);
                    break;
                case 3:
                    count = consec(m, n);
                    printf("THE GCD IS %d\n", gcd);
                    break;
            }
            printf("Basic operations count: %.2f\n", count);
        } else if (ch == 4) {
            printf("Running analysis...\n");
            printf("1. Euclid\n2. Modified Euclid\n3. Consecutive integer method\n");
            scanf("%d", &ch);
            if (ch >= 1 && ch <= 3) {
                analysis(ch);
            }
        } else {
            break;
        }
    }
    return 0;
}
