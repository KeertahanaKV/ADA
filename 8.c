#include<stdio.h>
#include<stdlib.h>

int graph[30][30],visited[30],bfsCount,orderCount,Count,cyclic;
int test;
void bfs(int n,int start){
    int queue[30],parent[30],parentNode,front=-1,rear=-1;
    visited[start] = 1;Count++;
    queue[++rear] = start;
    parent[rear] = -1;
    while( front < rear){
        start = queue[++front];
        parentNode = parent[front];
        if(test == 1)
            printf("-->%c",97+start);
        for(int i=0;i<n;i++){
            orderCount++;
            if(i!=parentNode && graph[start][i] && visited[i])
                cyclic = 1;
            if(graph[start][i] && !visited[i]){
                queue[++rear] = i;
                parent[rear] = start;
                visited[i] = 1;
                Count++;
            }
        }
    }
}

void tester()
{
    test = 1;
    int n;
    printf("\nEnter the number of vertices");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }visited[i] = 0;
    }
    printf("\nThe adjacency matrix is :\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d  ",graph[i][j]);
        }
        printf("\n");
    }
    bfsCount=0;Count=0;orderCount=0;cyclic=0;
    bfsCount++;
    bfs(n,0);
    if(Count == n)
        printf("\nThe graph is connected");
    else{
        int start = 1;
        while(Count != n){
            if(!visited[start]){
                bfsCount++;
                printf("\n");
                bfs(n,start);
            }start++;
        }
    printf("\nThe graph is disconnected");
    }

    if(cyclic)
        printf("\nThe given graph is cyclic");
    else
        printf("\nThe given graph is acyclic");
    printf("\nThe graph has %d bfs",bfsCount);
}

void plotter()
{
    FILE *fp,*fp2;
    fp = fopen("bfsB.txt","w");
    fp2 = fopen("bfsW.txt","w");
    for(int n=0;n<2;n++){
        for(int i=2 ; i<=20 ; i+=2){
            bfsCount=0;orderCount=0;Count=0;
            if(n==0){
                for(int j=0;j<i;j++){
                    for(int k=0;k<i;k++){
                        if( j== k)
                            graph[j][k] = 0;
                        else
                            graph[j][k] = 1;
                    }visited[j] = 0;
                }
            }
            else{
                for(int j=0;j<i;j++){
                    for(int k=0;k<i;k++){
                        graph[j][k] = 0;
                    }visited[j] = 0;
                }
                for(int k=0;k<i-1;k++){
                        graph[k][k+1]= 0;
                }
            }

            bfsCount++;
            bfs(i,0);int start = 1;
            while(Count != i){
                if(!visited[start]){
                    bfsCount++;
                    bfs(i,start);
                }start++;
            }
            if(n==0)
                fprintf(fp,"%d\t%d\n",i,orderCount);
            else
                fprintf(fp2,"%d\t%d\n",i,orderCount);
        }
    }

    fclose(fp);fclose(fp2);

}

void main()
{
    while(1){
        printf("Enter \n1.For tester \n2.For plotter \n3.To exit");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1 : test = 1;
                tester();
                break;
            case 2 : test = 0;
                plotter();
                break;
            case 3 : exit(0);
            default : printf("\nInvalid input");
        }
    }

}
