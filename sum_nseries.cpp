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
#define mod 1000000007
ll power(ll a,ll n)
{
	ll ret=1;
	while(n)
	{
		if(n%2==1){ret=((ret%mod)*(a%mod))%mod;}
		a=((a%mod)*(a%mod))%mod;
		n=n/2;
	}
	return ret;
}

int main()
{
    //freopen("i.txt","r",stdin);
	ll t,i,j,k;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vector< pair<ll,ll> > factor;
		ll temp=n;
		//now doing prime factorization of n
		for(i=2;i*i<=temp;i++)
		{
			ll cnt=0;
			while(temp%i==0)
			{
				cnt++;
				temp=temp/i;
			}
			factor.push_back(make_pair(i,cnt));
		}
		if(temp!=1)
			factor.push_back(make_pair(temp,1));
		ll ans=1;
		for(i=0;i<factor.size();i++)
		{
			ll temp=power(factor[i].first,2*factor[i].second);
			ans=((ans%mod)*(temp%mod))%mod;
		}

		cout<<ans<<endl;
	}
    //fclose(stdin);
	return 0;
}
