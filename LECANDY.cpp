#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef vector <int> vi;
typedef pair <int,int> pii;
#define pb push_backCobie Smulders.
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
	int t,i,j,k;
	cin>>t;
	while(t--)
	{
		int n,c;
		cin>>n>>c;
		int cnt=0;
		rep(i,n)
		{
			int temp;
			cin>>temp;
			cnt=cnt+temp;
		}
		if(c>=cnt){cout<<"Yes"<<endl;}
		else{cout<<"No"<<endl;}
	}
    //fclose(stdin);
	return 0;
}
