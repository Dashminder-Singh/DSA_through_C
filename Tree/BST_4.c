#include <stdio.h>
#include <stdlib.h>

struct BST
{
	struct BST *left;
	int item;
	struct BST *right;
};

void del_0(struct BST *ptr, struct BST *parptr, struct BST *root)
{
	if(parptr==NULL)
	{
		root=NULL;
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

void del_1(struct BST *ptr, struct BST *parptr, struct BST *root)
{
	if(parptr==NULL)
	{
		if(ptr->left!=NULL)
			root=ptr->left;
		else
			root=ptr->right;
	}
	else if(ptr==parptr->left)
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
void del_2(struct BST *ptr)
{
	struct BST *s, *ps;
	s=ptr->right;
	ps=ptr;

	while(s->left!=NULL)
	{
		ps=s;
		s=s->left;
	}
	ptr->item=s->item;
	if(s==ps->left)
		ps->left=s->right;
	else
		ps->right=s->right;
	free(s);
}

void deletion(struct BST **r,int data)
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
			printf("Not found\n");
		}
		else
		{
			if(ptr->left==NULL && ptr->right==NULL)
			{
				del_0(ptr,parptr,*r);
			}
			else if(ptr->left==NULL || ptr->right==NULL)
			{
				del_1(ptr,parptr, *r);
			}
			else
			{
				del_2(ptr);
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
		while(t!=NULL)
		{
			if(t->item== data)
			{
				printf("Duplicasy not allowed\n");
				free(n);
				break;
			}
			else if(t->item>data)
			{
				if(t->left== NULL)
				{
					t->left=n;
					break;
				}
				t=t->left;
			}
			else
			{
				if(t->right== NULL)
				{
					t->right=n;
					break;
				}
				t=t->right;
			}
		}
	}
}

void find(struct BST **r, int data)
{
	struct BST *t;
	t=*r;
	int flag=1;
	while(t!=NULL)
	{
		if(t->item== data)
		{
			printf("%d is found\n",data);
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
		printf("%d ",root->item);
	}
}

void preorder(struct BST *root)
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


void inorder(struct BST *root)
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


	printf("\nInorder: ");
	inorder(root);
	printf("\n");

	deletion(&root,10);
	deletion(&root,60);

	printf("\nAfter deletion: ");
	inorder(root);
	printf("\n");
	
	return 0;
}