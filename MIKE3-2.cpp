#include<iostream>  
#include<cstdio>  
#include<string.h>  
using namespace std;  
 
const int MAX=1<<20;  
int mp[21][20001],n,m;  
int a[21][21],num[MAX],dp[MAX];  
void init(){  
    num[0]=0;  
    for(int i=1;i<MAX;i++)  
        num[i]=num[i-(i&-i)]+1;  
}  
int ok(int state){  
    int last=state&-state,t;  
    if(dp[state-last]==0) return 0;  
    last=-1,t=0;  
    while(state){  
        if(state&1){  
            if(last==-1)  
                last=t;  
            else{  
                if(a[t][last]==1)  
                    return 0;  
            }  
        }  
        t++;  
        state>>=1;  
    }  
    return 1;  
}  
int main(){  
    int k,t;  
    init();  
    while(cin>>n>>m){  
        memset(mp,0,sizeof mp);  
        for(int i=0;i<m;i++){  
            scanf("%d",&k);  
            for(int j=0;j<k;j++)  
                scanf("%d",&t),mp[i][t]=1;  
        }  
        memset(a,0,sizeof a);  
        for(int i=0;i<m;i++){//O(m*m*n) 0.1s   
            for(int j=i+1;j<m;j++)  
                for(int k=1;k<=n;k++)  
                    if(mp[i][k]&&mp[j][k]){//
                        a[j][i]=a[i][j]=1;break;  
                    }  
        }  
        memset(dp,0,sizeof dp);  
        int mx=1<<m,ans=0;  
        dp[0]=1;  
        for(int s=1;s<mx;s++){  
            if(ok(s)){  
                dp[s]=1;  
                ans=max(ans,num[s]);  
            }  
        }  
        printf("%d\n",ans);  
    }  
    return 0;  
} 