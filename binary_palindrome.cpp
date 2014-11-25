#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int> bin;
	int temp=n;
	int cnt=0;
	while(temp)
	{
		bin.push_back(temp%2);
		if(temp%2==1){cnt++;}
		temp=temp/2;
	}
	vector<int> rev(bin.begin(),bin.end());
	//rev.assign(bin.begin(),bin.end());
	reverse(rev.begin(),rev.end());
	bool flag=false;
	for(int i=0;i<bin.size();i++)
	{
		if(bin[i]!=rev[i])
		{
			flag=true;
			break;
		}
	}
	if(flag)
	{
		cout<<"Not palindrome"<<endl;
	}
	else
	{
		cout<<"Palindrome "<<cnt<<endl;
	}
	return 0;
}