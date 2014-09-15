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

int zor(int *a,int n,int ans)
{
	rep(i,n)
	{
		ans=ans^a[i];
	}
	return ans;
}

int nd(int *a,int n,int ans)
{

	rep(i,n)
	{
		ans=ans&a[i];
	}
	return ans;
}

int aur(int *a,int n,int ans)
{

	rep(i,n)
	{
		ans=ans|a[i];
	}
	return ans;
}
int main()
{
    //freopen("i.txt","r",stdin);
	int t,i,j,k,a[1100];
	cin>>t;
	while(t--)
	{
		int n,k,ans;
		cin>>n>>k>>ans;
		rep(i,n)
		{
			cin>>a[i];
		}
		string str;
		cin>>str;
		if(k==0){cout<<ans<<endl;}
		else if(str=="XOR")
		{
			if(k%2==0){cout<<ans<<endl;}
			else{cout<<zor(a,n,ans)<<endl;}
		}
		else if(str=="AND")
		{
			cout<<nd(a,n,ans)<<endl;
		}
		else
		{
			cout<<aur(a,n,ans)<<endl;
		}
	}
    //fclose(stdin);
	return 0;
}
