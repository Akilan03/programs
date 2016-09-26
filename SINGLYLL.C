#include <stdio.h>
#include <conio.h>

struct node
 {
  int data;
  struct node *next;
 };

int searchnode(struct node *head,int data,struct node **prev)
 {
  *prev=null;
  struct node *temp=head;
  while(temp&&data>temp->data)
   {
    *prev=temp;
     temp=temp->next;
   }
  if(temp==null)
  return 0;
  else if(data==temp->data)
  return 1;
  else
  return 0;
 }

int insertnode(struct node **head,int data)
 {
  struct node newnode=null;
  struct node *prev=null;
  if(searchnode(*head,data,&prev))
   {
    printf("\nduplicate insertion");
   return 0;
   }
  newnode=(struct node *)malloc(sizeof(struct node));
  if(newnode==null)
  return 0;

  newnode->data=data;

  if(prev==null)
   {
    newnode->next=*head;
    *head=newnode;
   }
  else
   {
    newnode->next=prev->next;
    prev->next=newnode;
    return 1;
   }
}

int traverse(struct node *head)
 {
  struct node *temp=head;
  while(temp)
   {
    printf("%d",temp->data);
    temp=temp->next;
   }
   return 1;
 }