#include<bits/stdc++.h>
using namespace std;

#define max 1100000
bool prime[max];
int dp[1100000];
void initsow()
{
    int i,j,k;
    memset(prime,false,sizeof(prime));
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

void init2()
{
    int cnt=0;
    memset(dp,0,sizeof(dp));
    for(int i=2;i<=1100000;i++)
    {
        if(prime[i]==0)
        {
            cnt++;
            dp[cnt]=i;
        }
    }
}

int main()
{
    int i,j,k;
    initsow();

    //memset(prime,1,sizeof(prime));
//    for(i=1;i<=100;i++)
//    {
//        printf("%d=%d\n",i,prime[i]);
//    }

        init2();
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<dp[n]<<endl;
    }

    return 0;
}


