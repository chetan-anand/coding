#include<bits/stdc++.h>
using namespace std;

////////////////////////// fast i/o ////////////
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


inline void fastRead_aing(char *a)
{
    register char c = 0;
    register int i = 0;

    while (c < 33)
        c = getchar_unlocked();

    while (c != '\n') {
        a[i] = c;
        c = getchar_unlocked();
        i = i + 1;
    }

    a[i] = '\0';
}

//////////////////////////////////////////////

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

int main() {
	llu t,n,temp,cnt,len,i,j,k;
	gl(t);
	while(t--)
	{
        char a[100001];
		gl(n);
		scanf("%s",a);
        cnt=0;
		for(i=0;i<strlen(a);i++)
		{
			if(a[i]=='1'){cnt++;}
		}
		temp=(cnt)*(cnt+1);
		temp=temp/2;
		printf("%llu\n",temp);
	}
	return 0;
}
