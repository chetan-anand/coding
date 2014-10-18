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
		string str;
		cin>>str;
		int dp[20000];
		int cnt=0;
		int freq[400],len=str.size();
		memset(freq,0,sizeof(freq));
		for(int i=0;i<len;i++)
		{
			freq[str[i]]++;
			//cout<<"asd"<<endl;
			if(str[i]=='#'||i==(len-1))
			{
				int maxv=INT_MIN;
				for(int j='a';j<='z';j++)
				{
					maxv=max(maxv,freq[j]);
					//cout<<"max"<<maxv<<endl;
				}
				cout<<maxv<<endl;
				dp[cnt]=maxv;
				cnt++;
				//memset(freq,0,sizeof(freq));
			}
			
		}
		int maxv=INT_MIN;
		/*rep(i,cnt+1)
		{
			cout<<dp[i]<<endl;
		}*/
		for(int i=0;i<cnt-4+1;i++)
		{
			maxv=max(maxv,dp[i]+dp[i+1]+dp[i+2]+dp[i+3]+3);
		}
		//cout<<maxv<<endl;
		cout<<"skdf"<<endl;
	}
    //fclose(stdin);
	return 0;
}
