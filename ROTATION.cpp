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
int main()
{
    //freopen("i.txt","r",stdin);
    int n,m,d,i,j,k;
    int a[110000];
    //cin>>n>>m;
    fastRead_int(n);
    fastRead_int(m);
    rep(i,n)
    {
        //cin>>a[i];
        fastRead_int(a[i]);
    }
    long long int shift=0;
    while(m--)
    {
        char ch;
        cin>>ch;
        fastRead_int(d);
        if(ch=='R')
        {
            int idx=d-1-shift;
            if(idx<0)
                cout<<a[idx+n]<<endl;
            else
                cout<<a[idx]<<endl;
        }

        // Basically in both case i am advancing
        else if(ch=='C')
        {
            shift=(shift+n-d)%n; // instead of retracting shift i advance shift by (n-d)
        }
        else
        {
            shift=(shift+d)%n;  // i am advancing the shift by d
        }
    }

    //fclose(stdin);
	return 0;
}

