#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	cin>>str;
	int len=str.size();
	sort(str.begin(),str.end());
	cout<<str<<endl;
	// while(next_permutation(str.begin(),str.end()))
	// {
	// 	cout<<str<<endl;
	// }
	string::iterator it;
	for(it=str.begin();it!=str.end();it++)
	{
		cout<<*it<<endl;
	}


	return 0;
}