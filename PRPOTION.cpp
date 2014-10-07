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

inline void fastRead_long(long long int &x) {
    register long long int c = getchar_unlocked();
    x = 0;
    long long int neg = 0;

    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

    if(c=='-') {
    	neg = 1;
    	c = getchar_unlocked();
    }

    for(; c>47 && c<58 ; c = getchar_unlocked()) {
    	x = (x<<1) + (x<<3) + c - 48;
    }

    if(neg)
    	x = -x;
}

int main()
{
    //freopen("i.txt","r",stdin);
	long long int t,i,j,k;
	//cin>>t;
	fastRead_long(t);
	while(t--)
	{
		long long int r,g,b,m,temp;
		//cin>>r>>g>>b>>m;
		fastRead_long(r);
		fastRead_long(g);
		fastRead_long(b);
		fastRead_long(m);
		long long int a[3];
		memset(a,0,sizeof(a));
		rep(i,r)
		{
			//cin>>temp;
			fastRead_long(temp);
			a[0]=max(a[0],temp);
		}
		r=temp;
		rep(i,g)
		{
			//cin>>temp;
			fastRead_long(temp);
			a[1]=max(a[1],temp);
		}
		g=temp;
		rep(i,b)
		{
			//cin>>temp;
			fastRead_long(temp);
			a[2]=max(a[2],temp);
		}
		b=temp;
		//cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
		
		
		while(m--)
		{
			long long int idx;
			long long int maxv=INT_MIN;
			rep(i,3)
			{
				if(a[i]>maxv)
				{
					idx=i;
					maxv=a[i];
				}
			}
			a[idx]=a[idx]/2;
			if(a[0]==0&&a[1]==0&&a[2]==0)
				break;
		}
		long long int idx;
		long long int maxv=INT_MIN;
		rep(i,3)
		{
			if(a[i]>maxv)
			{
				idx=i;
				maxv=a[i];
			}
		}
		cout<<maxv<<endl;
	}
    //fclose(stdin);
	return 0;
}
