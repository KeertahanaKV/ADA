//heapSort
#include<stdio.h>
#include<stdlib.h>

int cnt,cnt2;

void swap(int* a ,int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int* heap,int n,int root)
{
    int largest = root, left = 2*root+1 , right = 2*root+2;
    if(left < n && heap[left]>heap[largest]){
        cnt++;
        largest = left;
    }
    if(right < n && heap[right]>heap[largest]){
        cnt++;
        largest = right;
    }
    if(largest != root){
        swap(&heap[root],&heap[largest]);
        heapify(heap,n,largest);
    }
}

void heapSort(int* heap,int n){
    cnt2=0;cnt=0;
    for(int i=n/2-1;i>=0;i--)
        heapify(heap,n,i);
    cnt2 = cnt;
    cnt = 0;
    for(int i=n-1;i>=0;i--){
        swap(&heap[0],&heap[i]);
        heapify(heap,i,0);
    }
}

void tester()
{
    int n;
    printf("Enter n\n");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter Array elements : ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    heapSort(arr,n);
    printf("\nArray elements : ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\nCount = %d %d",cnt,cnt2);
}
int max(int a,int b){
    return (a>b)?a:b;
}
void plotter()
{
    FILE *f1,*f2,*f3;
    f1 = fopen("heapB.txt","w");
    f2 = fopen("heapA.txt","w");
    f3 = fopen("heapW.txt","w");
    for(int n=100;n<=1000;n+=100){
        int arr[n];
        for(int i=0;i<n;i++){
            arr[i] = n-i+5;
        }
        heapSort(arr,n);
        cnt = max(cnt,cnt2);
        fprintf(f1,"%d\t%d\n",n,cnt);
        for(int i=0;i<n;i++){
            arr[i] = i+5;
        }
        heapSort(arr,n);
        cnt = max(cnt,cnt2);
        fprintf(f3,"%d\t%d\n",n,cnt);
        for(int i=0;i<n;i++){
            arr[i] = rand()%100;
        }
        heapSort(arr,n);
        cnt = max(cnt,cnt2);
        fprintf(f2,"%d\t%d\n",n,cnt);
    }
    fclose(f1);fclose(f2);fclose(f3);
}

void main()
{
    while (1)
    {
        printf("\nEnter \n1.For tester \n2.For plotter \n3.To exit ");
        int ch;
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            tester();
            break;
        case 2:
            plotter();
            break;
        case 3:
            exit(0);
        default:
            printf("\nInvalid input");
            break;
        }
    }
}
