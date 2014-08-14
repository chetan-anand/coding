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

struct suffix
{
    int index;
    char *suff;
};

int cmp(struct suffix a, struct suffix b)
{
    return strcmp(a.suff, b.suff) < 0? 1 : 0;
}

int *buildSuffixArray(char *txt, int n)
{

    struct suffix suffixes[n];
    for (int i = 0; i < n; i++)
    {
        suffixes[i].index = i;
        suffixes[i].suff = (txt+i);
    }
    sort(suffixes, suffixes+n, cmp);

    int *suffixArr = new int[n];
    for (int i = 0; i < n; i++)
        suffixArr[i] = suffixes[i].index;

    return  suffixArr;
}
int cnt=0;

void search(char *pat, char *txt, int *suffArr, int n)
{
    int m = strlen(pat);

    int l = 0, r = n-1;
    while (l <= r)
    {
        int mid = l + (r - l)/2;
        int res = strncmp(pat, txt+suffArr[mid], m);
        if (res == 0){cnt++;}
        if (res < 0) r = mid - 1;
        else l = mid + 1;
    }
}

int main()
{
    char str[200001],s[200001];
    cin>>str;
    int len=strlen(str),i,j,q,x,y,st=0,m=0;
    int *suffixArr = buildSuffixArray(str,len);
    cin>>q;
    while(q--)
    {
    cin>>x>>y;
    m=0;
    while(m<len)
    {
        for(i=m;i<x;i++)
        {
        s[i]=str[i];
        }
        s[x]='\0';
        m+=x;
        search(s, str, suffixArr, len);
        if(cnt==y){st++;}
    }
    cout<<st<<endl;
    }
    return 0;
}
