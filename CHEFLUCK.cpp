
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
    cin>>t;
    while(t--)
    {
        cin>>n;
        int q,r;
        q=n/7;
        r=n%7;
        if(r==0)
            pi(7*q);
        else if(r==1)
        {
            if(q-1<0){pi(-1);}
            else{pi(7*(q-1));}
        }
        else if(r==2)
        {
            if(q-2<0){pi(-1);}
            else{pi(7*(q-2));}
        }
        else if(r==3)
        {
            if(q-3<0){pi(-1);}
            else{pi(7*(q-3));}
        }
        else if(r==4)
        {
            pi(7*q);
        }
        else if(r==5)
        {
            if(q-1<0){pi(-1);}
            else{pi(7*(q-1));}
        }
        else
        {
            if(q-2<0){pi(-1);}
            else{pi(7*(q-2));}
        }
    }
    //fclose(stdin);
	return 0;
}

