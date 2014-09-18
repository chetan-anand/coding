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

/////////////////////////////////////////////////
long long int dp[110000][11];
void precompute(long long int *a,long long int n)
{
	memset(dp,0,sizeof(dp));
	fi(i,1,n)
	{
		dp[i][a[i]]++;
	}
	fi(i,1,n)
	{
		fi(j,0,9)
		{
			dp[i][j]=dp[i-1][j]+dp[i][j];
		}
	}
}

int main()
{
    //freopen("i.txt","r",stdin);
	long long int n,m,i,j,k,t;
	//cin>>n>>m;
	fastRead_long(n);
	fastRead_long(m);
	long long int a[110000];
	string s;
	cin>>s;
	rep(i,s.size())
	{
		a[i+1]=s[i]-48;
	}
	
	precompute(a,n);
	while(m--)
	{
		long long int x;
		//cin>>x;
		fastRead_long(x);
		long long int temp=a[x];
		long long int b1=0,b2=0;
		fi(i,0,9)
		{
			if(i<=temp)
			{
				long long int cnt=dp[x][i];
				b1=b1+cnt*(temp-i);
			}
			else
			{
				long long int cnt=dp[x][i];
				b2=b2+cnt*(i-temp);
			}
		}
		cout<<b1+b2<<endl;
	}

    //fclose(stdin);

	return 0;
}
