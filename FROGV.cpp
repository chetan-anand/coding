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
	int i,j,k,n,p;
	int dp[110000];
	memset(dp,0,sizeof(dp));
	pair<int,int> a[110000];
	cin>>n>>k>>p;
	rep(i,n)
	{
		int temp;
		cin>>temp;
		a[i]=make_pair(temp,i);
	}
	sort(a,a+n);
	int cnt=0;
	dp[a[0].second]=cnt;
	fi(i,1,n-1)
	{
		if(a[i].first-a[i-1].first<=k)
		{
			dp[a[i].second]=cnt;
		}
		else
		{
			cnt++;
			dp[a[i].second]=cnt;
		}
	}

	/*rep(i,n)
	{
		cout<<dp[a[i].second]<<endl;
	}*/
	while(p--)
	{
		int a,b;
		cin>>a>>b;
		if(dp[a-1]==dp[b-1])
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}