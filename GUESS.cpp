#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int a,long long int b)
{
    long long int temp,m;
    if(b>a){temp=a;a=b;b=temp;}
    while(b!=0)
    {
        m=a%b;
        a=b;
        b=m;
    }
    return a;
}
int main()
{
	long long int t,i,j,k,temp,n,m,numerator,denominator;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		numerator=(n/2)*(m-(m/2))+(m/2)*(n-n/2);
		denominator=n*m;
		//cout<<numerator<<endl;
		//cout<<denominator<<endl;
		temp=gcd(numerator,denominator);
		printf("%lld/%lld\n",numerator/temp,denominator/temp);

	}
	return 0;
}