#include<stdio.h>
#include<stdlib.h>
struct BSTree
{
  int data;
  struct BSTree*lfchld;
  struct BSTree*rtchld;
};
  typedef struct BSTree BSTree;
  struct BSTree*root=NULL;
  struct BSTree*create_BSTree(int);
  void insert(int);
  struct BSTree*delete(struct BSTree*,int);
  int search(int);
  void printtree(struct BSTree*,int);
  void inorder(struct BSTree*);
  void postorder();
  void preorder();
  struct BSTree*smallest_BSTree(struct BSTree*);
  struct BSTree*largest_BSTree(struct BSTree*);
  int get_data();
  void main()
{
  int userChoice;
  int userActive='Y';
  int data;
  struct BSTree*result=NULL;
  while(userActive=='Y'|| userActive=='y')
  {
    printf("\n\n-------Binary Search Tree------\n");
    printf("\n1.Insert");
    printf("\n2.Delete");
    printf("\n3.Search");
    printf("\n4.Get Larger BSTree Data");
    printf("\n5.Get Smaller BSTree Data");
    printf("\n6.Printing the Tree");
    printf("\n\n-- Traversals --");
    printf("\n\n7.Inorder");
    printf("\n8.Post Order");
    printf("\n9.Pre Order");
    printf("\n10.exit");
    printf("\n\nEnter Your Choice:");
    scanf("%d",&userChoice);
    printf("\n");
    switch(userChoice)
    {
      case 1:
	   data=get_data();
	   insert(data);
	   break;
      case 2:
	   data=get_data();
	   root=delete(root,data);
	   break;
      case 3:
	   data=get_data();
	   if(search(data)==1)
	   {
	    printf("\nData was found!\n");
	    }
	    else
	    {
	     printf("\nData does not found!\n");
	    }
	    break;
      case 4:
	   result=largest_BSTree(root);
	   if(result!=NULL)
	    {
	     printf("\nLargest Data:%d\n",result->data);
	     }
	   break;
      case 5:
	   result=smallest_BSTree(root);
	   if(result!=NULL)
	   {
	    printf("\nSmallest Data:%d\n",result->data);
	    }
	   break;
      case 6:
	   printtree(root,1);
	   break;
      case 7:
	   inorder(root);
	   break;
      case 8:
	   postorder(root);
	   break;
      case 9:
	   preorder(root);
	   break;
      case 10:
	    exit(0);
	    break;
      default:
	     printf("\n\tInvalid Choice\n");
	     break;
    }
    printf("\n_____\nDo you want to continue?");
    fflush(stdin);
    scanf("%c",&userActive);

  }
}
  struct BSTree*create_BSTree(int data)
 {
  struct BSTree*new_BSTree=(struct BSTree*)malloc(sizeof(struct BSTree));
  if(new_BSTree==NULL)
  {
   printf("\nMemory for new BSTree can't be allocated");
   return NULL;
   }
   new_BSTree->data=data;
   new_BSTree->lfchld=NULL;
   new_BSTree->rtchld=NULL;

   return new_BSTree;
 }
void insert(int data)
{
  struct BSTree*temp,*prev;
  struct BSTree*new_BSTree=create_BSTree(data);
  if(new_BSTree!=NULL)
  {
   if(root==NULL)
    {
     root=new_BSTree;
     printf("\n* BSTree having data%d was inserted\n",data);
     return;
    }
     temp=root;
     prev=NULL;
     while(temp!=NULL)
     {
      prev=temp;
      if(data>temp->data)
      {
       temp=temp->rtchld;
      }
      else
      {
       temp=temp->lfchld;
      }
    }
     if(data>prev->data)
      {
       prev->rtchld=new_BSTree;
      }
      else
      {
       prev->lfchld=new_BSTree;
      }
      printf("\n*BSTree having data%d was inserted\n",data);
     }
  }
      struct BSTree*delete(struct BSTree*root,int key)
      {
       struct BSTree*temp;
       if(root==NULL)
	{
	return root;
	}
	if(key<root->data)
	{
	 root->lfchld=delete(root->lfchld,key);
	}
	else if(key>root->data)
	{
	 root->rtchld=delete(root->rtchld,key);
	}
	else
	{
	 if(root->lfchld==NULL)
	 {
	  struct BSTree*temp=root->lfchld;
	  free(root);
	  return temp;
	 }
	else if(root->rtchld==NULL)
	 {
	  struct BSTree*temp=root->rtchld;
	  free(root);
	  return temp;
	 }
	  temp=smallest_BSTree(root->rtchld);
	  root->data=temp->data;
	  root->rtchld=delete(root->rtchld,temp->data);
	}
	 return root;
	 }
	 int search(int key)
	 {
	  struct BSTree*temp=root;
	  while(temp!=NULL)
	  {
	  if(key==temp->data)
	   {
	    return 1;
	    }
	    else if(key>temp->data)
	    {
	      temp=temp->rtchld;
	      }
	      else
	      {
	       temp=temp->lfchld;
	       }
	    }
	    return 0;
	    }
	    struct BSTree*smallest_BSTree(struct BSTree*root)
	    {
	     struct BSTree*curr=root;
	     while(curr!=NULL&&curr->lfchld!=NULL)
	     {
	      curr=curr->lfchld;
	     }
	     return curr;
	    }
	    struct BSTree*largest_BSTree(struct BSTree*root)
	    {
	     struct BSTree*curr=root;
	     while(curr!=NULL&&curr->rtchld!=NULL)
	     {
	      curr=curr->rtchld;
	     }
	     return curr;
	    }
      void printtree(struct BSTree*t,int level)
	{
	 int i;
	 if(t!=NULL)
	  { printtree(t->rtchld,level+1);
	    printf("\n");
	    for(i=0;i<level;i++)
	  printf(" ");
	    printf("%d",t->data);
	    printtree(t->lfchld,level+1);
	   }
	}
void inorder(struct BSTree*root)
{
  if(root==NULL)
  {
    return;
  }
  inorder(root->lfchld);
  printf("%d",root->data);
  inorder(root->rtchld);
}
void preorder(struct BSTree*root)
  {
   if(root==NULL)
   {
    return;
    }
    printf("%d",root->data);
    preorder(root->lfchld);
    preorder(root->rtchld);

   }
void postorder(struct BSTree*root)
   {
   if(root==NULL)
    {
     return;
    }
    postorder(root->lfchld);
    postorder(root->rtchld);
    printf("%d",root->data);
   }
    int get_data()
    {
     int data;
     printf("\nEnter data:");
     scanf("%d",&data);
     return data;
    }

