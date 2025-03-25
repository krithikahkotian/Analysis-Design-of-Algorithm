#include<stdio.h>
#include<time.h>
#define MAX 1000

void swap(int *a, int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

int partition(int a[],int low,int high){
    int i=low-1;
    int pivot=a[high];
    for(int j=low;j<high;j++){
        if(a[j]<pivot){
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[high]);
    return i+1;
}

int QuickSort(int a[],int low,int high)
{

    if(low<high){
        int pi=partition(a,low,high);
        QuickSort(a,low,pi-1);
        QuickSort(a,pi+1,high);
    }
}

int main()
{
    int a[MAX],n,ch=1;
    clock_t start,end;
    while(ch){
        printf("\nEnter the number of element in the array\n");
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            a[i]=rand()%200;
        }
        printf("\nArray Elements Before Sorting\n");
        for(int i=0;i<n;i++){
            printf("%d\t",a[i]);
        }
        start=clock();
        QuickSort(a,0,n-1);
        end=clock();
        double tt=(float)(end-start)/CLOCKS_PER_SEC;
        printf("\nArray Elements After Sorting\n");
        for(int i=0;i<n;i++){
            printf("%d\t",a[i]);
        }
        printf("\nTime Taken is %.3f",tt);
        printf("\nDo you want to Continue(1-Yes,0-No)\n");
        scanf("%d",&ch);
    }
    return 0;
}
