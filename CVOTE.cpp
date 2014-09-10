
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef vector <int> vi;
typedef pair <int,int> pii;

#define pb push_back
#define mp make_pair
#define gi(n) scanf("%d",&n)
#define gl(n) scanf("%lld",&n)
#define gs(n) scanf("%s",n);
#define pi(n) printf("%d\n",n)
#define pl(n) printf("%lld\n",n)
#define ps(n) printf("%s\n",n);
#define rep(i,n) for(int i=0;i<n;i++)
#define fi(i,a,n) for(int i=a;i<=n;i++)
#define fd(i,n,a) for(int i=n;i>=a;i--)
#define input(f) freopen("f.txt","r",stdin)

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

int main()
{
    //freopen("i.txt","r",stdin);
    map<string,int> chef;
    map<string,int> dp;
    map<string,int> cnt;
    string che[110000],cou[110000];
    int i,j,k,n,m;
    string ch;
    //cin>>n>>m;
    fastRead_int(n);
    fastRead_int(m);
    rep(i,n)
    {
        string s1,s2;
        cin>>s1>>s2;
        chef[s1]=i;
        che[i]=s1;
        cou[i]=s2;
    }
    rep(i,n)
    {
        dp[cou[i]]=0;
        cnt[che[i]]=0;
    }
    rep(i,m)
    {
        string q;
        cin>>q;
        cnt[q]++;
        dp[cou[chef[q]]]++;
    }


    std::map<string,int>::iterator it;
//    for(it=cnt.begin();it!=cnt.end();it++)
//    {
//        cout<<it->first<<"="<<it->second<<endl;
//    }
//
//    for(it=dp.begin();it!=dp.end();it++)
//    {
//        cout<<it->first<<"="<<it->second<<endl;
//    }

    string temp;
    int maxv;
    for(it=dp.begin();it!=dp.end();it++)
    {

        if(it==dp.begin()){maxv=it->second;temp=it->first;continue;}
        if(it->second>maxv){maxv=it->second;temp=it->first;}
    }

    cout<<temp<<endl;
    int idx;
    for(it=cnt.begin();it!=cnt.end();it++)
    {
        if(it==cnt.begin()){maxv=it->second;temp=it->first;continue;}
        if(it->second>maxv){maxv=it->second;temp=it->first;}
    }

    cout<<temp<<endl;

    //fclose(stdin);
	return 0;
}

