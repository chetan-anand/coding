#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

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


int cnt[310][310][12];
void preprocess(int a[310][310],int n)
{
	int i,j,k;
	memset(cnt,0,sizeof(cnt));
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
			{
				cnt[i][j][a[i][j]]++;
				
			}
				
			
	for(k=1;k<=10;k++)
		for(i=1;i<=n;i++)
			for(j=2;j<=n;j++)
			{
				cnt[i][j][k]=cnt[i][j-1][k]+cnt[i][j][k];
			}


}

int main(int argc, char const *argv[])
{
	int n,i,j,k,x1,x2,y1,y2;
	int a[310][310];
	fastRead_int(n);

	for(i=1;i<=n;i++)
	{
		for(j=01;j<=n;j++)
		{
			fastRead_int(a[i][j]);
		}
	}

	preprocess(a,n);
	int q;
	
	fastRead_int(q);
	int temp;
	while(q--)
	{
		fastRead_int(x1);
		fastRead_int(y1);
		fastRead_int(x2);
		fastRead_int(y2);
		temp=0;
		for(i=1;i<=10;i++)
			for(j=x1;j<=x2;j++)
			{
				if(cnt[j][y2][i]-cnt[j][y1-1][i]>0){temp++;break;}
			}
		printf("%d\n",temp);
	}
	return 0;
}