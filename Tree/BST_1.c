#include <stdio.h>
#include <stdlib.h>

struct BST
{
	int item;
	struct BST *left;
	struct BST *right;
};

void deletion(struct BST **r, int data)
{
	struct BST *ptr, *parptr;

	if(*r==NULL)
	{
		printf("Underflow\n");
	}
	else
	{
		ptr=*r;
		parptr=NULL;
		while(ptr->item!=data && ptr!=NULL)
		{
			if(ptr->item>data)
			{
				parptr=ptr;
				ptr=ptr->left;
			}
			else
			{
				parptr=ptr;
				ptr=ptr->right;
			}
		}
		if(ptr==NULL)
		{
			printf("Data Not Found");
		}
		else
		{
			if(ptr->left==NULL && ptr->right==NULL) // delete 0
			{
				if(parptr==NULL)
				{
					*r=NULL;
				}
				else if(ptr== parptr->left)
				{
					parptr->left=NULL;
				}
				else
				{
					parptr->right=NULL;
				}
				free(ptr);
			}

			else if(ptr->left==NULL || ptr->right==NULL) // delete 1
			{
				if(parptr==NULL)
				{
					if(ptr->left!=NULL)
						*r=ptr->left;
					else
						*r=ptr->right;
				}
				else if(ptr== parptr->left)
				{
					if(ptr->left!=NULL)
						parptr->left=ptr->left;
					else
						parptr->left=ptr->right;
				}
				else
				{
					if(ptr->left!=NULL)
						parptr->right=ptr->left;
					else
						parptr->right=ptr->right;
				}
				free(ptr);
			}

			else  								// delete 2
			{
				struct BST * pred, *parpred;
				pred=ptr->left;
				parpred=ptr;

				while(pred->right!=NULL)
				{
					parpred=pred;
					pred=pred->right;
				}

				ptr->item=pred->item;

				if(pred== parpred->left)
				{
					parpred->left= pred->left;
				}
				else
				{
					parpred->right= pred->left;
				}
				free(pred);
			}
		}
	}
}

void insert(struct BST **r, int data)
{
	struct BST *n, *t;
	n=malloc(sizeof(struct BST));
	n->item=data;
	n->left=NULL;
	n->right=NULL;

	if(*r==NULL)
	{
		*r=n;
	}
	else
	{
		t=*r;
		while(1)
		{
			if(t->item== data)
			{
				printf("Duplicate elements cannot be inserted\n");
				free(n);
				break;
			}
			else if(t->item> data)
			{
				if(t->left== NULL)
				{
					t->left=n;
					break;
				}
				else
					t=t->left;
			}
			else
			{
				if(t->right== NULL)
				{
					t->right=n;
					break;
				}
				else
					t=t->right;
			}	
		}
	}
}

void search(struct BST **r,int data)
{
	int flag=1;
	struct BST *t;
	t=*r;
	while(t!=NULL)
	{
		if(t->item==data)
		{
			printf("%d is found\n", data);
			flag=0;
			break;
		}
		else if(t->item>data)
		{
			t=t->left;
		}
		else
		{
			t=t->right;
		}
	}
	if(flag==1)
		printf("Not found\n");
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

	insert(&root,50);
	insert(&root,70);
	insert(&root,60);
	insert(&root,30);

	insert(&root,10);
	insert(&root,40);
	insert(&root,55);
	insert(&root,65);
	insert(&root,58);

	/*printf("\nPreOrder: ");
	preorder(root);
	printf("\n");*/



	printf("\nInOrder: ");
	inorder(root);
	printf("\n");

	deletion(&root,60);
	deletion(&root,65);


	printf("\nAfter deletion: ");
	inorder(root);
	printf("\n");

	/*printf("\nPostOrder: ");
	postorder(root);
	printf("\n");*/


	return 0;
}