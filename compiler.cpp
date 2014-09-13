#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,i,j,k;
	char s[1100000];
	cin>>t;
	while(t--)
	{
		cin>>s;
		int cnt,ans;
		cnt=0;ans=0;
		stack<char> par;
		if(s[0]=='>'){printf("0\n");continue;}
		for(i=0;s[i]!='\0';i++)
		{
			if(par.size()==0 && s[i]=='>'){break;}
			if(s[i]=='<'){par.push(s[i]);continue;}
			if(s[i]=='>' && par.top()=='<')
			{
				cnt++;
				par.pop();
			}
			if(par.size()==0){ans=ans+2*cnt;cnt=0;}
		}
		printf("%d\n",ans);
	}
	

	return 0;
}