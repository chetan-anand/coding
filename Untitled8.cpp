#include<iostream>
#include<stdio.h>
#include<functional>
#include<algorithm>
#include<math.h>
#include<limits.h>

#include<set>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<deque>

#include<cstring>
#include<string>


#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define lli long long int
#define mod1 1000000007
#define mod2 1000000009
#define ppi pair<int,int>
#define tr(a,it) for(typeof(a.begin()) it=a.begin();it!=a.end();it++)

using namespace std;

int main()
{
    int t;

    scanf("%d",&t);

    while(t--)
    {
              int n,c,k;
              scanf("%d%d%d",&n,&c,&k);

              double dp[n+2][k+2][c+1];

              FOR(i,0,n)FOR(j,0,c-1)FOR(s,0,k)dp[i][s][j]=0;

              FOR(i,1,n)dp[i][0][1]=1;

              FOR(s,1,k)
              {
                     int l,r;
                     scanf("%d%d",&l,&r);

                     FOR(i,1,l-1)
                     {
                          FOR(j,0,c-1)dp[i][s][j]=dp[i][s-1][j];
                     }

                     FOR(i,r+1,n)
                     {
                          FOR(j,0,c-1)dp[i][s][j]=dp[i][s-1][j];
                     }

                     FOR(i,l,r)
                     {
                               FOR(j,0,c-1)dp[i][s][j]+=(dp[i][s-1][j]/2);
                     }

                     FOR(i,l,r)
                     {
                               FOR(j,0,c-1)
                               {
                                           FOR(z,0,c-1){dp[i][s][(j*z)%c]+=(dp[i][s-1][j]/(2*c));}
                               }
                     }


              }

              double ans=0;

              FOR(i,1,n)
              {
                        FOR(j,0,c-1)ans+=j*dp[i][k][j];
              }

              printf("%.9lf\n",ans);

    }

    return 0;
}






