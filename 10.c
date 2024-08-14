//source removal                                                                                                                                  #include<stdio.h>
#include<stdlib.h>

int arr[30][30],flag[30],Queue[30],ind[30],s[30],Count,SCount,fro=-1,rear=-1,itemCount;
int x=0;
void indegree(int n)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[j][i] == 1)
                ind[i] += 1;
        }
    }

    for(int i=0;i<n;i++){
        if(ind[i] == 0){
            rear = (rear+1)%n;
            Queue[rear] = i;
            flag[i] = 1;
            itemCount++;
        }
    }
}

void sourceR(int n){
    while(itemCount > 0){
        fro = (fro+1)%n;
        int source = Queue[fro];
        s[x++] = source;
        Count++;
        itemCount--;
        for(int i=0;i<n;i++){
            SCount++;
            if(arr[source][i] == 1)
                ind[i] -= 1;
            if(ind[i] == 0 && flag[i]==0){
                rear = (rear+1)%n;
                Queue[rear] = i;
                flag[i] = 1;
                itemCount+=1;
            }
        }
    }
}

void tester()
{
    printf("\nEnter the no of vertices ");
    int n;
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            scanf("%d",&arr[i][j]);
        flag[i]=0;ind[i]=0;
    }
    Count=0;SCount=0;itemCount=0;fro=-1;rear=-1;x=0;
    indegree(n);
    sourceR(n);
    if(Count != n)
        printf("\nThe graph is cyclic");
    else{
        printf("\n");
        for(int i=0;i<x;i++)
            printf("%c  ",97+s[i]);
    }
}

void plotter()
{
    FILE *fp,*fp2;
    fp = fopen("removeB.txt","w");
    fp2 = fopen("removeW.txt","w");
    for(int k = 0;k<2;k++){
        for(int n=4;n<20;n++){
            Count=0;SCount=0;itemCount=0;fro=-1;rear=-1;x=0;
            if(k == 0){
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++)
                            arr[i][j] = 0;
                    flag[i] = 0;ind[i]=0;
                }
                for(int i=0;i<n;i++)
                    arr[i][i+1] = 1;
            }
            else{
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        arr[i][j] = 0;
                    }flag[i]=0;ind[i]=0;
                }
                for(int i=0;i<n-1;i++){
                    for(int j=i+1;j<n;j++)
                        arr[i][j] = 1;
                }
            }
            indegree(n);
            sourceR(n);
            if(k == 0){
                fprintf(fp,"%d\t%d\n",n,SCount);
                //printf("\n%d\t%d",n,SCount);
            }
            else{
                fprintf(fp2,"%d\t%d\n",n,SCount);
                //printf("\n%d\t%d",n,SCount);
            }

        }
    }fclose(fp);fclose(fp2);
}


void main()
{
    while(1){
        printf("\nEnter 1.tester 2.plotter 3.To exit  ");int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1 : tester();break;
            case 2 : plotter();printf("\nGraph plotted!");break;
            case 3 : exit(0);
            default : printf("\nInvalid input!!");
        }
    }

}
