#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	
	while(n--)
	{
		char s[102];
		scanf("%s",s);
		if(strlen(s)>10)
		{
			printf("%c%d%c\n",s[0],strlen(s)-2,s[strlen(s)-1]);
		}
		else
		{
			printf("%s\n",s);
		}
	}
	return 0;
}