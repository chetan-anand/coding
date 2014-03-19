#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define fu(i,a,n) for(int i=a;i<=n;i++)
#define fd(i,n,a) for(int i=n;i>=a;i--)
#define gi(n) n = io.sc()

#define N 211111
#define M 211111
#define c1(n) (n<<1)
#define c2(n) ((n<<1)|1)

#define SS 1024*1024*8
char IN[SS],OUT[SS],*iptr,*optr,stk[20];

struct fastIO
{
	fastIO()
	{
		fread(IN,1,SS,stdin);
		iptr=IN;
		optr=OUT;
	}
	void check()
	{
		int size=IN+SS-iptr;
		if(size<200)
		{
			memcpy(IN,iptr,size);
			fread(IN+size,1,SS-size,stdin);
			iptr=IN;
		}
	}
	void check2()
	{
		int size=OUT+SS-optr;
		if(size<200)
		{
			fwrite(OUT,optr-OUT,1,stdout);
			optr=OUT;
		}
	}

	int sc()
	{
		check();
		while(*iptr<=32) iptr++;
		int x=0;
		while(*iptr>32) x= x*10 + *iptr++ -'0';
		return x;
	}

	void pr(int x)
	{
		check2();
		if(x==0)
			*optr++='0';
		else
		{
			int y;
			int top=-1;
			while(x>0)
			{
				y=x/10;
				stk[++top]=x-y*10+'0';
				x=y;
			}
			while(top>=0) *optr++=stk[top--];
		}
		*optr++='\n';
	}
};

fastIO io;

struct node {
	int distance, nodeNo;
};
node *AST[N];
int sizeST[N], addend[N], isBlack[N];

void mymax(node &a, node &b, node &c) {
	if(b.distance > c.distance || (b.distance == c.distance && b.nodeNo > c.nodeNo)) a = b;
	else a = c;
}
int x,v,nodeNo,toAdd,forceIt;
void updateST(int cur, int s, int e, node *ST) {
	if(s>x || e<=x) return;
	if(s==x && s==e-1) {
		if((!forceIt) && (ST[cur].distance > v+toAdd || (ST[cur].distance == v + toAdd && ST[cur].nodeNo > nodeNo))) return;
		ST[cur].distance = v;
		if(ST[cur].distance != -1) ST[cur].distance += toAdd;
		ST[cur].nodeNo = nodeNo;
		return;
	}
	int m = (s+e)>>1, cur2 = (cur<<1);
	if(x < m) {
		updateST(cur2, s, m, ST);
	}
	if(x >= m) {
		updateST(cur2|1, m, e, ST);
	}
	if(ST[cur2].distance > ST[cur2|1].distance) {
		ST[cur] = ST[cur2];
		return;
	}
	if(ST[cur2].distance < ST[cur2|1].distance) {
		ST[cur] = ST[cur2|1];
		return;
	}
	if(ST[cur2].nodeNo > ST[cur2|1].nodeNo) {
		ST[cur] = ST[cur2];
		return;
	}
	ST[cur] = ST[cur2|1];
}
void updateST(int cur, int s, int e, int _x, int _v, int _nodeNo, int _toAdd, bool _forceIt, node *ST) {
	x = _x;
	v = _v;
	nodeNo = _nodeNo;
	toAdd = _toAdd;
	forceIt = _forceIt;
	updateST(cur,s,e,ST);
}
node wasteNode = (node) { -1, -1 };
node QT[N*6];
int S,E;
void queryST(int cur, int s, int e, node *ST) {
	if(s>=E || e<=S) { QT[cur] = wasteNode; return; }
	if(s>=S && e<=E) { QT[cur] = ST[cur]; return; }
	int m = (s+e)>>1, cur2 = (cur<<1);
	if(E<=m) {
		queryST(cur2, s, m, ST);
		QT[cur] = QT[cur2];
		return;
	} else if(S>=m) {
		queryST(cur2|1, m, e, ST);
		QT[cur] = QT[cur2|1];
		return;
	}
	queryST(cur2, s, m, ST);
	queryST((cur2|1), m, e, ST);
	if(QT[cur2].distance > QT[cur2|1].distance) {
		QT[cur] = QT[cur2];
		return;
	}
	if(QT[cur2].distance < QT[cur2|1].distance) {
		QT[cur] = QT[cur2|1];
		return;
	}
	if(QT[cur2].nodeNo > QT[cur2|1].nodeNo) {
		QT[cur] = QT[cur2];
		return;
	}
	QT[cur] = QT[cur2|1];
}
void queryST(int cur, int s, int e, int _S, int _E, node *ST) {
	S = _S;
	E = _E;
	queryST(cur, s, e, ST);
}

