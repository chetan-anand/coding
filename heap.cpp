#include<stdio.h>
#include<iostream>
#include<stdlib.h>
//using namespace std;
class heap
{
    public:
    void heapify(int *a,int i,int n)
    {
        int l,r,big,temp;
        l=2*i;
        r=2*i+1;
        if(l<=n && a[l]>a[i])
        {
            big=l;
        }
        else{big=i;}
        if(r<=n && a[r]>a[big])
        {
            big=r;
        }
        if(big!=i)
        {
            temp=a[i];
            a[i]=a[big];
            a[big]=temp;
        }
        if(2*big+1<=n)
        {heapify(a,big,n);}
    }

    void buildheap(int *a,int n)
    {
        int j;
        for(j=n/2;j>=1;j--)
        {
            heapify(a,j,n);
        }
        heapify(a,n/2,n);
    }
    void display(int *a,int n)
    {
        int i;
        printf("--------------------the sorted array is-------------------------------\n");
        for(i=1;i<=n;i++)
        {
            printf("%d\n",a[i]);
        }
    }
    void heapsort(int *a,int n)
    {
        buildheap(a,n);
        int i,temp;
        for(i=n;i>=2;i--)
        {
            temp=a[1];
            a[1]=a[i];
            a[i]=temp;
            n=n-1;
            heapify(a,1,n);
        }
    }
};
int main()
{
    int a[10000],i,n;
    printf("Enter the no of random integer to be sorted=");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        a[i]=rand();
    }
    heap object;
    //object.buildheap(a,n);
    object.heapsort(a,n);
    object.display(a,n);
    return 0;
}
