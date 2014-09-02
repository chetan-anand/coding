#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define gi(n) scanf("%d",&n)
#define gl(n) scanf("%llu",&n)
#define pi(n) printf("%d\n",n)
#define pl(n) printf("%llu\n",n)
#define rep(i,n) for(int i=0;i<n;i++)
#define fi(i,a,n) for(int i=a;i<=n;i++)
#define fd(i,n,a) for(int i=n;i>=a;i--)
#define input(f) freopen("f.txt","r",stdin)

int main()
{
    	int t,i,j,flag;
        char str[100001];
        t=inp();
        while(t--)
        {
            cin>>str;
            flag=0;
            for(i=0,j=strlen(str)-1;i<j;i++,j--)
            if(str[i]!=str[j])
            flag=1;
            if(flag)
            printf("2\n");
            else
            printf("1\n");
        }
        return 0;
}
