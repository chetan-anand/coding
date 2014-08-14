#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

struct node
{
    long long int tp;
    bool visited;
}b[110000];

long long int t,n,a[110000];
long long int tp[110000];
long long int visit[110000];

long long int gcd(long long int a,long long int b)
{
    long long int temp,m;
    if(b>a){temp=a;a=b;b=temp;}
    while(b!=0)
    {
        m=a%b;
        a=b;
        b=m;
    }
    return a;
}

long long int lcm(long long int a,long long int b)
{
    long long int ans= ((a%MOD)*(b%MOD))%MOD;
    ans/=gcd(a,b);
    return ans;
}


int main()
{
   // freopen("i.txt","r",stdin);

    long long int i,j,k,temp;

    cin>>t;

    while(t--)
    {
        memset(a,0,sizeof(a));
        memset(visit,0,sizeof(visit));
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
        }

        //////// precomputing the values ////// o(n)
        long long int ans=1;
        for(i=1;i<=n;i++)
        {
            long long int temp1;
            long long int temp2;
            if(visit[i]==0)
            {
                temp1=1;
                temp2=i;
                while(1)
                {
                    temp=a[temp2];
                    visit[temp]=1;
                    if(temp==i){break;}
                    temp1++;
                    temp2=temp;
                }
                //cout<<"tem1= "<<temp1<<endl;
                ans=(lcm(temp1,ans%MOD))%MOD;
            }

        }


//        for(i=1;i<=n;i++)
//        {
//            printf("tp=%lld\n",tp[i]);
//        }

        printf("%lld\n",ans);
        //cout<<endl;

    }
   // fclose(stdin);
    return 0;
}
