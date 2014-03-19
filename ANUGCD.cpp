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
#define SIZE 200000
#define pb push_back
#define mp make_pair
int n, m, mat[SIZE];
#define gi(n) scanf("%d",&n)
struct type {int temp;int cnt;};
#define gl(n) scanf("%lld",&n)
#define pi(n) printf("%d\n",n)
vector<int> v[SIZE],repe[SIZE],modi[SIZE];
vector<type> narendra[SIZE];
#define pl(n) printf("%lld\n",n)
#define rep(i,n) for(int i=0;i<n;i++)
#define fi(i,a,n) for(int i=a;i<=n;i++)
#define fd(i,n,a) for(int i=n;i>=a;i--)
#define input(f) freopen("f.txt","r",stdin)
//////////////// bondapa /////////////
#define all(a) a.begin(),a.end()
#define itemp numeric_limits<int>::temp()
#define imin numeric_limits<int>::min()
#define ltemp numeric_limits<llu>::temp()
#define lmin numeric_limits<llu>::min()
///////////////////////////////////////
void segmentTree(int modi, int idx, int s, int e) {
    if(s == e) {narendra[modi][idx].temp = mat[repe[modi][s]];narendra[modi][idx].cnt = 1;
        return;
    }
    segmentTree(modi, idx*2 + 1, s, (s+e)/2);
    segmentTree(modi, idx*2 + 2, (s+e)/2 + 1, e);
    if(narendra[modi][idx*2 + 1].temp > narendra[modi][idx*2 + 2].temp) {
        narendra[modi][idx] = narendra[modi][idx*2 + 1];
    }
    else if(narendra[modi][idx*2 + 1].temp < narendra[modi][idx*2 + 2].temp) {
        narendra[modi][idx] = narendra[modi][idx*2 + 2];
    }
    else {
        narendra[modi][idx] = narendra[modi][idx*2 + 1];
        narendra[modi][idx].cnt = narendra[modi][idx*2 + 2].cnt + narendra[modi][idx*2 + 1].cnt;
    }
}
type query(int modi, int idx, int s, int e, int x, int y)
{
        if(s == x && e == y) {
            return narendra[modi][idx];
        }
        if(y <= (s+e)/2) {
            return query(modi, idx*2 + 1, s, (s+e)/2, x, y);
        }
        else if(x > (s+e)/2) {
            return query(modi, idx*2 + 2, (s+e)/2 + 1, e, x, y);
        }
        else {
            type l, r, res;
            l = query(modi, idx*2 + 1, s, (s+e)/2, x, (s+e)/2);
            r = query(modi, idx*2 + 2, (s+e)/2 + 1, e, (s+e)/2 + 1, y);
            if(l.temp > r.temp) {
                return l;
            }
            else if(l.temp < r.temp) {
                return r;
            }
            else {
                res = l;
                res.cnt = r.cnt + l.cnt;
                return res;
            }
        }
}
int main()
{
    int hello,world,ans, x, y,i,j,k,lefty,righty,temp1;
    fastRead_int(n);
    fastRead_int(m);
    for(i = 2; i <= 100000; i++) {
        ans = i;
        for(j = 2; j * j <= ans; j++) {
            if(ans % j == 0) {      
                modi[i].push_back(j);
                while(ans % j == 0) {
                    ans /= j;
                }
            }
        }
        if(ans > 1) {
            modi[i].push_back(ans);
        }
    }
    type aa;
    for(i = 0; i < n; i++) {
        fastRead_int(mat[i]);
        for(j = 0; j < modi[mat[i]].size(); j++) {
            repe[modi[mat[i]][j]].push_back(i);
        }
    }
    for(i = 2; i <= 100000; i++) {
        if(repe[i].size()) {
            narendra[i].resize(4*(repe[i].size()));
            segmentTree(i, 0, 0, repe[i].size()-1);
        }
    }
    vector <int>::iterator si, ei;
    for(i = 0; i < m; i++) 
    {
        hello =-1;
        fastRead_int(ans);
        fastRead_int(x);
        fastRead_int(y);
        x=x-1;
        y=y-1;
        if(y < x) swap(x, y);
        world = hello;
        for(j = 0; j < modi[ans].size(); j++) 
        {
            if(repe[modi[ans][j]].size()) 
            {
                temp1 = modi[ans][j];
                si = lower_bound(repe[modi[ans][j]].begin(), repe[modi[ans][j]].end(), x);
                ei = upper_bound(repe[modi[ans][j]].begin(), repe[modi[ans][j]].end(), y);
                if(ei == repe[temp1].begin()) continue;
                ei--;

                if(si == repe[temp1].end()) continue;
                lefty = si - repe[temp1].begin();
                righty = ei - repe[temp1].begin();
                if(lefty > righty) continue;
                aa = query(modi[ans][j], 0, 0, repe[modi[ans][j]].size()-1, lefty, righty);
                if(aa.temp > hello) {
                    hello = aa.temp;
                    world = aa.cnt;
                }           
            }
        }
        printf("%d %d\n", hello, world);
    }
    return 0;
}




