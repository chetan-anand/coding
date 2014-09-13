#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef vector <long long int> vi;
typedef pair <long long int,long long int> pii;
#define pb push_back
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

//////////////// bondapa /////////////
#define all(a) a.begin(),a.end()
#define imax numeric_limits<long long int>::max()
#define imin numeric_limits<long long int>::min()
#define lmax numeric_limits<llu>::max()
#define lmin numeric_limits<llu>::min()
///////////////////////////////////////

void dis(long long int *a,long long int n)
{
	rep(i,n)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main()
{
    //freopen("i.txt","r",stdin);
	long long int i,j,k,n,m,a[110000],b[110000];
	cin>>n>>k;
	long long int maxv=INT_MIN;
	rep(i,n)
	{
		cin>>a[i];
		maxv=max(maxv,a[i]);
	}
	if(k==0){dis(a,n);return 0;}
	long long int maxv2=INT_MIN;
	rep(i,n)
	{
		a[i]=maxv-a[i];
		maxv2=max(maxv2,a[i]);
	}
	rep(i,n)
	{
		b[i]=maxv2-a[i];
	}
	if(k==1){dis(a,n);}
	else if((k-1)%2==0){dis(a,n);}
	else{dis(b,n);}
    //fclose(stdin);
	return 0;
}
