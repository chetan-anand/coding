#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#define maxv 100002
#define max(a,b) a>b?a:b
using namespace std;

bool dp[maxv];
bool pd(long long int n)
{
    long long int temp;
    while(n>0)
    {
        temp=n%10;
        if(temp!=0 &&temp!=1&&temp!=4&&temp!=9)
        {
            return false;
        }
        n=n/10;
    }
    return true;
}

void init()
{
    long long int i;
    dp[0]=true;
    for(i=1;i<=100005;i++)
    {
        if(pd(i*i)){dp[i]=true;}
        /*{dp[i]=dp[i-1]+1;}
        else{dp[i]=dp[i-1];}*/
    }
    for(i=0;i<=100;i++){printf("%lld=%d ",i,dp[i]);}
    printf("\n\n\n---------------------------------------------------------------------------------------\n\n\n");
}

int main()
{
    long long int t,i,j,a,b,cnt;
    memset(dp,false,sizeof(dp));
    init();
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&a,&b);
        //if(a==b){printf("%d\n",pd(a));continue;}
        a=(long long int)sqrt(a);
        b=(long long int)sqrt(b);
        cnt=0;
        //printf("a=%lld  b=%lld\n",a,b );
        for(i=a;i<=b;i++)
        {
            if(dp[i]){cnt++;}
            //printf("%lld  %lld\n",i,cnt );
        }

        printf("%lld\n",cnt);
    }

	return 0;
}
