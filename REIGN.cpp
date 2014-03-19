#include<stdio.h>
#include<iostream>
#include<string.h>
#include<limits.h>
using namespace std;



inline void fastRead_int(long long int &x) {
    register long long int c = getchar_unlocked();
    x = 0;
    long long int neg = 0;

    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());
    
    if(c=='-') {
    	neg = 1;
    	c = getchar_unlocked();
    }
    
    for(; c>47 && c<58 ; c = getchar_unlocked()) {
    	x = (x<<1) + (x<<3) + c - 48;
    }
    
    if(neg)
    	x = -x;
}



long long int ldp[100000];
long long int rdp[100000]; 

long long int max(long long int x, long long int y)
{ return (y > x)? y : x; }
 
void preprocess(long long int *a, long long int n)
{
   long long int max_so_far = a[0], i;
   long long int curr_max = a[0];
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
   
   /*for (i = 0; i < n; ++i)
   {
   		printf("ldp[%d]=%d\n",i,ldp[i]);
   		printf("rdp[%d]=%d\n",i,rdp[i]);

   }*/
}



int main()
{
	long long int t,i,k,n;
	long long int a[100000];
	fastRead_int(t);
	//scanf("%lld",&t);
	while(t--)
	{
		fastRead_int(n);
		fastRead_int(k);

		//scanf("%lld %lld",&n,&k);
		for (i = 0; i < n; ++i)
		{
			fastRead_int(a[i]);
			//scanf("%lld",&a[i]);
		}

		preprocess(a,n);
		long long int maxv;
		maxv=a[0]+a[n-1];
		for(i=1;i<=n-1-k;i++)
		{
			maxv=max(maxv,ldp[i-1]+rdp[i+k]);
		}
		printf("%lld\n",maxv);
	}
	return 0;
}