int last[N], ver[N], next[N], adj_ptr;


void dis(int from,int to)
{

	printf("add_ptr=%d\n",adj_ptr );
	printf("from=%d\n",from );
	printf("to=%d\n",to);
	printf("ver_[%d]=%d\n",adj_ptr,ver[adj_ptr] );
	printf("next[%d]=%d\n",adj_ptr,next[adj_ptr] );
	printf("last[%d]=%d\n",from,last[from] );

}



//---------------------------------------------------Graph formation-----------------------------
void addEdge(int from, int to) {

	ver[adj_ptr] = to; next[adj_ptr] = last[from]; last[from] = adj_ptr++;
	dis(from,to);
	printf("-------------end---------------------\n");

}
//--------------------------------------------------------------------------------------------------



int parent[N], subTree[N], depth[N], in[N], out[N], timestamp;
int dfs(int cur) {
	subTree[cur] = 1;
	if(parent[cur] == -1) depth[cur] = 0;
	else depth[cur] = depth[parent[cur]] + 1;
	in[cur] = ++timestamp;
	for(int i = last[cur]; i; i = next[i]) subTree[cur] += dfs(ver[i]);
	out[cur] = timestamp;
	return subTree[cur];
}

int chainNo, chainInd[N], chainPos[N], chainHead[N], chainSize[N], HLchild[N];
void HLD(int cur) {
	bool HLD_debug = false;
	if(chainHead[chainNo] == -1) {
		if(HLD_debug) printf("New Chain with head %d and ind = %d\n",cur,chainNo);
		chainHead[chainNo] = cur;
		chainSize[chainNo] = 0;
	}
	if(HLD_debug) printf("%d added to chain %d\n",cur,chainNo);
	chainInd[cur] = chainNo;
	chainPos[cur] = chainSize[chainNo];
	chainSize[chainNo]++;

	int ind = -1, ma = -1;
	for(int i = last[cur]; i; i = next[i]) {
		if(subTree[ver[i]] > ma) {
			ma = subTree[ver[i]];
			ind = i;
		}
	}
	HLchild[cur] = -1;
	if(ind != -1) {
		HLchild[cur] = ver[ind];
		HLD(ver[ind]);
	}

	for(int i = last[cur]; i; i = next[i]) {
		if(i != ind) {
			chainNo++;
			chainHead[chainNo] = -1;
			HLD(ver[i]);
		}
	}
}

