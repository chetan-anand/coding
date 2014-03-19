#include<stdio.h>
#include<iostream>
using namespace std;

int ldp[110000];
int rdp[110000]; 

int max(int x, int y)
{ return (y > x)? y : x; }
 
void preprocess(int a[], int n)
{
   int max_so_far = a[0], i;
   int curr_max = a[0];
 	ldp[0]=curr_max;
   for (i = 1; i < n; i++)
   {
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
        ldp[i]=max_so_far;
   }
   max_so_far=a[n-1];
   curr_max=a[n-1];
   rdp[n-1]=curr_max;
   for(i=1;i< n;i++)
   {
   		curr_max = max(a[n-i-1], curr_max+a[n-i-1]);
        max_so_far = max(max_so_far, curr_max);
        rdp[n-i-1]=max_so_far;
   }

   for (i = 0; i < n; ++i)
   {
   		printf("ldp[%d]=%d\n",i,ldp[i]);
   		printf("rdp[%d]=%d\n",i,rdp[i]);
   	/* code */
   }
}
 
/* Driver program to test maxSubArraySum */
int main()
{
   int a[] =  {5, 5 ,-1, -2, 3, -1, 2, -2};
   int n = sizeof(a)/sizeof(a[0]);
   preprocess(a,n);
   return 0;
}