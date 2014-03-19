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


inline void fastRead_long(long long &x) {
    register long long c = getchar_unlocked();
    x = 0;
    long long neg = 0;

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

////////////////////////////////////////////////////////////

typedef long long ll;
typedef unsigned long long llu;
typedef vector <int> vi;
typedef pair <int,int> pii;

#define pb push_back
#define mp make_pair
#define gi(n) scanf("%d",&n)
#define gl(n) scanf("%lld",&n)
#define pi(n) printf("%d\n",n)
#define pl(n) printf("%lld\n",n)
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


int main()
{
    int s[1000010],i,n,a,b,c,d,t,temp;
    ll ans1,ans2,temp1;
    fastRead_int(t);
    while(t--)
    {
        fastRead_int(n);
        fastRead_int(a);
        fastRead_int(b);
        fastRead_int(c);
        fastRead_int(d);
        memset(s,0,sizeof(s));
        temp1=d,ans1=0,ans2=0;
        ++s[d];
        for(i=1;i<n;++i)
            {
                temp1=(temp1*temp1*a+temp1*b+c)%1000000;
                ++s[temp1];
            }
        temp=0;
        for(i=1000000;i>=0;--i)
        {
            while(s[i]--)
            {
                if(temp%2==0)
                    ans1=ans1+i;
                else
                    ans2=ans2+i;
                temp++;
            }
        }
        pl(ans1-ans2);
    }
    return 0;
} 