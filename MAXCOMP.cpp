#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef vector <int> vi;
typedef pair <int,int> pii;

#define pb push_back
#define mp make_pair
#define gi(n) scanf("%d",&n)
#define gl(n) scanf("%llu",&n)
#define pi(n) printf("%d\n",n)
#define pl(n) printf("%llu\n",n)
#define rep(i,n) for(int i=0;i<n;i++)
#define fi(i,a,n) for(int i=a;i<=n;i++)
#define fd(i,n,a) for(int i=n;i>=a;i--)
#define input(f) freopen("f.txt","r",stdin)
#define all(a) a.begin(),a.end()

///////////////////////////////////////

int main()
{
    //freopen("i.txt","r",stdin);
    int n,t,i,j,k,c[50][50],dp[50];
    cin>>t;
    while(t--)
    {
        memset(c,0,sizeof(c));
        memset(dp,0,sizeof(dp));
        int s,e,temp;
        cin>>n;
        while(n--)
        {
            cin>>s>>e>>temp;
            if(c[s][e]<temp){c[s][e]=temp;}
        }

        dp[0]=0; //base case;

        fi(i,1,48)
        {
            dp[i]=0;
            fi(j,0,i)
            {
                dp[i]=max(dp[j]+c[j][i],dp[i]);
            }
        }
        cout<<dp[48]<<endl;
    }
    //fclose(stdin);
	return 0;
}

