#include<stdio.h>
int main()
{
    int n,i,j,k,l;
    unsigned long long a[100001];
    scanf("%d",&n);
    if(n>=130){printf("Yes\n");return 0;}
    for(i=0;i<n;i++)
    {
        scanf("%llu",&a[i]);
    }
        for(i=0;i<n-3;i++)
        {
            for(j=i+1;j<n-2;j++)
            {
                for(k=j+1;k<n-1;k++)
                {
                    for(l=k+1;l<n;l++)
                    {
                        if((a[i]^a[j]^a[k]^a[l])==0){printf("Yes\n");return 0;}
                    }
                }
            }
        }
        printf("No\n");
    return 0;
}
