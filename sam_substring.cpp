#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main() {
    /* Enter your code here. Read input from STDIN. Prlong long int output to STDOUT */ 
    long long int i,j,k,l;
    long long int dp[220000];
    string s;
    cin>>s;
    memset(dp,0,sizeof(dp));
    //base case
    dp[0]=(long long int)s[0]-48;
    //cout<<dp[0]<<endl;
    for(i=1;i<s.size();i++)
        {
        dp[i]=((dp[i-1]*10)%mod+((i+1)%mod*((long long int)s[i]-48)%mod)%mod)%mod;
        //cout<<dp[i]<<endl;
    }
    
    long long int cnt=0;
    for(i=0;i<s.size();i++)
        {
        	//cout<<dp[i]<<endl;
        cnt=(cnt%mod+dp[i]%mod)%mod;
    }
    cout<<cnt<<endl;
    return 0;
}
