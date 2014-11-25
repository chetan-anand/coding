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

long long int city[1100000];
int main()
{
    //freopen("i.txt","r",stdin);
	long long int t;
	cin>>t;
	for(long long int tc=1;tc<=t;tc++)
	{
		long long int n;
		cin>>n;
		memset(city,0,sizeof(city));
		for(long long int i=0;i<n;i++)
		{
			long long int a,b;
			cin>>a>>b;
			for(long long int j=a;j<=b;j++)
			{
				city[j]++;
			}
		}

		 long long int q;
		 cin>>q;
		cout<<"Case #"<<tc<<":"<<" ";
		while(q--)
		{
			long long int temp;
			cin>>temp;
		 	cout<<city[temp]<<" ";
		 }
		 cout<<endl;
	}
    //fclose(stdin);
	return 0;
}
