#include<bits/stdc++.h>
#include <cstdio>
#include <cstring>
using namespace std;

//////////////////////// fast i/o ////////////
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

///////////////////////    Suffix automation ////////////////////////////////

const int MAXLEN = 250052;
const int K = 26;

struct state {
	int length, link, next[K];
} st[MAXLEN*2-1];

int sz, last;
char A[MAXLEN], B[MAXLEN];

void init() {
	st[0].link = -1;
	memset(st[0].next, -1, sizeof st[0].next);
	sz++;
}

void extend(char c) {
	int nlast = sz++, p, q, clone;
	st[nlast].length = st[last].length + 1;
	memset(st[nlast].next, -1, sizeof st[nlast].next);
	for(p=last; p!=-1 && st[p].next[c]==-1; p=st[p].link) st[p].next[c] = nlast;
	if(p == -1) st[nlast].link = 0;
	else{
		q = st[p].next[c];
		if(st[p].length + 1 == st[q].length) st[nlast].link = q;
		else{
			clone = sz++;
			st[clone].length = st[p].length + 1;
			memcpy(st[clone].next, st[q].next, sizeof st[clone].next);
			st[clone].link = st[q].link;
			for(; p!=-1 && st[p].next[c]==q; p=st[p].link) st[p].next[c] = clone;
			st[q].link = st[nlast].link = clone;
		}
	}
	last = nlast;
}
int pos;
int lcs(char *a, char *b) {
	
	int i, p, l, best, bestpos;
	init();
	for(i=0; a[i]; i++) extend (a[i]-'a');
	p = 0, l = 0, best = 0, bestpos = 0;
	for(i=0; b[i]; i++) {
		if(st[p].next[b[i]-'a'] == -1) {
			for(; p!=-1 && st[p].next[b[i]-'a'] == -1; p=st[p].link);
			if (p == -1) {
				p = l = 0;
				continue;
			}
			l = st[p].length;
		}
		p = st[p].next[b[i]-'a']; l++;
		if(l >best) best = l, bestpos = i;
	}
	pos=bestpos;
	return best;
}

int main() {
	gets(A);gets(B);
	int temp,i;
	temp=lcs(A,B);
	if(temp==0){printf("0\n");}
	else
	{
		for (i = pos-temp+1; i <=pos; ++i)
		{
			/* code */
			//printf("jkzxmc\n");
			printf("%c",B[i]);
		}
		printf("\n%d\n",temp);
	}
	return 0;
}
