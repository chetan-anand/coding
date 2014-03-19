#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> PI;
typedef vector<int> VI;
typedef long long LL;

#define FOR(i,a,b) for(register int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define PB push_back
#define mod 1000000007
#define MP make_pair
#define INF mod

class disjoint
{
    int sz;
    VI p;
    vector<PI> snp;
public:
    disjoint(int n)
    {
        init(n);
    }
    void init(int n)
    {
        sz=n;
        p.resize(n);
        REP(i,n) p[i]=i;
        snp.clear();
    }
    int fn(int i)
    {
        if(i==p[i]) return i;
        snp.PB(MP(i,p[i]));
        int ret=fn(p[i]);
        p[i]=ret;
        return ret;
    }
    void snap()
    {
        snp.clear();
    }
    void roll()
    {
        FORD(i,snp.size()-1,0){
        p[snp[i].first]=snp[i].second;
        if(snp[i].first==snp[i].second) sz++;
        }
        snp.clear();
    }
    int size()
    {
        return sz;
    }
    void jn(int i,int j)
    {
        if(i==j) return;
        int pi=fn(i),pj=fn(j);
        if(pi!=pj)
        {
            snp.PB(MP(pi,pi));
            p[pi]=pj;
            sz--;
        }
    }
};
int sq;
bool cmp(pair<PI,int> A,pair<PI,int> B)
{
    if (A.first.first/sq!=B.first.first/sq) return A.first.first/sq<B.first.first/sq;
    return A.first.second<B.first.second;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int t,n,m,Q;
    for(cin>>t; t--;)
    {
        cin>>n>>m>>Q;
        pair<PI,int> q[Q];
        PI edge[m];
        int xx,yy;
        REP(i,m)
        {
            cin>>xx>>yy;
            edge[i]=MP(xx-1,yy-1);
        }
        int ans[Q];
        sq=sqrt(m);
        disjoint d(n);
        REP(i,Q)
        {
            cin>>xx>>yy;
            q[i]=MP(MP(xx-1,yy-1),i);
        }
        sort(q,q+Q,cmp);
        REP(i,Q)
        {
            if(q[i].first.second<=sq+q[i].first.first)
            {
                FOR(j,q[i].first.first,q[i].first.second+1)
                {
                    d.jn(edge[j].first,edge[j].second);
                }
                ans[q[i].second]=d.size();
                d.roll();
            }
        }
        int last=-1,cur;
        REP(i,Q)
        {
            if(q[i].first.second<=sq+q[i].first.first) continue;
            cur=q[i].first.first/sq;
            int l,r;
            if(cur!=last)
            {
                d.init(n);
                l = (cur+1)*sq,r=q[i].first.second;
                FOR(j,l,r+1)  d.jn(edge[j].first,edge[j].second);
                d.snap();
            }
            last=cur;
            while (r <=q[i].first.second)
            {
                d.jn(edge[r].first,edge[r].second);
                r++;
            }
            d.snap();
            FOR(j,q[i].first.first,l) d.jn(edge[j].first,edge[j].second);
            ans[q[i].second]=d.size();
            d.roll();
        }
        REP(i,Q) cout<<ans[i]<<endl;
    }
    return 0;
}