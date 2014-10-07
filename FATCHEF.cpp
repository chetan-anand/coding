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
#define mod 1000000009
int main()
{
    //freopen("i.txt","r",stdin);
	ll t,i,j,k,n,m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		ll a[110000];
		memset(a,0,sizeof(a));
		rep(i,m)
		{
			char ch;
			ll idx;
			cin>>ch>>idx;
			a[idx]=ch;
		}
		i=1;
		ll start=INT_MAX,end=INT_MIN;
		fi(i,1,n)
		{
			if(a[i]!=0)
			{
				start=min(start,i);
				end=max(end,i);
			}
		}
		cout<<start<<" "<<endl;
		ll ans=1;
		for(i=start+1;i<=end;)
		{
			ll cnt=0;
			while()
		}
	}

    //fclose(stdin);
	return 0;
}
