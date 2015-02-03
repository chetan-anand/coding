#include<bits/stdc++.h>
using namespace std;
void gen(vector<char> s,int n,string ans)
{
	//cout<<ans<<endl;
	if(ans.size()==n)
	{
		cout<<ans<<endl;
		return;
	}
	for(int i=0;i<s.size();i++)
	{
		string temp=ans;
		temp=temp+s[i];
		//cout<<ans<<endl;
		//getchar();
		gen(s,n,temp);
	}
}
int main()
{
	int n,t,i,j,k,m;
	cout<<"Enter the lenght of string generated"<<endl;
	cin>>n;
	cout<<"Enter the size of alphabet"<<endl;
	cin>>m;
	vector<char> s;
	for(int i=0;i<m;i++)
	{
		char ch;
		cin>>ch;
		s.push_back(ch);
	}
	string ans;
	//cout<<n<<" "<<m<<" ";

	gen(s,n,ans);
	return 0;
}