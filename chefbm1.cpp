#include<bits/stdc++.h>
using namespace std;
inline void fastRead_long(long long &x) {
    register long long c = getchar_unlocked();
    x = 0;
    long long neg = 0;

    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

    if(c=='-') {
        neg = 1;
        c = getchar_unlocked();
    }

    for(; c>47 && c<58 ; c = getchar_unlocked()) {
        x = (x<<1) + (x<<3) + c - 48;
    }

    if(neg)
        x = -x;
}
int main()
{
	long long int n,m,i,j,k,p;
	//cin>>m>>n>>p;  m=no of rows  n= number of cols
	fastRead_long(m);
	fastRead_long(n);
	fastRead_long(p);
	long long int x,y;
	long long int temp[110000];
	pair<long long int,long long int> foo[110000];
	bool hashrow[110000];
	memset(hashrow,0,sizeof(hashrow));
	vector<long long int>adj[110000];
	for(i=0;i<p;i++)
	{
		//cin>>x>>y;
		fastRead_long(x);
		fastRead_long(y);
		foo[i]=make_pair(x,y);
		hashrow[x]=true;
		adj[x].push_back(y);
	}

	sort(foo,foo+p);
	// for(i=0;i<p;i++)
	// {
	// 	cout<<foo[i].first<<" "<<foo[i].second;
	// 	cout<<endl;
	// }

	for(i=1;i<=m;i++)
	{
		if(!(hashrow[i]))
			printf("%lld\n", n-1);
		else
		{
			memset(temp,0,sizeof(temp));
			for(j=1;j<=n;j++)
			{
				temp[j]=j;
			}
			for(j=0;j<adj[i].size();j++)
			{
				temp[adj[i][j]]++;
			}
			// // long long int maxidx,minidx;
			// printf("----------------\n");
			// for(j=1;j<=n;j++)
			// {
			// 	printf("%d ", temp[j]);
			// 	cout<<endl;
			// }
			// printf("----------------\n");
	
			// /*for (j=1; j <= n; ++j)
			// {
				
			// 	if(j==1){maxidx=1;minidx=1;continue;}
			// 	if(temp[j]<temp[minidx]){minidx=j;}
			// 	if(temp[j]>temp[maxidx]){maxidx=j;}
			// }*/

			bool flag=true;
			long long int ans;
			ans=0;
			for(j=1;j<n;j++)
			{
				if(temp[j+1]-temp[j]<0){flag=false;break;}
				ans=ans+temp[j+1]-temp[j];
			}

			if(flag)
			{
				printf("%lld\n",ans);
			}
			else
			{
				printf("-1\n");
			}
		}
	}
	return 0;
}
