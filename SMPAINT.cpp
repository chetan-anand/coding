#include <bits/stdc++.h>
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

int orig[1100][1100];
int main(int argc, char const *argv[])
{
	/* code */
	int t,i,j,k,u,d,l,r,c,cnt;
	//cin>>c;
	fastRead_int(c);
	cnt=0;
	for(i=0;i<c;i++)
	{
		for(j=0;j<c;j++)
		{
			//cin>>orig[i][j];
			fastRead_int(orig[i][j]);
			if(orig[i][j]>0){cnt++;}
		}
	}

	//cout<<cnt<<endl;
	printf("%d\n",cnt);
	cnt=1;
	for(i=0;i<c;i++)
	{
		for(j=0;j<c;j++)
		{
			if(orig[i][j])
			{
				printf("%d %d %d %d %d\n",orig[i][j],i+1,i+1,j+1,j+1);
				cnt++;
			}
		}
	}

	return 0;
}