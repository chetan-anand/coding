#include<bits/stdc++.h>
using namespace std;
//bottom up approach
int dp[100][100];
void init()
{
    memset(dp,0,sizeof(dp));
}

int waysCoinChange(int *s,int m,int n)
{
    if(n<0){return 0;}
    else if(m<0&&n>0){return 0;}
    else if(n==0){return 1;}
    else if(dp[m][n]>0){return dp[m][n];}
    else
    {
        dp[m][n]=dp[m-1][n-s[m]]+dp[m-1][n];
    }
    return dp[m][n];
}
//////////////////////
int main()
{
    int
    return 0;
}
