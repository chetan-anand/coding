#include<bits/stdc++.h>
using namespace std;

/*///////////////////////// fast i/o ////////////
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

//////////////////////////////////////////////*/

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

//////////////// bondapa /////////////
#define all(a) a.begin(),a.end()
#define imax numeric_limits<int>::max()
#define imin numeric_limits<int>::min()
#define lmax numeric_limits<llu>::max()
#define lmin numeric_limits<llu>::min()
///////////////////////////////////////
#define sz 1000003

char s[sz];
int dpa[sz];
int dpb[sz];
int dpc[sz];
struct node
{
	int val,ind;
}a[100005];
bool operator < (node x,node y)
{
	return x.val<y.val;
}
int n,k,p;
int comp[100005],c;
int main()
{
	int x,y;
	scanf("%d %d %d",&n,&k,&p);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].val);
		a[i].ind=i;
	}
	sort(a+1,a+n+1);
	c=0;
	comp[a[0].ind]=c;
	for(int i=2;i<=n;i++)
	{
		if(a[i].val-a[i-1].val<=k)
			comp[a[i].ind]=c;
		else
			comp[a[i].ind]=++c;
	}
	for(int i=0;i<p;i++)
	{
		scanf("%d %d",&x,&y);
		if(comp[x]==comp[y])
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
