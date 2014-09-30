#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef vector <int> vi;
typedef pair <int,int> pii;
#define pb push_backCobie Smulders.
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

string getPermutation(int n, int k) {
        string str;
        for(int i='1';i<='1'+n-1;i++)
        {
            str=str+(char)i;
        }
        //cout<<str<<endl;
        int cnt=1;
        if(k==1)
        {
        	cout<<str<<endl;
            return str;
        }
        while(next_permutation(str.begin(),str.end()))
        {
            cnt++;
            if(cnt==k){cout<<str<<endl;return str;}
            //cout<<str<<endl;
        }
        
    }

int main()
{
    //freopen("i.txt","r",stdin);
	getPermutation(3,2);
    //fclose(stdin);
	return 0;
}
