#include<bits/stdc++.h>
using namespace std;


int random(int base,int range)
{
	return base+(rand())%range;
}

struct node
{
	int childs;
	int parents;
	vector<int>child;
	child.resize(child_s);
	vector<int>parent;

};


node *create_node()
{
	node *root=new(node);
	return root;
}


void rand_dag()
{
	node *root=create_node();
	int noc=rand()%2;
	n--;

	for(int i=0;i<noc;i++)
	{
		node *child=create_node();
		root->child[]
	}
}

int main()
{
	node *temp=create_node();
	return 0;
}