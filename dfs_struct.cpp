#include<bits/stdc++.h>
using namespace std;


struct data
{
	/* data */
	int data;
};


// undirected graph
struct node
{
	int order;
	vector <struct node*> child;
	struct data key;
};

int main(int argc, char const *argv[])
{
	struct node *root=(struct node*)malloc(sizeof(struct node));
	return 0;
}

