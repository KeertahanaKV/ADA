#include<stdio.h>
#include<stdlib.h>

int mat[30][30],w[30],p[30],Count;
int Max(int a,int b){
    return (a>b)?a:b;
}

int knap(int n,int C){
    Count = 0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=C;j++){
            Count++;
            if(i==0 || j==0){
                Count--;
                mat[i][j] = 0;
            }
            else if(j < w[i])
                mat[i][j] = mat[i-1][j];
            else
                mat[i][j] = Max(mat[i-1][j] , (p[i] + mat[i-1][j-w[i]]));
        }
    }
    return mat[n][C];
}

void tester()
{
    int n,C;
    printf("\nEnter the no. of items :");
    scanf("%d",&n);
    printf("\nEnter the weight and profit \n");
    for(int i=1;i<=n;i++)
        scanf("%d %d",&w[i],&p[i]);
    printf("\nEnter the max capacity ");
    scanf("%d",&C);
    printf("\nI  W  P\n");
    for(int i=0;i<=n;i++)
        printf("%d  %d  %d\n",i,w[i],p[i]);
    printf("\nThe max profit is %d\n",knap(n,C));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=C;j++)
            printf("%d  ",mat[i][j]);
        printf("\n");
    }
    int j=C;
    printf("\nComposition : ");
    for(int i=n;i>0 && j>0 ; i--){
        if(mat[i][j] != mat[i-1][j]){
            j -= w[i];
            printf("%d  ",i);
        }
    }
}

void plotter()
{
    FILE *f1;
    f1 = fopen("knap.txt","w");
    int c;
    for(int i=1;i<=40;i+=4){
        c = i+3;
        for(int j=1;j<=i;j++){
            w[j] = rand()%i;
            p[i] = rand()%100;
        }
        knap(i,c);
        fprintf(f1,"%d\t%d\n",i,Count);
    }
    fclose(f1);
}

void main()
{
    while(1){
        int ch;
        printf("\nEnter 1.for tester 2.for plotter 3.to exit  ");
        scanf("%d",&ch);
        switch(ch){
            case 1 : tester();break;
            case 2 : plotter();break;
            case 3 : exit(0);
            default : printf("\nInvalid input ");
        }
    }

}
