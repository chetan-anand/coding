#include <iostream>
#include <cstdio>
using namespace std;
long long int dp[1000005];
int main()
{
    long long int i;
    
    dp[0] = 1ll;
    dp[2] = 3ll;
    for (i = 3 ; i <= 1000000 ; i++)
    {
        dp[i] = ( (dp[i-1] % 1000000007) + (dp[i-1] % 1000000007) + 1 ) % 1000000007;
    }
    long long int t,n;
    cin>>t;
    while (t--)
    {
        cin>>n;
        cout<<dp[n]<<endl;
    }
    return 0;
}