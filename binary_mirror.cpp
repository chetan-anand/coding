void mirror(struct node* node) 
{
  if (node==NULL) 
    return;  
  else
  {
    struct node* temp;
     
    /* do the subtrees */
    mirror(node->left);
    mirror(node->right);
 
    /* swap the pointers in this node */
    temp        = node->left;
    node->left  = node->right;
    node->right = temp;
  }

  if(root==NULL)
  {
  	return;
  }
  mirror()
  struct node* temp;
  temp=root->left;
  root->left=root->right;
  root->right=temp;
}