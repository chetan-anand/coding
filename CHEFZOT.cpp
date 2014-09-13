#include <bits/stdc++.h>
using namespace std;


int main()
{
	int n,a;
	cin>>n;
	int temp=0,cnt=0;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		if(a==0){temp=max(temp,cnt);cnt=0;}
		else{cnt++;}
	}
	cout<<max(cnt,temp)<<endl;
	return 0;
}