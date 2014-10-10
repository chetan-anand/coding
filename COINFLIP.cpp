#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	/* code */
	int t,g,i,q,n;
	cin>>t;
	while(t--)
	{
		cin>>g;
		while(g--)
		{
			cin>>i>>n>>q;
			if(!(n&1))
				cout<<n/2<<endl;
			else
			{
				if(i==q)
					cout<<n/2<<endl;
				else
					cout<<(n/2)+1<<endl;
			}
		}
	}
	return 0;
}
