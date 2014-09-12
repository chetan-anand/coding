// non recusive o(log(n)) exponent functiongit 

#include <bits/stdc++.h>
using namespace std;
int pow(int a,int n)
{
	int ret=1;
	while(n)
	{
		if(n%2==1){ret=ret*a;}
		a=a*a;
		n=n/2;
	}
	return ret;
}
int main()
{
	printf("%d\n",pow(3,4) );
	return 0;
}