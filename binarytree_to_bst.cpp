#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

int data[1000];
int cnt;
struct node *inorder[1000];
void storeInorder(struct node* node)
{
    if(node==NULL)
        return;
    storeInorder(node->left);
    data[cnt]=node->data;
    inorder[cnt]=node;
    storeInorder(node->right);

}

void binary_to_bst()
{
    sort(data,data+cnt);
    for(int i=0;i<cnt;i++)
    {
        inorder[i]->data=data[i];
    }
}

struct node* newNode(int data)
{
    struct node* temp=new struct node;
    temp->left=NULL;
    temp->right=NULL;
    temp->data=data;
    return temp;
};
int main()
{
    struct node *root=NULL;
    root=newNode(10);
    root->left=newNode(30);
    root->right=newNode(15);
    return 0;
}
