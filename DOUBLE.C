#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
 int info;
 struct node *prev,*next;
};
struct node *start = NULL;
void traverse()
{
  struct node *temp;
  temp=start;
 if(start==NULL)
 {
   printf("\n list is empty\n");
   return;
 }
  printf("data is:");
 while(temp!=NULL)
 {
  printf("data is %d \n",temp->info);
  temp=temp->next;
 }
}
void insert_at_front()
{
 int data;
 struct node *temp;
 temp=(struct node*)malloc(sizeof(struct node));
 printf("\n enter numbers to be inserted:");
 scanf("%d",&data);
 temp->info=data;
 temp->prev=NULL;
 temp->next=start;
 start=temp;
}
void insert_at_end()
{
  int data;
  struct node *temp, *trav;
  temp=(struct node *)malloc(sizeof(struct node));
  temp->prev=NULL;
  temp->next=NULL;
  printf("\n each data to be inserted:");
  scanf("%d",&data);
  temp->info=data;
  temp->next=NULL;
  trav=start;
  if(start==NULL)
   {
     start=temp;
   }
   else
   {
    while(trav->next!= NULL)
    {
     trav=trav->next;
    }
    temp->prev=trav;
    trav->next=temp;
   }
}
void insert_at_position()
{
 int data,pos,i=1;
 struct node *temp, *newnode;
 newnode=(struct node*)malloc(sizeof(struct node));
 newnode->next=NULL;
 newnode->prev=NULL;
 printf("\n enter position:");
 scanf("%d",& pos);
 printf("enter data to be inserted:");
 scanf("%d",&data);
 newnode->info = data;
 temp=start;
 if(start==NULL)
 {
  start=newnode;
  newnode->prev=NULL;
  newnode->next=NULL;
 }
 else if(pos==1)
 {
  newnode->next=start;
  newnode->next->prev=newnode;
 newnode->prev=NULL;
 start=newnode;
 }
 else
 {
   while(i<pos-1)
   {
     temp=temp->next;
     i++;
   }
   newnode->next=temp->next;
   newnode->prev=temp;
   temp->next=newnode;
   temp->next->prev=newnode;
 }
}
void delete_first()
{
 struct node *temp;
 if(start==NULL)
  printf("\n list is empty \n");
 else
 {
  temp=start;
  start=start->next;
  if(start!=NULL)
  {
   start->prev=NULL;
  }
  free(temp);
  printf("item deleted");
 }
}
void delete_end()
 {
  struct node *temp;
  if(start==NULL)
  {
    printf("\n list is empty \n");
  }
   temp=start;
   while(temp->next!=NULL)
   {
     temp=temp->next;
   }
   if(start->next==NULL)
   {
     start=NULL;
   }
   else
   {
    temp->prev->next=NULL;
    free(temp);
   }
 }
void delete_position()
{
  int pos,i=1;
  struct node *temp,*position;
  temp=start;
  if(start==NULL)
  {
   printf("llist is empty \n");
  }
  else
  {
   printf("\nenter position:");
   scanf("%d",&pos);
   if(pos==1)
   {
    position=start;
    start=start->next;
    if(start!=NULL)
    {
     start->prev=NULL;
    }
    free(position);
    return;
   }
   while(i<pos-1)
   {
   temp=temp->next;
   i++;
   }
   position=temp->next;
   if(position->next!=NULL)
   {
     position->next->prev=temp;
   }
    temp->next=position->next;
    free(position);
  }
}
void search()
 {
  struct node *temp;
  int item,i=0,flag;
  temp=start;
  if(temp==NULL)
  {
   printf("list is empty\n");
  }
  else
  {
   printf("enter the element to be searched:");
   scanf("%d",&item);
   while(temp!=NULL)
    {
     if(temp->info==item)
     {
      printf("item found at position%d",i++);
      flag=0;break;
     }
     else
      {
       flag=1;
      }
     i++;
     temp=temp->next;
    }
    if(flag==1)
    {
    printf("item not found");
    }
  }
 }
void main()
{
 int choice;
 while(1)
  {
   printf("\n 1.insert at first \n");
   printf(" 2.insert at end \n");
   printf(" 3.insert at any position \n");
   printf(" 4.delete first element \n");
   printf(" 5.delete last element \n");
   printf(" 6.delete element at any position \n");
   printf(" 7.search an element \n");
   printf(" 8.display the list \n");
   printf(" 9.exit \n");
   printf("\n enter choice:\n");
   scanf("%d",&choice);
   switch(choice)
   {
    case1:insert_at_front();
	  break;
    case2:insert_at_end();
	  break;
    case3:insert_at_position();
	  break;
    case4:delete_first();
	  break;
    case5:delete_end();
	  break;
    case6:delete_position();
	  break;
    case7:search();
	  break;
    case8:traverse();
	  break;
    case9:exit(0);
	  break;
    default:printf("wrong choice");
	    continue;
   }
  }
}