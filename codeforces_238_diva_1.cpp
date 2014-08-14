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

int a[1001][1001];

int main()
{
    freopen("i.txt","r",stdin);
    int n,i,j,k,m,q;
    gi(n);
    memset(a,0,sizeof(a));
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            gi(a[i][j]);
        }
    }

    gi(m);int temp;
    while(m--)
    {
        gi(q);
        if(q==1)
        {
            gi(temp);
            for(i=0;i<n;i++)
            {
                if(a[temp][i]==1){a[temp][i]=0;}
                else{a[temp][i]=1;}
            }
        }
        if(q==2)
        {
            gi(temp);
            for(i=0;i<n;i++)
            {
                if(a[i][temp]==1){a[i][temp]=0;}
                else{a[i][temp]=1;}
            }
        }
        if(q==3)
        {
            int sum=0;
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    sum=sum+a[i][j]*a[j][i];
                }
            }
            sum=sum%2;
            pi(sum);
        }
    }
    fclose(stdin);
	return 0;
}
