#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <map>
using namespace std;
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		long long n,k;
		scanf("%lld %lld",&n,&k);
		map<long long,vector<pair<long long,long long> > > arr;
		long long s,f,p;
		for(int i=0;i<n;i++){
			scanf("%lld %lld %lld",&s,&f,&p);
			arr[p-1].push_back(make_pair(f,s));
		}
		long long res = 0;
		for(map<long long,vector<pair<long long,long long> > >::iterator it=arr.begin(); it!=arr.end(); it++){
			long long l = it->second.size();
			if(l==0) continue;
			long long current = 0;
			sort(it->second.begin(), it->second.end());
			for(long long j=0;j<l;j++){
				if(it->second[j].second<current) continue;
				else{
					res+=1;
					current=it->second[j].first;
				}
			}
		}
		printf("%lld\n",res);
	}
	return 0;
}