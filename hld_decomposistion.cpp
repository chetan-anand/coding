#include <bits/stdc++.h>
using namespace std;

#define root 0
#define N 10100		//n=number of nodes
#define LN 14		//LN= log of n

vector <int> adj[N],cost[N],indexx[N];
int baseArray[N],ptr;
int chainNo, chainInd[N], chainHead[N], posInBase[N];
/*
	chainInd = chain index 	
	chainHead= chain Head    chain no. -> chain head
	posInBase= position of node in its chain
	chainNo=
*/

int depth[N], pa[LN][N], otherEnd[N], subsize[N];
int st[N*6], qt[N*6];

/*
 * make_tree:
 * Used to construct the segment tree. It uses the baseArray for construction
 */

void make_tree(int cur,int s,int e)
{
	if(s==e-1)
	{
		st[cur]=baseArray[s];
		return;
	}
	int c1=(cur<<1),c2=c1 | 1, m=(s+e)>>1;
	make_tree(c1, s, m);
	make_tree(c2, m, e);
	st[cur]=st[c1]>st[c2]?st[c1]:st[c2];
}
/*
* update_tree:
* Poingt update. Update a single element of the segment tree
*/

void update_tree(int cur, int s,int e,int val)
{
	if(s>x||e<=x){return;}
	if(s==x && s==e-1)
	{
		st[cur]=val;
		return;
	}
	int c1=(cur<<1), c2=c1 | 1,m=(s+e)>>1;
	update_tree(c1,s,m,x,val);

}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ptr=0;
		int n;
		scanf("%d",&n);
		// cleaning step, new test case
		for(int i=0;i<n;i++)
		{
			adj[i].clear();
			cost[i]
		}
	}
	return 0;
}