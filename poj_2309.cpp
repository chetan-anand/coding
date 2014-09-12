#include "stdio.h"
#include "string.h"
#include "math.h"

int wei[33];
int n;
int ch1[33],ch2[33];

void doit(int n)
{
	int i,j;
	memset(wei,0,sizeof(wei));
	while(n!=0)
	{
		wei[0]++;
		wei[wei[0]]=n%2;
		n/=2;
	}
	for (i=0;i<=32;i++) ch1[i]=ch2[i]=wei[i];
//	for (i=wei[0];i>=1;i--) printf("%d",wei[i]);
//	printf("\n");
}

void change1() //get min
{
	int i,j,site;
	if (ch1[1]!=1)
	{
		site=1;
		while (ch1[site]==0) site++;
		ch1[site]=0;
		ch1[1]=1;
	}
}

void change2()  //get max
{
	int i,j,site;
	if (ch2[1]!=1)
	{
		site=1;
		while(ch2[site]==0) site++;
		for (i=1;i<site;i++) ch2[i]=1;
	}
}

int count( int *tq)
{
	int i,j;
	int tot=0;
	for (i=tq[0];i>1;i--)
	{
		tot+=tq[i];
		tot*=2;
	}
	tot+=tq[1];
	return tot;	
}

main()
{
	int icase,ncase;
	scanf("%d",&ncase);
	for (icase=1;icase<=ncase;icase++)
	{
		scanf("%d",&n);
		doit(n);
		change1();
		change2();
		printf("%d %d\n",count(ch1),count(ch2));
	}


	return 0;
}