#include<bits/stdc++.h>
//#include<unordered_map>
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
	int t;
	cin>>t;
	for(int tc=1;tc<=t;tc++)
	{
		int n;
		cin>>n;
		map<string,string > mp;
		map<string,int> dp;
		for(int i=0;i<n;i++)
		{
			string src;
			string dest;
			cin>>src;
			cin>>dest;
			mp[src]=dest;
			dp[dest]=INT_MAX;
			dp[src]=dp[src]-1;
		}
		map<string,int>::iterator it;
		string source;
		for(it=dp.begin();it!=dp.end();it++)
		{
			if((*it).second<=0)
			{
				source=(*it).first;
			}
				//cout<<(*it).first<<" "<<(*it).second<<endl;
		}
		//cout<<"source"<<source<<endl;
		int cnt=n;
		cout<<"Case #"<<tc<<":"<<" ";
		while(cnt--)
		{
			cout<<source<<"-"<<mp[source]<<" ";
			source=mp[source];
		}
		cout<<endl;
	}
    //fclose(stdin);
	return 0;
}
