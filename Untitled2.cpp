#include<bits/stdc++.h>
using namespace std;
#define maxn 200000 + 5

int f[maxn], t[maxn], p[maxn], ii, kdepth[maxn], Tn, i, n, x, y, l, r, mid, eaten;
bool over;

void addedge (int x, int y) {
	t[++ii] = y;
	p[ii] = f[x];
	f[x] = ii;
}

void dfs (int k, int pr, int depth) {
	++kdepth[depth];
	int q = f[k];
	while(q > 0) {
		if (t[q] != pr) dfs(t[q], k, depth + 1);
		q = p[q];
	}
}

int main (int argc, char * const argv[]) {
//	freopen("input.txt", "r", stdin);
    clock_t start = clock();
	scanf("%d", &Tn);
	while (Tn--) {
		ii = 0;
		for(i = 1; i <= n; i++) f[i] = 0;
		scanf("%d", &n);
		for(i = 1; i < n; i++) {
			scanf("%d %d", &x, &y);
			addedge(x, y);
			addedge(y, x);
		}
		for(i = 1; i <= n; i++) kdepth[i] = 0;
		dfs(1, -1, 1);
		l = 1, r = n;
		while (l < r) {
			mid = (l + r + 1) / 2;
			eaten = 0;
			for(i = 1; i <= (mid + 1) / 2; i++) eaten += kdepth[i];
			if (n - eaten >= mid - (mid + 1) / 2) over = false; else over = true;
			if (over) r = mid - 1; else l = mid;
		}
		int remain = n;
		for(i = 1; i <= (l + 1) / 2; i++) remain -= kdepth[i];
		remain -= l - (l + 1) / 2;
		if (remain) ++l;
		printf("%d\n", l);
	}
	 while (clock() - start < (1.0 - 0.02) * CLOCKS_PER_SEC);
    return 0;
}

