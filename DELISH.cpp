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
#define MAX 11000
int dpmaxr[MAX],dpminr[MAX];
int dpmaxl[MAX],dpminl[MAX];

long long int precompute(int *d,int n)
{
	int i,j,k;
	// max left and maxright
	int curmax=INT_MIN,maxfar=INT_MIN;
	int curmin=INT_MAX,minfar=INT_MAX;
	for(i=0;i<n;i++)
	{
		curmax=max(curmax+d[i],d[i]);
		curmin=min(curmin+d[i],d[i]);
		maxfar=max(maxfar,curmax);
		minfar=min(minfar,curmin);
		dpmaxl[i]=maxfar;
		dpminl[i]=minfar;
	}
	curmax=INT_MIN;maxfar=INT_MIN;
	curmin=INT_MAX;minfar=INT_MAX;
	for(i=n-1;i>=0;i--)
	{
		curmax=max(curmax+d[i],d[i]);
		curmin=min(curmin+d[i],d[i]);
		maxfar=max(maxfar,curmax);
		minfar=min(minfar,curmin);
		dpmaxr[i]=maxfar;
		dpminr[i]=minfar;
	}

	int max1=INT_MIN,max2=INT_MIN;
	for(i=0;i<=n-2;i++)
	{
		max1=max(max1,abs(dpminl[i]-dpmaxr[i+1]));
		max2=max(max2,abs(dpmaxl[i]-dpminr[i+1]));
	}
	return max1>max2?max1:max2;
}
int main()
{
    //freopen("i.txt","r",stdin);
	int t,i,j,k,n,d[MAX];
	cin>>t;
	while(t--)
	{
		cin>>n;
		rep(i,n)
		{
			cin>>d[i];
		}
		precompute(d);
	}
    //fclose(stdin);
	return 0;
}
