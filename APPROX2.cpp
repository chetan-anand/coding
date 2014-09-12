#include<bits/stdc++.h> 
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    int i,j,k,n,temp,min;
    int a[10000];
    while(t--)
    {
        memset(a,0,sizeof(a));
        scanf("%d %d",&n,&k);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<=n-2;i++)
        {
            for(j=i+1;j<=n-1;j++)
            {
                if(i==0 && j==1)
                {
                    min=abs(a[i]+a[j]-k);
                }
                if(abs(a[i]+a[j]-k)<min){min=abs(a[i]+a[j]-k);}
            }
        }
        int cnt=0;
        for(i=0;i<=n-2;i++)
        {
            for(j=i+1;j<=n-1;j++)
            {
                if(abs(a[i]+a[j]-k)==min){cnt++;}
            }
        }
        printf("%d %d\n",min,cnt);
    }    
	return 0;
}
