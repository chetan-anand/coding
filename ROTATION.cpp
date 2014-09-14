#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef vector <int> vi;
typedef pair <int,int> pii;
#define pb push_back
#define mp make_pair
#define gi(n) scanf("%d",&n)
#define gl(n) scanf("%lld",&n)
#define gs(n) scanf("%s",n);
#define pi(n) printf("%d\n",n)
#define pl(n) printf("%lld\n",n)
#define ps(n) printf("%s\n",n);
#define rep(i,n) for(int i=0;i<n;i++)
#define fi(i,a,n) for(int i=a;i<=n;i++)
#define fd(i,n,a) for(int i=n;i>=a;i--)
#define input(f) freopen("f.txt","r",stdin)

int main()
{
    //freopen("i.txt","r",stdin);
    int n,m,d,i,j,k;
    int a[110000];
    cin>>n>>m;
    rep(i,n)
    {
        cin>>a[i];
    }
    long long int shift=0;
    while(m--)
    {
        char ch;
        cin>>ch>>d;
        if(ch=='R')
        {
            int idx=d-1-shift;
            if(idx<0)
                cout<<a[idx+n]<<endl;
            else
                cout<<a[idx]<<endl;
        }
        else if(ch=='C')
        {
            shift=(shift+n-d)%n;
        }
        else
        {
            shift=(shift+d)%n;
        }
    }

    //fclose(stdin);
	return 0;
}

