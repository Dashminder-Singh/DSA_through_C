#include <stdio.h>
#include <stdlib.h>

struct BST
{
	int item;
	struct BST *left;
	struct BST *right;
};

struct BST *insert(struct BST *root, int data) 
{
	struct BST *n;
	n=malloc(sizeof(struct BST));
	n->item=data;
	n->left=NULL;
	n->right=NULL;

	if(root==NULL)
	{
		root=n;
	}
	else if(root->item== data)
	{
		printf("Duplicasy not allowed\n");
		free(n);
		return root;
	}
	else if(root->item> data)
	{
		root->left=insert(root->left,data);
	}
	else
	{
		root->right=insert(root->right,data);
	}
	return root;
}

struct BST *search(struct BST *root, int data)
{
	if(root==NULL)
	{
		return NULL;
	}
	if(root->item== data)
	{
		return root;
	}
	else if(root->item> data)
	{
		search(root->left, data);
	}
	else
	{
		search(root->right, data);
	}
}

void postorder(struct BST *root)
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

void preorder(struct BST *root)
{
	if(root!=NULL)
	{
		printf("%d ", root->item);
		if(root->left!=NULL)
			preorder(root->left);
		if(root->right!=NULL)
			preorder(root->right);
	}
}

void inorder(struct BST *root)
{
	if(root!=NULL)
	{
		if(root->left!=NULL)
			inorder(root->left);
		printf("%d ", root->item);
		if(root->right!=NULL)
			inorder(root->right);
	}
}

int main()
{
	struct BST *root;
	root=NULL;

	root=insert(root,50);
	root=insert(root,70);
	root=insert(root,60);
	root=insert(root,30);

	root=insert(root,10);
	root=insert(root,40);

	printf("\nPreorder: ");
	preorder(root);
	printf("\n");

	printf("\nInorder: ");
	inorder(root);
	printf("\n");

	struct BST *s1;
	s1=search(root,40);
	if(s1!=NULL)
		printf("%d is found\n", s1->item);
	else
		printf("Not found");

	return 0;
}