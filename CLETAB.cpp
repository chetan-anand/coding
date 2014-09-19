#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef vector <int> vi;
typedef pair <int,int> pii;
#define pb push_back
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

int dp[402][202];
void precompute(int *orders,int m,int n)
{

}
int main()
{
    //freopen("i.txt","r",stdin);
	int t,i,j,k;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		bool present[202]; //which person is present
		int orders[402];
		memset(present,0,sizeof(present));
		int cnt=0; // no of seat vacant
		rep(i,m)
		{
			cin>>orders[i];
		}
		int ans=0;
		rep(i,m)
		{
			if(cnt<=n)
			{
				if(!present[order[i]])
				{
					cnt++;
					ans++;
				}
			}
			else
			{
				if(!present[order[i]])
				{

				}
			}
		}
	}
    //fclose(stdin);
	return 0;
}
