#include <stdio.h>
#include <stdlib.h>

struct BT
{
	struct BT *left;
	int item;
	struct BT *right;
};

void postorder(struct BT *root)
{
	if(root!=NULL)
	{
		if(root->left!=NULL)
			postorder(root->left);
		if(root->right!=NULL)
			postorder(root->right);
		printf("%d ", root->item);
	}
}

void preorder(struct BT *root)
{
	if(root!=NULL)
	{
		printf("%d ",root->item);
		if(root->left!=NULL)
			preorder(root->left);
		if(root->right!=NULL)
			preorder(root->right);
	}
}

void inorder(struct BT *root)
{
	if(root!=NULL)
	{
		if(root->left!=NULL)
			inorder(root->left);
		printf("%d ",root->item);
		if(root->right!=NULL)
			inorder(root->right);
	}
}

int main()
{
	struct BT *root;
	root=NULL;
	return 0;
}