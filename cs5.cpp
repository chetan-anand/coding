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

long long int m[200000];
long long int h[200000];
int main()
{
    //freopen("i.txt","r",stdin);
	int t,i,j,k,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		rep(i,n)
		{
			cin>>m[i];
		}
		rep(i,n)
		{
			cin>>h[i];
		}
		sort(m,m+n);
		sort(h,h+n);
		long long int maxv=INT_MIN;
		rep(i,n)
		{
			maxv=max(maxv,abs(m[i]-h[i]));
		}
		cout<<maxv<<endl;
	}
    //fclose(stdin);
	return 0;
}
