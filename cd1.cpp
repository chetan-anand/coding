#include<bits/stdc++.h>
using namespace std;
int func(int n)
{
	if(n%2==0)
	{
		return 2;
	}
	else
	{
		int temp=sqrt(n);
		for(int i=3;i<=temp;i+=2)
		{
			if(n%i==0)
			{
				return i;
			}
			else
			{
				if(i==temp)
				{
					return i;
				}
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	
	int i,j,d;
	//cin>>i>>j>>d;
	cout<<func(1)<<endl;
	return 0;
}