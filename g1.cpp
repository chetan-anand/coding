#include<bits/stdc++.h>
using namespace std;


long long int mat[1100][1100];
bool dp[1100][1100];
long long int x[1100000],y[1100000];
long long int ans;
void dfs(long long int i,long long int j,long long int s,long long int cnt)
{

	//cout<<i<<" "<<j<<endl;
	ans=max(ans,cnt);
	//cout<<"ans="<<ans<<endl;
	
	dp[i][j]=true;
	if(i+1<=s-1)
	{
		long long int temp=i+1;
		
		if(!(dp[temp][j])&& mat[temp][j]==mat[i][j]+1)
		{
			//long long int cnt1=cnt;
			//cnt1++;
			//cout<<"cnt1="<<ans<<endl;
			//ans=max(ans,cnt1);
			//cout<<"ans="<<ans<<endl;
			dfs(temp,j,s,cnt+1);
		}
	}
	if(i-1>=0)
	{
		long long int temp=i-1;
		
		if(!(dp[temp][j])&& mat[temp][j]==mat[i][j]+1)
		{
			// long long int cnt1=cnt;
			// cnt1++;
			// //cout<<"cnt1="<<ans<<endl;
			// ans=max(ans,cnt1);
			//cout<<"ans="<<ans<<endl;
			dfs(temp,j,s,cnt+1);
		}
	}
	if(j+1<=s-1)
	{
		long long int temp=j+1;
		
		if(!(dp[i][temp])&& mat[i][temp]==mat[i][j]+1)
		{
			/*long long int cnt1=cnt;
			cnt1++;
			//cout<<"cnt1="<<ans<<endl;
			ans=max(ans,cnt1);
			//cout<<"ans="<<ans<<endl;*/
			dfs(i,temp,s,cnt+1);
		}
	}
	if(j-1>=0)
	{
		long long int temp=j-1;
		
		if(!(dp[i][temp])&& mat[i][temp]==mat[i][j]+1)
		{
			/*long long int cnt1=cnt;
			cnt1++;
			//cout<<"cnt1="<<ans<<endl;
			ans=max(ans,cnt1);
			//cout<<"ans="<<ans<<endl;*/
			dfs(i,temp,s,cnt+1);
		}
	}
	//cout<<"ans="<<ans<<endl;
	//cout<<"end"<<endl;
}
int main()
{
    //freopen("i.txt","r",stdin);
	long long int t,i,j,k,s;
	cin>>t;
	long long int cnt=0;
	while(t--)
	{
		cin>>s;

		memset(dp,0,sizeof(dp));
		vector< pair<long long int,long long int> > an;
		for(long long int i=0;i<s;i++)
		{
			for(long long int j=0;j<s;j++)
			{
				cin>>mat[i][j];
				x[mat[i][j]-1]=i;
				y[mat[i][j]-1]=j;
				//cout<<mat[i][j]<<endl;

			}
		}

		
		for(long long int i=0;i<s*s;i++)
		{
			//cout<<x[i]<<" "<<y[i]<<endl;
			ans=0;
			if(!dp[x[i]][y[i]])
			{
				dfs(x[i],y[i],s,0);
				//cout<<"end ans"<<ans<<endl;
				pair<long long int,long long int> temp=make_pair(i+1,ans+1);
				an.push_back(temp);
			}
		}
		long long int ans2=INT_MIN;
		long long int ans1;
		for(long long int i=0;i<an.size();i++)
		{
			if(an[i].second>ans2)
			{
				ans2=an[i].second;
				ans1=an[i].first;
			}
		}
		cnt++;
		cout<<"Case #"<<cnt<<": "<<ans1<<" "<<ans2<<endl;
	}
    //fclose(stdin);
	return 0;
}
