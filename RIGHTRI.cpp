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
    int cnt=0;
    cin>>t;
    while(t--)
    {
        int x1,x2,x3,y1,y2,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        int dp1=(x1-x2)*(x1-x3)+(y1-y2)*(y1-y3);
        int dp2=(x3-x2)*(x3-x1)+(y3-y1)*(y3-y2);
        int dp3=(x2-x1)*(x2-x3)+(y2-y1)*(y2-y3);
        if(dp1==0||dp2==0||dp3==0){cnt++;}
    }
    cout<<cnt<<endl;
    //fclose(stdin);
	return 0;
}


