#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::vector<int> v;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	int dpl[110000],dpr[110000];
	memset(dpl,0,sizeof(dpl));
	memset(dpr,0,sizeof(dpr));

	for(int i=0;i<n;i++)
	{
		dpl[i]=dpl[i-1]+v[i];
		dpr[n-1-i]=dpr[n-i]+v[n-i-1];
	}

	for(int i=0;i<n;i++)
	{
		if(dpl[i]==dpr[i])
		{
			cout<<"Eq_point="<<i<<endl;
		}
	}
	return 0;
}