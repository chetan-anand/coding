
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

int main()
{
    //freopen("i.txt","r",stdin);

    int t,n,i,j,k,b;
    int a[110][110];
    int dp[110][110];
    //scanf("%d",&t);
    //while(t--)
    {
        cin>>n>>m;
        //scanf("%d",&n);
        int cnt=0;
        for(i=0;i<m;i++)
        {
            for(j=0;j<=n;j++)
            {

                //uint32_t b = g_fi.ReadNext();
                cin>>a[j][i];
                //a[i][j]=b;
            }
        }

        for(i=n-1;i>=0;i--)
        {
            for(j=0;j<=i;j++)
            {
                if(i==(n-1)){dp[i][j]=a[i][j];}
                else
                {

                    int temp=max(dp[i+1][j],dp[i+1][j+1]);
                    dp[i][j]=a[i][j] + temp;

                }
            }

        }

        printf("%d\n",dp[0][0]);
    }
	return 0;
    //fclose(stdin);
	return 0;
}
