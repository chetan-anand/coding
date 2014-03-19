#include<stdio.h>
#include<vector>
using namespace std;
long exclude[50][50];
long dp[50];
vector<long>offer[20005];
int main()
{
		long i,j,k[50],w,f,n,m,x,max,count;
		
		scanf("%ld%ld",&n,&m);
		for(i=1;i<=m;i++)//order no.
		{
			scanf("%ld",&k[i]);
			for(j=1;j<=k[i];j++)
			{
				scanf("%ld",&x);//offer[index of stamp][offer index]
				//offer[20000][20]
				offer[x].push_back(i);//push order no.
			}
		}
		
		for(i=1;i<=n;i++)//ticket no.
		{
			
			
				long l=offer[i].size();
				for(j=0;j<l;j++){
					for(w=j+1;w<l;w++)
					{	
						exclude[offer[i][j]][offer[i][w]]=1;
						exclude[offer[i][w]][offer[i][j]]=1;
						
					}}
			
			
		}
		/*//printf("\n");
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=m;j++)printf("%ld ",exclude[i][j]);
			printf("\n");
		}printf("\n");*/
		max=0;
		for(i=1;i<=m;i++)
		{
			
			
			
				count=1;
				for(j=1;j<i;j++)
				{
							
							if(exclude[i][j]==0)
							{
								count++;
							}
						
					
				}
				
				if(max<count)max=count;
	
			
		}
		printf("%ld\n",max);
}