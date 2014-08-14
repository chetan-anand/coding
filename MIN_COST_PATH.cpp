#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
////////////////// top down approach /////
int minCost(int cost[3][3],int m,int n)
{
    memset(dp,0,sizeof(dp));
    dp[0][0]=cost[0][0];
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0&&j==0){continue;}
            else if(i==0){dp[i][j]=dp[i][j-1]+cost[i][j];}
            else if(j==0){dp[i][j]=dp[i-1][j]+cost[i][j];}
            else{dp[i][j]=cost[i][j]+min(dp[i-1][j],dp[i][j-1]);}
        }
    }
    return dp[m][n];
}
int main()
{
    int cost[3][3] = { {1, 2, 3},{4, 8, 2},{1, 5, 3} };
    printf("min cost path is %d \n", minCost(cost, 2, 2));
    return 0;
}
