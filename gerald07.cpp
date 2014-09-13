#include<bits/stdc++.h>
using namespace std;
//////////////////////////////////////////

template<class T> struct splnode {
  typedef splnode<T> node_t;

  splnode() : P(NULL), flip(0), pp(NULL) {
    C[0] = C[1] = NULL;
    fix();
  }

  node_t* P;
  node_t* C[2];

  int flip;
  node_t* pp;

  /* Fix the parent pointers of our children.  Additionally if we have any
   * extra data we're tracking (e.g. sum of subtree elements) now is the time to
   * update them (all of the children will already be up to date). */
  void fix() {
    if(C[0]) C[0]->P = this;
    if(C[1]) C[1]->P = this;
  }

  /* Push the flip bit down the tree. */
  void push_flip() {
    if(!flip) return;
    flip = 0;
    swap(C[0], C[1]);
    if(C[0]) C[0]->flip ^= 1;
    if(C[1]) C[1]->flip ^= 1;
  }

  /* Return the direction of this relative its parent. */
  int up() {
    return !P ? -1 : (P->C[0] == this ? 0 : 1);
  }

  /* Simple zig step in the 'c' direction when we've reached the root. */
  void zig(int c) {
    node_t* X = C[c];
    if(X->P = P) P->C[up()] = X;
    C[c] = X->C[1 - c];
    X->C[1 - c] = this;
    fix(); X->fix();
    if(P) P->fix();
    swap(pp, X->pp);
  }

  /* Zig zig in the 'c' direction both times. */
  void zigzig(int c) {
    node_t* X = C[c];
    node_t* Y = X->C[c];
    if(Y->P = P) P->C[up()] = Y;
    C[c] = X->C[1 - c];
    X->C[c] = Y->C[1 - c];
    Y->C[1 - c] = X;
    X->C[1 - c] = this;
    fix(); X->fix(); Y->fix();
    if(P) P->fix();
    swap(pp, Y->pp);
  }

  /* Zig zag first in the 'c' direction then in the '1-c' direciton. */
  void zigzag(int c) {
    node_t* X = C[c];
    node_t* Y = X->C[1 - c];
    if(Y->P = P) P->C[up()] = Y;
    C[c] = Y->C[1 - c];
    X->C[1 - c] = Y->C[c];
    Y->C[1 - c] = this;
    Y->C[c] = X;
    fix(); X->fix(); Y->fix();
    if(P) P->fix();
    swap(pp, Y->pp);
  }

  /* Splay this up to the root.  Always finishes without flip set. */
  node_t* splay() {
    for(push_flip(); P; ) {
      /* Reorganize flip bits so we can rotate as normal. */
      if(P->P) P->P->push_flip();
      P->push_flip();
      push_flip();

      int c1 = up();
      int c2 = P->up();
      if(c2 == -1) {
        P->zig(c1);
      } else if(c1 == c2) {
        P->P->zigzig(c1);
      } else {
        P->P->zigzag(c2);
      }
    }
    return this;
  }

  /* Return the max element of the subtree rooted at this. */
  node_t* last() {
    push_flip();
    return C[1] ? C[1]->last()  : splay();
  }

  /* Return the min element of the subtree rooted at this. */
  node_t* first() {
    push_flip();
    return C[0] ? C[0]->first() : splay();
  }
};


template<class T>
struct linkcut {
typedef splnode<T> node_t;

linkcut(int N) : node(N) {
}

void link(int u, int v) {
  make_root(v);
  node[v].pp = &node[u];
}

void cut(int u, int v) {
  make_root(u);
  node[v].splay();
  if(node[v].pp) {
    node[v].pp = NULL;
  } else {
    node[v].C[0]->P = NULL;
    node[v].C[0] = NULL;
    node[v].fix();
  }
}

bool connected(int u, int v) {
  node_t* nu = access(u)->first();
  node_t* nv = access(v)->first();
  return nu == nv;
}

/* Move u to root of represented tree. */
void make_root(int u) {
  access(u);
  node[u].splay();
  if(node[u].C[0]) {
    node[u].C[0]->P = NULL;
    node[u].C[0]->flip ^= 1;
    node[u].C[0]->pp = &node[u];

    node[u].C[0] = NULL;
    node[u].fix();
  }
}

/* Move u to root aux tree.  Return the root of the root aux tree. */
splnode<T>* access(int u) {
  node_t* x,* pp;
  for(x = node[u].splay(); x->pp; x = pp) {
    pp = x->pp->splay();
    x->pp = NULL;
    if(pp->C[1]) {
      pp->C[1]->P = NULL;
      pp->C[1]->pp = pp;
    }
    pp->C[1] = x;
    pp->fix();
  }
  return x;
}

vector<node_t> node;
};


#include <cstdlib>

inline int fast_read_int() {
  register char c=0;
  while(c < '0' || '9' < c) {
    c = getchar_unlocked();
  }

  int a = 0;
  while('0' <= c && c <= '9') {
    a = a * 10 + c - '0';
    c = getchar_unlocked();
  }
  return a;
}

inline char fast_read_char() {
  register char c=0;
  while(c <= ' ') {
    c = getchar_unlocked();
  }
  return c;
}


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

pii v[210000];

int main()
{	
    int n,m,i,j,k,q,x,y,N,M;
    int t;
    fastRead_int(t);
    while(t--)
    {
    	int str,end;
    	fastRead_int(n);
    	fastRead_int(m);
    	fastRead_int(q);
    	N=n;
  		M=m;
  		linkcut<int> tr(N);
    	
    	for(i=1;i<=m;i++)
    	{
    		fastRead_int(x);
    		fastRead_int(y);
    		v[i]=make_pair(x-1,y-1);
    		tr.link(x-1,y-1);
    	}
    	str=1;end=m;
    	for(i=0;i<q;i++)
    	{
    		fastRead_int(x);
    		fastRead_int(y);
    		while((x-str)!=0)
    		{
    			if(str>x)
    			{
    				tr.cut(v[str].first,v[str].second);
    				str--;
    			}
    			if(str<x)
    			{
    				str++;
    				tr.link(v[str].first,v[str].second);
    			}
    		}

    		while((y-end)!=0)
    		{
    			if(end>y)
    			{
    				tr.cut(v[end].first,v[end].second);
    				end--;
    			}
    			if(end<y)
    			{
    				end++;
    				tr.link(v[end].first,v[end].second);
    			}
    		}	
    	}
        

    }
	
	return 0;
}
