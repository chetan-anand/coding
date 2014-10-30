#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,j,k;
	int t,n,m,x;
	cin>>t;

	while(t--)
	{
		cin>>n>>m>>x;
		int c[n+2],w[n+2];
		bool dp[m+1][x+1];
		memset(dp,0,sizeof(dp));
		dp[0][0]=0;
		for(i=0;i<n;i++)
		{
			cin>>w[i];
		}
		for(i=0;i<n;i++)
		{
			cin>>c[i];
		}

		for(i=0;i<n;i++)
		{
			if(c[i]==1)
			{
				dp[1][w[i]]=true;
			}
		}

		for(i=2;i<=m;i++)
		{
			for(j=1;j<=x;j++)
			{
				for(k=0;k<n;k++)
				{
					if(c[k]==i)
					{
						if(j-w[k]>=0 && dp[i-1][j-w[k]])
						{
							dp[i][j]=true;
						}
					}
				}
			}
		}

		for(i=x;i>=1;i--)
		{
			if(dp[m][i])
			{
				cout<<x-i<<endl;
				break;
			}
		}
		if(i==0)
		{
			cout<<"-1"<<endl;
		}
	}

	return 0;
}