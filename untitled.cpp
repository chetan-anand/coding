#include <cstdio>
#include <vector>
#include <algorithm>
 #include<bits/stdc++.h>
using namespace std;
 
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int n;
		scanf("%d", &n);
		vector<vector<int> > p(101, vector<int>(101, 0));
		vector<pair<int, int> > sp;
		for (int j = 0; j < n; j++) {
			int x, y;
			scanf("%d %d", &x, &y);
			p[y+50][x+50]++;
			sp.push_back(make_pair(y+50, x+50));
		}
		//sort(sp.begin(), sp.end());
		for(i=0;i<sp.size();i++)
		{
			cout<<sp[i].first<<" "<<sp[i].second<<endl;
		}
		/*int ct = 0;
		for (int j = 0; j < sp.size(); j++) for (int k = j+1; k < sp.size(); k++)
			if (sp[k].second > sp[j].second) {
				int y = sp[j].first, x = sp[j].second, dy = sp[k].first-y,
						dx = sp[k].second-x;
				if (x-dy >= 0 && y+dx+dy < 101 && p[y+dx][x-dy] &&
						p[y+dx+dy][x-dy+dx])
					ct++;
			}
		printf("%d\n", ct);*/
	}
	return 0;
} 