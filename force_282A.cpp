#include<bits/stdc++.h>
using namespace std;

///////////////////////// fast i/o ////////////
/*
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
*/
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
   int t;

   cin>> t;
   int cnt;
   cnt=0;
   while(t--)
   {
        char q[10];
        cin>>q;
        if(q[0]=='X')
        {
            if(q[1]=='+')
            {
                cnt++;
            }
            else{cnt--;}
        }
        if(q[0]=='+'){cnt++;}
        if(q[0]=='-'){cnt--;}
   }
   cout<<cnt<<endl;
	return 0;
}
