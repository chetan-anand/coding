#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
	int temp;
	while(b)
	{
		int temp=a%b;
		a=b;
		b=temp;
	}
	return a;
}
int main()
{
	int t,i,j,k;
	cin>>t;
	while(t--)
	{
		int n,a[110000],temp;
		cin>>n;
		for(i=0;i<n;i++)
			cin>>a[i];
		temp=a[0];
		for(i=1;i<n;i++)
		{
			temp=gcd(temp,a[i]);
			if(temp==1)
			{
				cout<<n<<endl;
				break;
			}
		}
		if(temp!=1)
			cout<<"-1"<<endl;
	}
	return 0;
}
		
		