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
#define oi(n) printf("%d\n",n)
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


class disjoint
{
    int sz;
    vi p;
    vector<pii> snp;
public:
    disjoint(int n)
    {
        init(n);
    }

    void init(int n)
    {
        sz=n;
        p.resize(n);
        for (int i = 0; i <n; i++)
        {
            p[i]=i;
        }
        snp.clear();
    }

    int foo(int i)
    {
        if(i==p[i]) return i;
        snp.push_back(make_pair(i,p[i]));
        int ret=foo(p[i]);
        p[i]=ret;
        return ret;
    }

    void snap()
    {
        snp.clear();
    }
    void roll()
    {
        for(int i=snp.size()-1;i>=0;i--)
        {
            p[snp[i].first]=snp[i].second;
            if(snp[i].first==snp[i].second)
                sz++;
        }
        snp.clear();
    }

    int size()
    {
        return sz;
    }

    void join(int i,int j)
    {
        if(i==j)return;
        int pi=foo(i),pj=foo(j);
        if(pi!=pj)
        {
            snp.push_back(make_pair(pi,pi));
            p[pi]=pj;
            sz--;
        }
    }

};
int sq;
bool cmp(pair<pii,int> A,pair<pii,int> B)
{
    if(A.first.first/sq!=B.first.first/sq)
    {
        return A.first.first/sq<B.first.first/sq;
    }
    return A.first.second<B.first.second;
}

int main()
{
    int t,n,m,Q;
    fastRead_int(t);
    while(t--)
    {
        fastRead_int(n);
        fastRead_int(m);
        fastRead_int(Q);
        pair<pii,int> q[Q];
        pii edge[m];
        int xx,yy;
        for (int i = 0; i < m; i++)
        {
            fastRead_int(xx);
            fastRead_int(yy);
            edge[i]=make_pair(xx-1,yy-1);
        }
        int ans[Q];
        sq=sqrt(m);

        disjoint d(n);
        for (int i = 0; i < Q; i++)
        {
            fastRead_int(xx);
            fastRead_int(yy);
            q[i]=make_pair(make_pair(xx-1,yy-1),i);
        }

        sort(q,q+Q,cmp);

        for (int i = 0; i < Q; i++)
        {
            if(q[i].first.second<=sq+q[i].first.first)
            {
                for (int j = q[i].first.first; j < q[i].first.second+1; ++j)
                {
                    d.join(edge[j].first,edge[j].second);
                }
                ans[q[i].second]=d.size();
                d.roll();
            }
        }
        int last=-1,cur;
        for (int i = 0; i < Q; i++)
        {
            if(q[i].first.second<=sq+q[i].first.first){continue;}
            cur=q[i].first.first/sq;
            int l,r;
            if(cur!=last)
            {
                d.init(n);
                l = (cur+1)*sq,r=q[i].first.second;
                for(int j=l;j<r+1;j++)
                {
                    d.join(edge[j].first,edge[j].second);
                }
                d.snap();
            }
            last=cur;
            while (r <=q[i].first.second)
            {
                d.join(edge[r].first,edge[r].second);
                r++;
            }
            d.snap();
            for(int j=q[i].first.first;j<l;j++)
            {
                d.join(edge[j].first,edge[j].second);
            } 
            ans[q[i].second]=d.size();
            d.roll();
        }
        for (int i = 0; i < Q; i++)
        {
            oi(ans[i]);
        }
    }
	return 0;
}
