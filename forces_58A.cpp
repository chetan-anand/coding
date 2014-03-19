#include<bits/stdc++.h>
using namespace std;

///////////////////////// fast i/o ////////////
/*inline void fastRead_int(int &x) {
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
}*/

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



int main()
{
    int t,i,j,k;
    char ch[111];
    int h=1,e=1,l=2,o=1;
    cin>>ch;int cnt=0;
    for(i=0;ch[i]!='\0';i++)
    {
        if(ch[i]=='h' && h>0){h--;cnt++;}
        if(ch[i]=='e' && h==0 && e>0){e--;cnt++;}
        if(ch[i]=='l' && e==0 && l>0){l--;cnt++;}
        if(ch[i]=='o' && l==0 && o>0){o--;cnt++;}
        if(o==0){break;}
    }
    //cout<<l<<endl;
    //cout<<o<<endl;
    if(o==0){cout<<"YES\n";}
    else{cout<<"NO\n";}

	return 0;
}
