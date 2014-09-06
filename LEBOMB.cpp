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
    int t,i,j,k,n;
    string s,temp;
    cin>>t;
    while(t--)
    {
        int len;
        cin>>len;
        cin>>s;
        temp=s;
        rep(i,len)
        {
            if(i==0 && s[i]=='1'){temp[i+1]='1';}
            else if(i==len-1 && s[i]=='1'){temp[i-1]='1';}
            else
            {
                if(s[i]=='1'){temp[i-1]='1';temp[i+1]='1';}
            }
        }
        int cnt=0;
        //cout<<temp<<endl;
        rep(i,len)
        {
            if(temp[i]=='0'){cnt++;}
        }
        cout<<cnt<<endl;
    }
    //fclose(stdin);
	return 0;
}


