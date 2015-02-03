#include<bits/stdc++.h>
using namespace std;
 int main()
 {
 	string str1,str2;
 	getline(cin,str1);
 	bool flag=false;
 	int lidx=str1.size();
 	for(int i=0;i<str1.size();i++)
 	{
 		if(flag)
 		{
 			str2=str2+str1[i];
 		}
 		if(str1[i]=='|')
 		{
 			flag=true;
 			lidx=i;
 			i++;
 		}
 		
 	}
 	str1=str1.substr(0,lidx-1);
 	/*cin>>str1;
 	cin>>str2;*/

 	cout<<str1<<endl;
 	cout<<str2<<endl;

 	int freq1[110000],freq2[110000];
 	memset(freq1,0,sizeof(freq1));
 	memset(freq2,0,sizeof(freq2));
 	for(int i=0;i<str1.size();i++)
 	{
 		freq1[str1[i]]=1;
 	}
 	for(int i=0;i<str2.size();i++)
 	{
 		freq2[str2[i]]=1;
 	}
 	flag=false;
 	for(int i=0;i<str1.size();i++)
 	{
 		if(freq1[str1[i]]!=freq2[str1[i]])
 		{
 			flag=true;
 			break;
 		}
 	}
 	
 	if(flag)
 	{
 		cout<<"Not Equal"<<endl;
 	}
 	else
 	{
 		cout<<"Equal"<<endl;
 	}
 	return 0;
 }