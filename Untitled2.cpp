#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef vector <long long int> vi;
typedef pair <long long int,long long int> pii;
#define pb push_back
#define mp make_pair
#define gi(n) scanf("%d",&n)
#define gl(n) scanf("%lld",&n)
#define gs(n) scanf("%s",n);
#define pi(n) prlong long intf("%d\n",n)
#define pl(n) prlong long intf("%lld\n",n)
#define ps(n) prlong long intf("%s\n",n);
#define rep(i,n) for(long long int i=0;i<n;i++)
#define fi(i,a,n) for(long long int i=a;i<=n;i++)
#define fd(i,n,a) for(long long int i=n;i>=a;i--)
#define input(f) freopen("f.txt","r",stdin)
    long long int a[150000],b[150000];
int main()
{
    //freopen("i.txt","r",stdin);
    long long int t,n,m,i,j,k;
    cin>>t;

    while(t--)
    {
        //cout<<"a"<<endl;
        cin>>n>>m;
        rep(i,n)
        {

            cin>>a[i];
        }
        rep(i,m)
        {
            cin>>b[i];
        }
//cout<<"a"<<endl;
        sort(a,a+n);
        sort(b,b+m);
        long long int idx=0,x=0;
        long long int temp1=INT_MIN;
        rep(i,n)
        {
            long long int temp=INT_MAX;
            //cout<<"a"<<endl;
            for(j=x;j<=m-n+i;j++)
            {
                //cout<<"b"<<endl;
                if(abs(a[i]-b[j])<temp)
                {
                    idx=j;
                    temp=abs(a[i]-b[j]);
                }
            }
            x=idx+1;
            //cout<<temp<<endl;
            temp1=max(temp,temp1);
        }
        cout<<temp1<<endl;

    }
    //fclose(stdin);
	return 0;
}
