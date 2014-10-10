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
#define MAX 1100000
#define mod 1000000007
int dp[MAX];

void pre()
{
    int i,j,k;
    dp[0]=1;
    dp[1]=1;
    //dp[2]=2;
    for(i=2;i<=MAX;i++)
    {
        dp[i]=(dp[i-1]%mod + dp[i-2]%mod)%mod;
    }
}
int main()
{
    //freopen("i.txt","r",stdin);
    memset(dp,0,sizeof(dp));
    int t,i,j,k;
    pre();
    cin>>t;
    while(t--)
    {
        int n,g;
        cin>>n>>g;
        //cout<<dp[n]<<endl;
        if(g==__builtin_popcount(dp[n]))
            cout<<"CORRECT"<<endl;
        else
            cout<<"INCORRECT"<<endl;
    }
    //fclose(stdin);
    return 0;
}
