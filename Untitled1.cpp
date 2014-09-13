/* @uthor - Shivam Saxena */
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<set>
#include<map>
#include<iostream>
#include <list>
using namespace std;
#define mod 1000000007
long long power(long long b, long long e) {
    long long p = 1;
    while (e > 0) {
        if(e&1) {
            p = (p*b)%mod;
        }
        e = e>>1;
        b = (b * b)%mod;
    }
    return p;
}

int main()
{
    int t;
    long long n,m,i,ans,sqrtn,k;
    double y,t1,t2,x;
    scanf("%d",&t);
    while(t--)
    {

        scanf("%lld %lld",&n,&mod);
        if(n==1)
        {
            P1(n%m);
            continue;
        }
        k=0;
        ans=n%mod;
        sqrtn=(long long)floor(sqrt(n));
        for (i = 2; i <= sqrtn; i++)
        {
            x=1.0*i;
            y=1.0*ans;
            y=fmod(y+x*x*x*x*floor(1.0*n/x),mod);
            ans=(long long)y;

        }
        for(i=1;i<=sqrtn && !k;i++)
        {
            t1=1.0*(n/(i+1));
            t2=1.0*(n/i);
            if(t1==sqrtn)
                k=1;
            t1=t1*(t1+1)*(2*t1+1)*(3*t1*t1+3*t1-1)/30;
            t2=t2*(t2+1)*(2*t2+1)*(3*t2*t2+3*t2-1)/30;
            y=1.0*ans;
            y=fmod((y+(t2-t1)*i),mod);
            ans=(long long)y;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

