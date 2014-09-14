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
#define fill(a) memset(a,0,sizeof(a))

int main()
{
    //freopen("i.txt","r",stdin);
    int t,i,j,k;
    int a[11000],b[11000];
    int h[1100];
    cin>>t;
    while(t--)
    {

        int n,m;
        fill(h);
        cin>>n>>m;
        rep(i,m)
        {
            cin>>a[i]>>b[i];
        }


        vector<int> ans;
        fd(i,m-1,0)
        {
            if(h[a[i]]==0 && h[b[i]]==0)
            {
                h[a[i]]++;
                h[b[i]]++;
                ans.pb(i);
            }
        }
        vector<int>::iterator it;
        fd(i,ans.size()-1,0)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;

    }

    //fclose(stdin);
	return 0;
}

