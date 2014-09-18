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
	long long int t,i,j,k,x,y,x1,x2,y1,y2;
	cin>>t;
	while(t--)
	{
		cin>>x>>y>>x1>>y1>>x2>>y2;
		cout<<min(min(abs(x1-x),abs(x2-x)),min(abs(y1-y),abs(y2-y)))<<endl;
	}
    //fclose(stdin);
	return 0;
}
