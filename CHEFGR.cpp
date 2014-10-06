#include<bits/stdc++.h>
using namespace std;
int main()
{
int t,i,j,k;
cin>>t;
while(t--)
{
	//cin>>t;
	//cout<<"t"<<t<<endl;
	int n,m;
	cin>>n>>m;
	int a[1000];
	int maxv=INT_MIN;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		maxv=max(a[i],maxv);	
	}
	//cout<<"max"<<maxv<<endl;
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		cnt+=maxv-a[i];	
	}
	//cout<<"cnt"<<cnt<<endl;
	if(m==cnt)
	cout<<"Yes"<<endl;
	else
	{
	if((m-cnt)%n==0)
	cout<<"Yes"<<endl;
	else
	cout<<"No"<<endl;
	}
	 
}
return 0;
} 