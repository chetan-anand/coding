#include<bits/stdc++.h>
using namespace std;
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
#define all(a) a.begin(),a.end()

///////////////////////////////////////

int main()
{
    //freopen("i.txt","r",stdin);
    int t,i,j,k;

    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int len=s.size();
        //cout<<len<<endl;
        len=len/2;
        int freq[200];
        memset(freq,0,sizeof(freq));
        rep(i,len)
        {
            freq[s[i]]++;
        }
        bool temp=true;
        //cout<<len<<endl;
        rep(i,len)
        {
            freq[s[s.size()-1-i]]--;
            if(freq[s[s.size()-1-i]]<0)
            {
                temp=false;
            }
        }
        if(temp){cout<<"YES"<<endl;}
        else{cout<<"NO"<<endl;}
    }
    //fclose(stdin);
	return 0;
}


