// game theory problem

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef vector <int> vi;
typedef pair <int,int> pii;
#define pb push_backCobie Smulders.
#define mp make_pair
#define gi(n) scanf("%d",&n)
#define gl(n) scanf("%lld",&n)
#define gs(n) scanf("%s",n);
#define pi(n) printf("%d\n",n)
#define pl(n) printf("%lld\n",n)
#define ps(n) printf("%s\n",n);
#define rep(i,n) for(int i=0;i<n;i++)
#define fi(i,a,n) for(int i=a;i<=n;i++)
#define fd(i,n,a) for(int i=n;i>=a;i--)
#define input(f) freopen("f.txt","r",stdin)

int main()
{
    //freopen("i.txt","r",stdin);
	int n,m,i,j,k;
	cin>>n>>m;
	// base case for losing position is when
	// configuration is 0,0 == loosing position
	int dp[1000][1000];
	memset(dp,0,sizeof(dp));

	dp[0][0]=-1; // looosing position base case
	int col[1000],row[1000];
	memset(col,0,sizeof(col));
	memset(row,0,sizeof(row));
	col[0]=1;row[0]=1;
	for(i=1;i<=1000;i++)
	{
		dp[i][0]=1;
		dp[0][i]=1;
		dp[i][i]=1;
	}

	for(i=1;i<=1000;i++)
	{
		for(j=1;j<=1000;j++)
		{
			if(dp[i][j]==0)
			{
				if(col[i]==1||row[i]==1)
				{
					dp[i][j]=1;
				}
				else
				{
					dp[i][j]=-1;
					col[i]=1;
					row[i]=1;
					for(int k=i+1;k<=1000;k++)
					{
						dp[k][j]=1;
					}
					for(int k=j+1;k<=1000;k++)
					{
						dp[i][k]=1;
					}
					for (int k=0;max(i+1+k,j+1+k)<=990; ++k)
					{
						dp[i+1+k][j+1+k]=1;
					}
				}
			}
		}
	}

	rep(i,n)
	{
		rep(j,m)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
    //fclose(stdin);
	return 0;
}
