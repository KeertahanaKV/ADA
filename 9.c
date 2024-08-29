#include<stdio.h>
#include<stdlib.h>

int graph[30][30],visited[30],cyc,path[30],Count,Stack[30],top=-1;
void dfs(int n,int start){
    visited[start] = 1;path[start]=1;
    for(int i=0;i<n;i++){
        Count++;
        if(graph[start][i] && visited[i] && path[i])
            cyc = 1;
        if(graph[start][i] && !visited[i]){
            dfs(n,i);
        }
    }path[start] = 0;Stack[++top] = start;
}

void tester()
{
    printf("\nEnter the no of vetrices :");
    int n;
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }visited[i]=0;path[i]=0;
    }
    cyc = 0;Count=0;
    for(int i=0;i<n;i++){
        if(!visited[i])
            dfs(n,i);
    }
    if(cyc == 1){
        printf("\nCycle exist so can't ");
        return;
    }

    for(int i=n-1; i>0 ; i--)
        printf("-->%c",97+Stack[i]);
}

void plotter()
{
    FILE *fp,*fp2;
    fp = fopen("topoB.txt","w");
    fp2 = fopen("topoW.txt","w");
    for(int k = 0;k<2;k++){
        for(int n=4;n<14;n++){
            cyc = 0;Count = 0;top=-1;
            if(k == 0){
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        if(i == j)
                            graph[i][j] = 0;
                        else
                            graph[i][j] = 1;
                    }visited[i] = 0;path[i]=0;
                }
            }
            else{
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        graph[i][j] = 0;
                    }visited[i] = 0;path[i]=0;
                }
                for(int i=0;i<n;i++)
                    graph[i][i+1] = 1;
            }
            for(int i=0;i<n;i++){
                if(!visited[i])
                    dfs(n,i);
            }
            if(k == 0)
                fprintf(fp,"%d\t%d\n",n,Count);
            else
                fprintf(fp2,"%d\t%d\n",n,Count);

        }
    }
}

void main()
{
    printf("\nEnter 1.tester 2.plotter");int ch;
    scanf("%d",&ch);
    switch(ch){
        case 1 : tester();break;
        case 2 : plotter();printf("\nGraph plotted!");break;
        case 3 : exit(0);
        default : printf("\nInvalid input!!");
    }
}
