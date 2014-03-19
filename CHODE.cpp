#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
using namespace std;


//ios_base::sync_with_stdio(false);

int main()
{
	int t,i,j,k,cnt[300],nod;
	char fs[30],map[300];
	char cf[300000];
	scanf("%d",&t);
	for(int tc=0;tc<t;tc++)
	{
		memset(cnt,0,sizeof(cnt));
		if(tc==0){getchar();}
		cin.getline(fs,sizeof(fs));
		cin.getline(cf,sizeof(cf));
		/*cout<<fs<<endl;
		cout<<cf<<endl;*/

		for(i=0;cf[i]!='\0';i++)
			if((cf[i]>='A' && cf[i]<='Z')||(cf[i]>='a' && cf[i]<='z'))
				if(cf[i]>='A' && cf[i]<='Z')
					cnt[cf[i]+32]++;
				else
					cnt[cf[i]]++;

		nod=0;
		for (i = 97; i<=122; ++i)
		{
			if(cnt[i]>0){nod++;}
			//printf("%c=%d\n",i,cnt[i]);
		}
		//cout<<"nod="<<nod<<endl;
		int min;
		char minch;
		for(j=0;j<nod;j++)
		{	
			min=INT_MAX;
			//cout<<"jkjan"<<endl;
			for(i=97;i<=122;i++)
			{
				if(cnt[i]>0)
				{
					if(cnt[i]<min){min=cnt[i];minch=i;}
				}
			}
			//cout<<"minch="<<minch<<endl;
			cnt[minch]=0;
			map[minch]=fs[26-nod+j];
		}


		/*for (i = 97; i<=122; ++i)
		{
			//if(cnt[i]>0){nod++;}
			printf("%c=%c\n",i,map[i]);
		}*/
		for(i=0;cf[i]!='\0';i++)
		{
			int temp=0;
			if(cf[i]>='A' && cf[i]<='Z')
			{
				cf[i]=cf[i]+32;temp=-32;
			}
			if(cf[i]>='a'&& cf[i]<='z')
			{
				printf("%d\n",100);
				printf("%c",map[cf[i]]+temp);
			}
			else
			{
				printf("%c",cf[i]);
			}
		}
		printf("\n");

	}
	return 0;
}