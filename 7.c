//dfs
#include<stdio.h>
#include<stdlib.h>

int graph[30][30],visited[30],dfsCount,dcount,Count,iscyc,parent[30];
int test;

void dfs(int n,int start){
    visited[start] = 1;
    Count++;
    if(test == 1)
        printf("-->%c",start+65);
    for(int i=0;i<n;i++){
        dcount++;
        if(!parent[start] && graph[start][i] && visited[i])
            iscyc = 1;
        if(graph[start][i] && !visited[i]){
            dfs(n,i);
            parent[i] = start;
        }
    }

}

void tester()
{
    printf("\nEnter the num of vertex ");
    int n;
    scanf("%d",&n);
    printf("Enter the adjacency matrix");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            scanf("%d",&graph[i][j]);
        visited[i] = 0;
    }
    printf("\nThe adjacency matrix is :");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            printf("%d  ",graph[i][j]);
        printf("\n");
    }
    dfsCount++;
    parent[0] = -1;
    dfs(n,0);
    if(Count == n)
        printf("\nThe graph is connected");
    else{
        int start = 1;
        while( Count != n){
                if(!visited[start]){
                    printf("\n");
                    dfsCount++;
                    parent[start] = -1;
                    dfs(n,start);
                }start++;
        }
        printf("\nThe graph is disconnected");
    }
    if(iscyc)
        printf("\nThe graph is cyclic");
    else
        printf("\nThe graph is acyclic");
    printf("\nThe no of components in dfs is %d",dfsCount);
}

void plotter()
{
    FILE *fp1,*fp2;
    fp1 = fopen("dfsB.txt","w");
    fp2 = fopen("dfsW.txt","w");
    for(int k=0;k<2;k++){
        for(int n=2;n<=20;n+=2){
            dfsCount=0;Count=0;dcount=0;
            if(k==0){
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        if(i==j)
                            graph[i][j] = 0;
                        else
                            graph[i][j] = 1;
                    }visited[i] = 0;
                }
            }
            else{
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++)
                        graph[i][j] = 0;
                    visited[i] = 0;
                }
                for(int i=0;i<n;i++)
                    graph[i][i+1] = 1;
            }
            dfsCount++;
            parent[0] = -1;
            dfs(n,0);
            int start = 1;
            while(Count != n){
                if(!visited[start]){
                    dfsCount++;
                    parent[start] = -1;
                    dfs(n,start);
                }start++;
            }
            if(k==0)
                fprintf(fp1,"%d\t%d\n",n,dcount);
            else
                fprintf(fp2,"%d\t%d\n",n,dcount);
        }
    }
}

void main()
{
    while(1){
        printf("\nEnter \n1.for tester \n2.for plotter");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1 : test = 1;
            tester();break;
            case 2 : test = 0;
            plotter();
            break;
            case 3 : exit(0);
            default : printf("\nInvalid input");
        }
    }
}
