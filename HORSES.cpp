#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef vector <int> vi;
typedef pair <int,int> pii;

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
#define all(a) a.begin(),a.end()

///////////////////////////////////////

int main()
{
    //freopen("i.txt","r",stdin);
    int t,i,j,k,a[6000],n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        rep(i,n)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        int minv=INT_MAX;
        rep(i,n-1)
        {
            minv=min(a[i+1]-a[i],minv);
        }
        cout<<minv<<endl;
    }
    //fclose(stdin);
	return 0;
}

