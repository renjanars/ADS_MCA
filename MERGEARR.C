#include<stdio.h>
#include<conio.h>
void main()
{
 int a[50],b[50],c[100],m,n,i,j,k=0;
 printf("enter size of first array:");
 scanf("%d",&m);
 printf("\n enter sorted elements of first array:");
 for(i=0;i<m;i++)
  {
   scanf("%d",&a[i]);
  }
 printf("enter the size of second array:");
 scanf("%d",&n);
 printf("\n enter sorted elements of second array:");
 for(i=0;i<n;i++)
   {
    scanf("%d",&b[i]);
   }
 i=j=k=0;
 while(i<m && j<n)
  {
    if(a[i]<b[j])
    {
    c[k]=a[i];
    i++;
    }
  else if (a[i]>b[j])
  {
   c[k]=b[j];
   j++;
  }
  else
   {
   c[k]=a[i];
   i++;
   j++;
   }
   k++;
 }
  while(i<m)
  {
   c[k]=a[i];
   i++;
   k++;
  }
  while(j<n)
  {
  c[k]=b[j];
  j++;
  k++;
  }
 printf("after merging:\n");
 for(i=0;i<m+n;i++)
 {
  printf("%d",c[i]);
  }
  getch();
}
