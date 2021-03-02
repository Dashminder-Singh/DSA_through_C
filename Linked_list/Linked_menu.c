#include<stdio.h>
#include <stdlib.h>
struct node
{
    int item;
    struct node *next;
};

void insertLast(struct node**s,int data)
{
    struct node *n,*t;
    n=malloc(sizeof(struct node));
    n->item=data;
    n->next=NULL;
    if(*s==NULL)
        *s=n;
     else
     {
       t=*s;
       while(t->next!=NULL)
            t=t->next;
       t->next=n;
     }
}
void insertFirst(struct node**s,int data)
{
    struct node*n;
    n=malloc(sizeof(struct node));
     n->item=data;
     n->next=*s;
     *s=n;
}
void insertAfter(struct node *t, int data)
{
   struct node*n;
   n=malloc(sizeof(struct node));
   n->item=data;
   n->next=t->next;
   t->next=n;
}

 void removeFirst(struct  node**s)
 {
     struct node *r;
     if(*s==NULL)
         printf("\n nothing to delete");
      else
        r=*s;
      *s=r->next;
      free(r);
 }
 void removeLast(struct node**s)
 {
     struct node *t1,*t2;
     if(*s==NULL)
         printf("\n Nothing to delete");
       else
       {
           t1=*s;
           t2=NULL;
           while(t1->next!=NULL)
             {
               t2=t1;
               t1=t1->next;
             }
             if(t2!=NULL)
                t2->next=NULL;
             else
                *s=NULL;
             free(t1);
       }

 }
 void removeNode(struct node**s,struct node*r)
 {
     struct node*t;
     if(*s==r)
     {
        *s=r->next;
     }
      else
      {
          t=*s;
          while(t->next!=r)
          {
            t=t->next;
          }
          t->next=r->next;
      }
      free (r);
 }

 struct node*search(struct node *start, int data)
 {
     while(start)
     {
     	if(start->item==data)
     	{
            return start;
        }
      start=start->next;
     }
     printf("%d is not found",data);
     printf("\n");
     return NULL;  
 }
   void viewlist(struct node **s)
   {
       struct node*t;
       t=*s;
       while(t)
       {
           printf("%d ",t->item);
           t=t->next;
       }
   }

  int menu()
   {
       int choice ;
       printf("\n1.insert at first");
       printf("\n2.insert at last");
       printf("\n3.search");
       printf("\n4.insert after");
       printf("\n5.remove first");
       printf("\n6.remove last");
       printf("\n7.remove Node");
       printf("\n8.exit");
       printf("\nEnter your choice: ");
       scanf("%d",&choice);
       return choice;
   }

int  main()
{
  struct node *start;
  start=NULL;
  int data,value;
  struct node *r,*r2;
  while(1)
  {
    system("cls");
    viewlist(&start);
    switch(menu())
    {
          case 1:
          printf("Enter the item value first node: ");
          scanf("%d",&data);
          insertFirst(&start,data);
          break;
          case 2:
          printf("Enter the item value last node: ");
          scanf("%d",&data);
          insertLast(&start,data);
          break;
          case 3:
          printf("Enter the item value for search: ");
          scanf("%d",&data);
          r=search(start,data);
          printf("%d is found",r->item);
          break;
          case 4:
          printf("Enter one value to search & one value to insert: ");
          scanf("%d%d",&data,&value);
          r=search(start,data);
          insertAfter(r,value);
          break;
          case 5:
          removeFirst(&start);
          break;
          case 6:
          removeLast(&start);
          break;
          case 7:
          printf("Enter value to delete a particular node: ");
          scanf("%d",&data);
          r2=search(start,data);
          removeNode(&start,r2);
          break;
          case 8:
          exit(0);
          break;
          default:
          printf("\n. Invalid choice");
          break;
    }
  }
}