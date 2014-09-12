// recusive o(log(n)) exponent functiongit 

#include<bits/stdc++.h>
using namespace std;
int pow(int a,int n)
{
	if(n==0){return 1;}
	if(n==1){return a;}
	if(n%2==1)
	{
		int temp=pow(a,n/2);
		return temp*temp*a;
	}
	else
	{
		int temp=pow(a,n/2);
		return temp*temp;
	}
}

int main()
{

	
	return 0;
}
