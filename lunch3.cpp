#include<bits/stdc++.h>
using namespace std;

///////////////////////// fast i/o ////////////
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
int a[1100000];

int gcd(int a,int b)
{
    int temp,m;
    if(b>a){temp=a;a=b;b=temp;}
    while(b!=0)
    {
        m=a%b;
        a=b;
        b=m;
    }
    return a;
}

int main()
{
    //freopen("i.txt","r",stdin);
    int n;
    //cin>>n;
    fastRead_int(n);
    rep(i,n)
    {
        //cin>>a[i];
        fastRead_int(a[i]);
    }
    int cnt=0;
    rep(i,n-2)
    {
        fi(j,i+1,n-2)
        {
            int temp=gcd(a[i],a[j]);
            if(temp==1)
            {
                cnt+=n-1-j;
            }
            else
            {
                fi(k,j+1,n-1)
                {
                    if(gcd(temp,a[k])==1){cnt++;}
                }
            }
        }
    }
    //cout<<cnt<<endl;
    pi(cnt);
    //fclose(stdin);
	return 0;
}