void specialQuery(int curNode, int avoidChild, node &bestNode, int addie) {
	if(avoidChild == -1) {
		queryST(1, 0, timestamp+1, in[curNode], out[curNode]+1, AST[chainNo+10]);
		if(QT[1].distance != -1) QT[1].distance += addie - depth[curNode];
		mymax(bestNode, QT[1], bestNode);
	} else {
		queryST(1, 0, timestamp+1, in[curNode], in[avoidChild], AST[chainNo+10]);
		if(QT[1].distance != -1) QT[1].distance += addie - depth[curNode];
		mymax(bestNode, QT[1], bestNode);
		if(out[avoidChild] < out[curNode]){
			queryST(1, 0, timestamp+1, out[avoidChild]+1, out[curNode]+1, AST[chainNo+10]);
			if(QT[1].distance != -1) QT[1].distance += addie - depth[curNode];
			mymax(bestNode, QT[1], bestNode);
		}
	}
}
void treeUpdate(int nodeNo, bool wasteIt = false) {
	bool forceFlag = wasteIt;
	int curNode = nodeNo, curDistance = 0,ind,pos;
	bool treeUpdate_debug = false;
	while(curNode != -1) {
		ind = chainInd[curNode];
		pos = chainPos[curNode];
		node temp = (node) {curDistance, nodeNo};
		if(wasteIt) temp = wasteNode;
		specialQuery(curNode, HLchild[curNode], temp, 0);
		updateST(1, 0, chainSize[ind], pos, temp.distance, temp.nodeNo, addend[curNode], forceFlag, AST[ind]);
		curNode = chainHead[ind];
		curDistance += pos;
		curNode = parent[curNode];
		curDistance++;
	}
}


int quenum = 0;
void treeQuery(int nodeNo) {
	int curNode = nodeNo, addie = 0, avoidChild = -1;
	node bestNode = wasteNode;
	while(curNode != -1) {
		int ind = chainInd[curNode];
		int pos = chainPos[curNode];
		specialQuery(curNode, avoidChild, bestNode, addie);
		queryST(1, 0, chainSize[ind], 0, pos, AST[ind]);
		if(QT[1].distance != -1) QT[1].distance += addie - addend[curNode];
		mymax(bestNode, QT[1], bestNode);
		curNode = chainHead[ind];
		avoidChild = curNode;
		addie += pos;
		curNode = parent[curNode];
		addie++;
	}
	io.pr(bestNode.nodeNo);
}

void solve() {
	//Initializations - Check before submit!!
	adj_ptr = 1;
	chainNo = 0;
	chainHead[0] = -1;
	timestamp = -1;

	int n,m;
	gi(n); gi(m);
	rep(i,n+10) last[i] = 0, isBlack[i] = false;
	parent[1] = -1;
	fu(i,2,n) gi(parent[i]);
	fu(i,2,n) addEdge(parent[i], i);
	dfs(1);
	HLD(1);

	fu(i,1,n) {
		int ind = chainInd[i];
		addend[i] = chainSize[ind] - chainPos[i];
	}

	rep(i,chainNo+1) {
		AST[i] = new node[chainSize[i]*6];
		rep(j,chainSize[i]*6) AST[i][j] = wasteNode;
	}
	AST[chainNo + 10] = new node[n*6];
	rep(j,n*6) AST[chainNo + 10][j] = wasteNode;

	// printf("In of 1, out of 1 are %d %d\n",in[1],out[1]);
	// printf("In of %d, out of %d are %d %d\n",HLchild[1],HLchild[1],in[HLchild[1]],out[HLchild[1]]);
	fu(i,1,n) updateST(1, 0, timestamp+1, in[i], depth[i], i, 0, 1, AST[chainNo + 10]);
	fu(i,1,n) treeUpdate(i);

	while(m--) {
		// printf("-----------------------------\n");
		quenum++;
		int vi; gi(vi);
		if(isBlack[vi]) {
			updateST(1, 0, timestamp+1, in[vi], depth[vi], vi, 0, 1, AST[chainNo + 10]);
			treeUpdate(vi);
		}
		treeQuery(vi);
		if(!isBlack[vi]) {
			updateST(1, 0, timestamp+1, in[vi], -1, vi, 0, 1, AST[chainNo + 10]);
			treeUpdate(vi, 1);
		}
		isBlack[vi] = 1 - isBlack[vi];
	}

	rep(i,chainNo+1) delete(AST[i]);
	delete(AST[chainNo + 10]);
}



int main() {
	int t;
	gi(t);
	while(t--) solve();
	// while(double(clock())/CLOCKS_PER_SEC < 2.0);
	fwrite(OUT, optr-OUT, 1, stdout);
	return 0;
}
