#include<bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	string s1,s2;
	cin>>s1;
	int i=0;
	cin>>s2;
	for(int i=0; s1[i]; i++)
	{
		if(s1[i]==',')
			s1[i]=' ';
		if(s1[i]==':')
			s1[i]=' ';
		if(s1[i]=='"')
			s1[i]=' ';
		if(s1[i]=='}')
			s1[i]=' ';
		if(s1[i]=='{')
			s1[i]=' ';
	}
	for(int i=0; s2[i]; i++)
	{
		if(s2[i]==',')
			s2[i]=' ';
		if(s2[i]==':')
			s2[i]=' ';
		if(s2[i]=='"')
			s2[i]=' ';
		if(s2[i]=='}')
			s2[i]=' ';
		if(s2[i]=='{')
			s2[i]=' ';
		if(s2[i]=='[')
			s2[i]=' ';
		if(s2[i]==']')
			s2[i]=' ';
		if(s2[i]=='\'')
			s2[i]=' ';
	}
	// cout<<s1<<endl<<s2<<endl;
	queue<string>S;
	string x;
	int n=s1.size();
	for(int i=0; i<n; i++)
	{	
		if(s1[i]!=' ')
		{
			string x="\0";
			while(i<n&&s1[i]!=' ')
			{
				x+=s1[i];
				i++;
			}
			if(x.size()>0)
			{
				S.push(x);
			}
		}
	}
	queue<string>q;
 	int n1=s2.size();
	for(int i=0; i<n1; i++)
	{
		if(s2[i]!=' ')
		{
			string x="\0";
			while(i<n1&&s2[i]!=' ')
			{
				x+=s2[i];
				i++;
			}
			if(x.size()>0)
			{
				q.push(x);
			}
		}
	}
	string r="\0";
	while(!S.empty()&&!q.empty())
	{
		if((S.size()>1)&&(q.size()>1))
		{
			string top1=S.front();
			string top2=q.front();
			S.pop();
			q.pop();
// cout<<top1<<" "<<top2<<endl;
			if(S.front()!=q.front())
{
if(r=="\0")
r=r+top1;
else
r+=":"+top1;
}
S.pop();
q.pop();
}
}
cout<<r<<endl;
}