#include<iostream>
#include<stdio.h>
int main()
{
		 long long int n,cnt;
		 while(true)
		 	{
		 	    scanf("%lld",&n);
		 	    if(n==0){break;}
		 	if(n%2==0)
		 		{
		 		    cnt=(n*(n-2)*(2*n-5))/24;
		 		}
		 	else
		 		{
		 		    cnt=((n-1)*(n-3)*(2*n-1))/24;
		 		}
		 		printf("%lld\n",cnt);
		 	}
    return 0;
}

