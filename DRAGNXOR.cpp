#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef vector <long long int> vi;
typedef pair <long long int,long long int> pii;
#define pb push_backCobie Smulders.
#define mp make_pair
#define gi(n) scanf("%d",&n)
#define gl(n) scanf("%lld",&n)
#define gs(n) scanf("%s",n);
#define pi(n) prlong long intf("%d\n",n)
#define pl(n) prlong long intf("%lld\n",n)
#define ps(n) prlong long intf("%s\n",n);
#define rep(i,n) for(long long int i=0;i<n;i++)
#define fi(i,a,n) for(long long int i=a;i<=n;i++)
#define fd(i,n,a) for(long long int i=n;i>=a;i--)
#define input(f) freopen("f.txt","r",stdin)

int main()
{
    //freopen("i.txt","r",stdin);
	long long int t,i,j,k,n;
	cin>>t;
	while(t--)
	{
		long long int a,b;
		cin>>n>>a>>b;
		long long int na1,na0,nb1,nb0;
		na1=na0=nb1=nb0=0;
		rep(i,n)
		{
			if(a&1)
				na1++;
			else
				na0++;
			a=a>>1;
			if(b&1)
				nb1++;
			else
				nb0++;
			b=b>>1;
		}
		//cout<<na1<<" "<<na0<<" "<<nb1<<" "<<nb0<<endl;
		long long int temp=min(na1+nb1,na0+nb0);
		long long int ans=0;
		//cout<<temp<<endl;
		for(j=1;j<=temp;j++)
		{
			ans=ans+(ll)(1<<(n-j));
		}
		cout<<ans<<endl;
	}
    //fclose(stdin);
	return 0;
}
