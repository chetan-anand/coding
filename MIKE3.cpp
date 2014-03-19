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
int offer[1000][1000],n,m,cnt=0;
#define pi(n) printf("%d\n",n)
#define pl(n) printf("%lld\n",n)
vector < vi > stamp(30001);
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


void func(vi& R,vi& P,vi& X);
void BronKerbosch3(vi& temp);

int main()
{
  int p,i,j,k;
  for(i=0;i<20;i++)
  {
	for(j=0;j<20;j++)
	{
	  offer[i][j]=1;
	}
  }
  fastRead_int(n);
  fastRead_int(m);
  for(i=0;i<m;i++)
  {
	fastRead_int(k);
	for(j=0;j<k;j++)
	{
	  fastRead_int(p);
	  stamp[p].push_back(i);
	  for(int l=0;l<stamp[p].size();l++)
	  {
		offer[i][stamp[p][l]]=0;
		offer[stamp[p][l]][i]=0;
	  }
	}
  }
  vector<std::pair<int,int> > V;
  for(int i=0;i<m;i++)
  {
	int ans=0;
	for(int j=0;j<m;j++)
	{
	  if(offer[i][j]==1)
	  {
		ans++;
	  }
	} 
	V.push_back(make_pair(i,ans));
  }
  int ct=m;
  vi temp;
  while(ct!=0)
  {
	int ans=25;
	int huma=-1;
	for(int i=0;i<m;i++)
	{
	  if(V[i].second<ans)
	  {
		huma=i;
		ans=V[i].second;
	  }
	}
	V[huma].second=30;
	temp.push_back(huma);
	for(int i=0;i<m;i++)
	{
	  if(offer[huma][i]==1)
	  {
		V[i].second--;
	  }
	}
	ct--;       
  }
  BronKerbosch3(temp);
  pi(cnt);
  return 0;
}

void func(vi& R,vi& P,vi& X)
{
	if(P.size()==0 && X.size()==0)     
		{
		  if(R.size()>cnt)
		  {
			cnt=R.size();
		  }  
		}
	   else{
	   int u;
	   if(P.size()!=0)
	   {
		  u=P[P.size()-1];
	   }               
	   else
	   {
		  u=X[X.size()-1];
	   }
	   for(int i=0;i<P.size();i++)
	   {
		   if(offer[P[i]][u]!=1)     
		   {
		   vi RV(R);
		   vi PN,XN;
		   RV.push_back(P[i]);
	   
			  for(int j=0;j<P.size();j++)
		   {
			  if(offer[P[i]][P[j]]==1)
			  {
				PN.push_back(P[j]);
			  }
		   }
		   for(int j=0;j<X.size();j++)
		   {
			  if(offer[P[i]][X[j]]==1)
			  {
				XN.push_back(X[j]);
			  }
		   } 
		   func(RV,PN,XN);  
			X.push_back(P[i]);  
			P.erase(P.begin()+i);    
			i--;   
		   }
	   }
	   }
}

void BronKerbosch3(vi& temp)
  {                      
	 vi P(temp.begin(),temp.end());
	   vi R,X;
		for(int i=0;i<P.size();i++)     
		 {
		   vi RV(R);
		   vi PN,XN;
		   RV.push_back(P[i]);
		   for(int j=0;j<P.size();j++)
		   {
			  if(offer[P[i]][P[j]]==1)
			  {
				PN.push_back(P[j]);
			  }
		   }
		   for(int j=0;j<X.size();j++)
		   {
			  if(offer[P[i]][X[j]]==1)
			  {
				XN.push_back(X[j]);
			  }
		   }
		   func(RV,PN,XN);    
		   X.push_back(P[i]);      
		   P.erase(P.begin()+i);    
		  }
	}