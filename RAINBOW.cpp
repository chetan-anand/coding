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
int c[1000004][7];
void pre(int n)
{
	memset(c,0,sizeof(c));
	/*fi(i,1,n)
	{
		c[i][0]=1;
		c[i][i]=1;
		c[i][1]=i;
	}*/
	fi(i,1,n)
	{
		fi(j,0,min(i,6))
		{
			if(i==j || j==0)
				c[i][j]=1;  // Base cases we have to stop here and do not go to normal recursion for base inputs.
				// Keep above point in mind
			else
				c[i][j]=((c[i-1][j])%mod + (c[i-1][j-1])%mod)%mod;
		}
	}
}
int main()
{
    //freopen("i.txt","r",stdin);
	int n,i,j,k;
	cin>>n;
	//fastRead_int(n);
	if(n<13)
		cout<<"0"<<endl;
	else if(n==13)
		cout<<"1"<<endl;
	else
	{
		int cnt=0,temp;
		if(n%2==0){temp=2;}
		else{temp=1;}
		pre(n/2);   // pre processing and store all the binomial coefficient which can be later used
		//cout<<c[4][2]<<endl;
		for(i=temp;i<=n-12;i+=2)
		{
			int p=(n-i)/2;
			p=p-1;
			// now for each i we have to find tatal no of
			// positive integral solution for a1+a2+a3+a4+a5+a6=p;
			// which p C 5

			cnt=((cnt%mod)+c[p][5])%mod;
		}
        cout<<cnt<<endl;
		//cout<<c[(n-1)/2][6]<<endl;
	}
    //fclose(stdin);
	return 0;
}
