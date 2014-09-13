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

int main()
{
    //freopen("i.txt","r",stdin);
	long long int t,i,j,k,n,a,b,c;
	cin>>t;
	while(t--)
	{
		cin>>n>>a>>b>>c;
		long long int cnt=0;
		fi(i,0,a)
		{
			fi(j,0,b)
			{
				if((n-i-j)>=0)
				{
					cnt+=min(c,n-i-j)+1;
				}
				else{break;}
				
			}
		}
		cout<<cnt<<endl;
	}
    //fclose(stdin);
	return 0;
}
