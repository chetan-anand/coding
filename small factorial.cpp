#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;
long long int fact(int n)
{
    long long int ans=1;
    for(int i=1;i<=n;i++){ans=ans*i;}
    return ans;
}


int main()
{
    long long int t;long long int n,i,j,k;
    scanf("%lld",&t);
    while(t--)
    {

        scanf("%d",&n);
        printf("%lld\n",fact(n));

    }

	return 0;
}
