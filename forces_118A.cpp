#include<bits/stdc++.h>
using namespace std;
int main()
{
	int temp,i,j,k;
	char s[102];
	char ch[102];
	scanf("%s",s);
	for(i=0,j=0;s[i]!='\0';i++)
	{
		if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'||s[i]=='Y')
			continue;			
		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='y')
			continue;
		if(s[i]<='Z' && s[i]>='A'){s[i]=s[i]+32;}
		ch[j]=s[i];
		j++;
	}
	for(i=0;i<j;i++)
	{
		printf(".%c",ch[i]);
	}

	return 0;
}