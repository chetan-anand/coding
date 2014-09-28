#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef vector <ll> vi;
typedef pair <ll,ll> pii;
#define pb push_backCobie Smulders.
#define mp make_pair
#define gi(n) scanf("%d",&n)
#define gl(n) scanf("%lld",&n)
#define gs(n) scanf("%s",n);
#define pi(n) prllf("%d\n",n)
#define pl(n) prllf("%lld\n",n)
#define ps(n) prllf("%s\n",n);
#define rep(i,n) for(ll i=0;i<n;i++)
#define fi(i,a,n) for(ll i=a;i<=n;i++)
#define fd(i,n,a) for(ll i=n;i>=a;i--)
#define input(f) freopen("f.txt","r",stdin)
#define init(f) memset(f,0,sizeof(f))

void sum(ll *s,ll *a,ll n)
    {
    s[1]=a[1];
    for(ll i=2;i<=n;i++)
        {
        s[i]=s[i-1]+a[i];
    }
}


int main() {

    /* Enter your code here. Read input from STDIN. Prll output to STDOUT */
    ll t,i,j,k;
    ll s[110000],a[110000],dp[110000],n;
    cin>>t;
    //dp[i]= max score player can get with top stack size of i
    while(t--)
    {
        cin>>n;

        memset(s,0,sizeof(s));
        memset(dp,0,sizeof(dp));
        fd(i,n,1)
        {
            cin>>a[i];
        }
        sum(s,a,n);
        if(n<=3)
        {
            cout<<s[n]<<endl;
            continue;
        }
        dp[1]=a[1];dp[2]=a[1]+a[2];
        dp[3]=a[1]+a[2]+a[3];
        fi(i,4,n)
        {
            ll x=a[i];
            ll y=x+a[i-1];
            ll z=y+a[i-2];
            dp[i]=max(x+s[i-1]-dp[i-1],max(y+s[i-2]-dp[i-2],z+s[i-3]-dp[i-3]));
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}
