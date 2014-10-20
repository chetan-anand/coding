#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n&1)
			cout<<"BOB"<<endl;
		else
			cout<<"ALICE"<<endl;
	}
	return 0;
}