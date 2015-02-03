#include<bits/stdc++.h>
using namespace std;
std::vector<int> prepos(1100000,-1);
std::vector<int> dp(1000000,0);
int main()
{
	std::vector<int> v;
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		int temp;
		cin>>temp;
		v.push_back(temp);
	}

	// for (int i = 0; i < n; ++i)
	// { 
	// 	cout<<prepos[i]<<endl;
	// }
	for(int i=0;i<n;i++)
	{
		dp[i]=dp[i-1]+v[i];
	}

	int i=0,j=0;
	int maxsum=INT_MIN;
	while(j<n)
	{
		//cout<<"debug prepos="<<prepos[v[j]]<<endl;
		if(prepos[v[j]]<i)
		{
			prepos[v[j]]=j;
			maxsum=max(maxsum,dp[j]-dp[i-1]);
			//cout<<"debug="<<maxsum<<endl;
			j++;
		}
		else
		{
			i=prepos[v[j]]+1;
			//cout<<"i="<<i<<endl;
			prepos[v[j]]=j;
			maxsum=max(maxsum,dp[j]-dp[i-1]);
			//cout<<"debug="<<maxsum<<endl;
			j++;
		}
	}
	cout<<maxsum<<endl;
	return 0;
}