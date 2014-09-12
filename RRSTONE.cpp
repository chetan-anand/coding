#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
	int n,i,j,k;
	cin>>n>>k;
	int a[100010],min,max;
	int tmp[100010];
	//memset(a,0,sizeof(a));
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		if(i==0){min=max=a[i];}
		if(a[i]<min){min=a[i];}
		if(a[i]>max){max=a[i];}
	}

	if(k==0)
	{
		for(i=0;i<n;i++)
		{
			printf("%d ",a[i]);
		}
		return 0;
	}

	for(i=0;i<n;i++){a[i]=max-a[i];}


	if(k%2!=0)
	{
		for(i=0;i<n;i++)
		{
			printf("%d ",a[i]);
		}
	}
	else
	{
		for (i = 0; i < n; ++i)
		{
			/* code */
			printf("%d ",max-min-a[i]);
		}
	}
	printf("\n");
	return 0;
}