#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long


int main()
{

    ll l[1100],a,b,c,n,t,i,j,k,temp;
    char s[1100];

    scanf("%llu",&t);
    while(t--)
    {
        scanf("%llu",&n);
        for(i=0;i<n;i++)
        {
            scanf("%llu",&l[i]);
        }
        scanf("%llu %llu %llu",&a,&b,&c);
        scanf("%s",s);
        //cout<<s<<endl;

        for(i=0;i<n;i++)
        {
            if(s[i]=='R')
            {
                for(j=i,k=0;j<=(n+i)/2;j++,k++)
                {
                    temp=l[j];
                    l[j]=(l[n-1-k])%c;
                    l[n-1-k]=(temp)%c;
                }
                printf("%llu ",l[i]);
            }

            if(s[i]=='A')
            {
                for(j=i;j<n;j++)
                {
                    l[j]=((l[j]%c)+(a%c))%c;
                }
                printf("%llu ",l[i]);
            }

            if(s[i]=='M')
            {
                for (j=i;j<n;j++)
                {
                    l[j]=((l[j]%c)*(b%c))%c;
                }
                printf("%llu ",l[i]);
            }
            
        }
        printf("\n");
    }
    return 0;
}
