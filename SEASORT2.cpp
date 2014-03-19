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



int main() {
	int n, cnt = 0, i, j, start, end, temp;
	int mat[10004], mat1[10004], tempu[10004][2];

	fastRead_int(n);
	
	for(i=0; i<n; i++) 
	{
		//scanf("%d", &a[i]);
		fastRead_int(mat[i]);
		mat1[i] = mat[i];
	}
	sort(mat1, mat1+n);
	
	for(i=0; i<n; i++) {
		if(mat[i] == mat1[i])
			continue;
		
		for(j=i+1; j<n; j++) {
			
			if(mat[j] == mat1[i]) {
				tempu[cnt][0] = i + 1;
				tempu[cnt][1] = j + 1;
				cnt++;
				
				start = i;
				end = j;
				while(start < end) {
					temp = mat[start];
					mat[start] = mat[end];
					mat[end] = temp;
					start++;
					end--;
				}
				
				break;
			}
		}
	}
	
	printf("%d\n", cnt);
	for(i=0; i<cnt; i++)
		printf("%d %d\n", tempu[i][0], tempu[i][1]);
	return 0;
}