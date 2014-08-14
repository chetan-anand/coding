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
int main()
{
    int t,i,j,n,q,x,y;
    int fr[110000];
    cin>>t;
    while(t--)
    {
        cin>>n;
        int has[n],a[n];
        for(i=0;i<n;i++)
        {
            fastRead_int(a[i]);
            has[i]=i;
        }
        cin>>q;
        while(q--)
        {
            int cnt;
            fastRead_int(cnt);
            if(cnt==0)
            {
                fastRead_int(x);
                fastRead_int(y);
                x-=1,y-=1;
                int temp1,temp2;
                i=x;
                while(has[i]!=i)
                {
                    i=has[i];
                }
                temp1=i;
                i=x;
                int j;
                while(has[i]!=i)
                {
                    j=has[i];
                    has[i]=temp1;
                    i=j;
                }
                i=y;
                while(has[i]!=i)
                {
                    i=has[i];
                }
                temp2=i;
                i=y;
                while(has[i]!=i)
                {
                    j=has[i];
                    has[i]=temp2;
                    i=j;
                }
                if(temp1==temp2){printf("Invalid query!\n");}
                if(a[temp1]>a[temp2]){has[temp2]=temp1;}
                else if(a[temp2]>a[temp1]){has[temp1]=temp2;}
            }
            else
            {
                fastRead_int(x);
                x-=1;
                i=x;
                while(has[i]!=i){i=has[i];}
                x=i;

                cout<<x+1<<endl;
            }
        }
    }
    return 0;
}
