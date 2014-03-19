
//////////   Interval Schedulling algorithn  //////////////////

#include <bits/stdc++.h>
using namespace std;

inline void fastRead_int(long long int &x) {
    register long long int c = getchar_unlocked();
    x = 0;
    long long int neg = 0;

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


map<long long,vector<pair<long long,long long> > >::iterator it;

int main() 
{
	long long int t,n,k,s,f,p,temp,l,curr,i,j;
	//scanf("%lld",&t);
	fastRead_int(t);
	while(t--)
	{

		//scanf("%lld %lld",&n,&k);
		fastRead_int(n);
		fastRead_int(k);

		map<long long,vector<pair<long long,long long> > > sc;
		for(i=0;i<n;i++)
		{
			//scanf("%lld %lld %lld",&s,&f,&p);
			fastRead_int(s);
			fastRead_int(f);
			fastRead_int(p);
			sc[p-1].push_back(make_pair(f,s));
		}


		temp = 0;


		for(it=sc.begin(); it!=sc.end(); it++)
		{
			l = it->second.size();
			if(l==0)
			{
				continue;
			}

			curr = 0;
			sort(it->second.begin(), it->second.end());
			for(j=0;j<l;j++)
			{
				if(it->second[j].second<curr)
				{
					continue;
				}
				else
				{
					temp+=1;
					curr=it->second[j].first;
				}
			}
		}
		printf("%lld\n",temp);

	}
	return 0;
}