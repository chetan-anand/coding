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
#define mod 1000000007
inline void fastRead_int(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    int neg = 0;

    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

    if(c=='-') {
    	neg = 1;
    	c = getchar_unlocked();
    }

    for(; c>47 && c<58 ; c = getchar_unlocked()) {
    	x = (x<<1) + (x<<3) + c - 48;
    }

    if(neg)
    	x = -x;
}

inline void fastRead_string(char *str)
{
    register char c = 0;
    register int i = 0;

    while (c < 33)
        c = getchar_unlocked();

    while (c != '\n') {
        str[i] = c;
        c = getchar_unlocked();
        i = i + 1;
    }

    str[i] = '\0';
}
int main()
{
    //freopen("i.txt","r",stdin);
	int t,i,j,k;
	//cin>>t;
	fastRead_int(t);
	while(t--)
	{
		string str;
		cin>>str;
		//cout<<str<<endl;
		long long int temp=1,cnt=1;
		rep(i,str.size())
		{
			if(cnt%2!=0)
			{
				if(str[i]=='l')
				{
					temp=((temp%mod)*2)%mod;
				}
				else
				{
					temp=(((temp%mod)*2)%mod+2)%mod;
				}
			}
			else
			{
				if(str[i]=='r')
				{
					temp=(((temp%mod)*2)%mod+1)%mod;
				}
				else
				{
					temp=(((temp%mod)*2)%mod-1)%mod;
				}
			}
			cnt++;
		}
		cout<<temp<<endl;
	}
    //fclose(stdin);
	return 0;
}
