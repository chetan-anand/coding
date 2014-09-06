#include<bits/stdc++.h>
using namespace std;
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
#define all(a) a.begin(),a.end()

///////////////////////////////////////

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
    int n,i,j,k,l;
    int a,b;
    //cin>>n;
    fastRead_int(n);
    while(n--)
    {
        //cin>>a>>b;
        fastRead_int(a);
        fastRead_int(b);
        int cnt=0;
        while(a!=b)
        {
            if(a>b){a=a>>1;}
            else{b=b>>1;}
            cnt++;
        }
        cout<<cnt<<endl;
    }
    //fclose(stdin);
	return 0;
}

