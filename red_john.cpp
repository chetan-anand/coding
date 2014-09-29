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



#define max 300000
bool prime[max];
int primeno[max];
void initsow()
{
    int i,j,k;
    memset(prime,false,sizeof(prime));
    prime[1]=true;
    for(i=2;i<=sqrt(max);i++)
    {
        if(!(prime[i]))
        {
            for(j=2*i;j<=max;j+=i)
            {
                if(!prime[j]){prime[j]=true;}

            }
        }
    }
}

int dp[100];
void pre()
{
	memset(dp,0,sizeof(dp));
	initsow();
	dp[0]=dp[1]=dp[2]=dp[3]=1;
	fi(i,4,42)
	{
		dp[i]=dp[i-1]+dp[i-4];
	}
	memset(primeno,0,sizeof(primeno));
	int cnt=0;
	fi(i,2,max)
	{
		if(!prime[i])
		{
			cnt++;
		}
		primeno[i]=cnt;
	}
}
int main()
{
    //freopen("i.txt","r",stdin);
	int i,j,k,t,n;
	cin>>t;
	pre();
	while(t--)
	{
		cin>>n;
		cout<<primeno[dp[n]]<<endl;
		//cout<<dp[41]<<endl;
	}
    //fclose(stdin);
	return 0;
}
