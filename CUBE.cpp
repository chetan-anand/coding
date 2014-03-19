#include <bits/stdc++.h>
using namespace std;

//typedef long long int lli;

inline void fastRead_int(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    int neg = 0;

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


inline void fastRead_string(char *str)
{
    register char c = 0;
    register int i = 0;

    while (c < 33)
        c = getchar_unlocked();

    while (c != '\n') {
        str[i] = c;
        c = getchar_unlocked();
        i = i + 1;
    }
 
    str[i] = '\0';
}



int mc[42][42][42];
int smc[42][42][42];
int n;
int sz[42][42][42];

inline void preprocess()
{
	int i,j,k;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				smc[i][j][k]=smc[i][j][k-1]+smc[i][j-1][k]-smc[i][j-1][k-1];
				smc[i][j][k]=smc[i][j][k]+mc[i][j][k];
				//printf("smc[%d][%d][%d]=%d\n",i,j,k,smc[i][j][k]);
			}
		}
		//smc[i][j][k]=smc[i][j][k]+smc[i-1][j][k];
	}

}


int solve(int size,int pure)
{
	int i,j,k,a,b;
	int cnt=0;

	//printf("pure=%d n=%d size=%d\n",pure,n,size );

	for(j=0;j<=n-size;j++)
	{
		for(k=0;k<=n-size;k++)
		{
			for(i=0;i<n;i++)
			{
				b=smc[i][j+size-1][k+size-1]-smc[i][j+size-1][k-1]-smc[i][j-1][k+size-1];
				//printf("b1[%d][%d][%d]=%d\n",i,j,k,b);
				b=b+smc[i][j-1][k-1];
				//printf("b2[%d][%d][%d]=%d\n",i,j,k,b);
				sz[i][j][k]=b+sz[i-1][j][k];
				//printf("fuck=%d\n",sz[i][j][k]);
			}
		}
	}


	for(j=0;j<=n-size;j++)
	{
		for(k=0;k<=n-size;k++)
		{
			
			for(i=0;i<=n-size;i++)
			{
				a=0;
				/*for(int l=i;l<i+size;l++)
				{
					b=smc[l][j+size-1][k+size-1]-smc[l][j+size-1][k-1]-smc[l][j-1][k+size-1];
					b=b+smc[l][j-1][k-1];
					//cout<<"b="<<b<<endl;
					a=a+b;
				}*/
				a=sz[i+size-1][j][k]-sz[i-1][j][k];
				//printf("a=%d\n",a);
				if(a*100>=pure){cnt++;}
				//printf("smc[%d][%d][%d]=%d\n",i,j,k,smc[i][j][k]);
			}
			
		}
	}

	return cnt;
}


inline int f(int i,int j,int k)
{
	return i*n*n+j*n+k;
}


int main(int argc, char const *argv[])
{
	int t,i,j,k,p;
	char s1[68000],s2[68000];
	//string s1,s2;
	//cin>>t;
	fastRead_int(t);
	while(t--)
	{

		fastRead_int(n);
		fastRead_int(p);

		/*s1.clear();
		s2.clear();
		cin>>s1>>s2;*/
		fastRead_string(s1);
		fastRead_string(s2);

		memset(smc,0,sizeof(smc));
		memset(mc,0,sizeof(mc));
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				for(k=0;k<n;k++)
				{
					if(s1[f(i,j,k)]==s2[f(i,j,k)])
					{
						mc[i][j][k]=1;
					}
					else{mc[i][j][k]=0;}
					/*cout<<s1[f(i,j,k)]<<endl;
					cout<<s2[f(i,j,k)]<<endl;*/
					//printf("mc[%d][%d][%d]=%d\n",i,j,k,mc[i][j][k]);
				}
			}
		}

		//cout<<"\n"<<endl;

		/*for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				for(k=0;k<n;k++)
				{
					printf("mc[%d][%d][%d]=%d\n",i,j,k,mc[i][j][k]);
				}
			}
		}*/
		//cout<<"\n"<<endl;

		preprocess();
		int ans=0;
		int cnt=0;
		for(i=n;i>=1;i--)
		{
			int pure=i*i*i*p;
			//int pure=i*i*i*p;
			//printf("pure of %d=%d\n",i,pure);
			memset(sz,0,sizeof(sz));
			ans=solve(i,pure);
			if(ans)
			{
				printf("%d %d\n",i,ans);
				break;
			}
		}

		if (!ans)
		{
			printf("-1\n");
		}
	}
	return 0;
}