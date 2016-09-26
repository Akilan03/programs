
#include <stdio.h>
#include <conio.h>
#include <circlell.h>

int searchnode(struct node *head, int data, struct node **prev) {
	struct node *temp = head;
	*prev=NULL;
    if(temp==NULL)
    return 0;
    do
   { if(data>temp->data)
      {
    *prev=temp;
     temp=temp->next;
     }
   }while(temp!=head&&temp->data<data);

	 if(data==temp->data)
		return 1;
	else
		return 0;
 }

int insertnode(struct node **head,int data)
 {
  struct node *newnode=(struct node *)malloc(sizeof(struct node));
  struct node *prev=NULL;
  struct node *last=NULL;
  if(searchnode(*head,data,&prev))
   {
    printf("\nduplicate insertion");
   return 0;
   }

  if(newnode==NULL)
  return 0;

  newnode->data=data;
  if(!(*head))//cll empty
  {
  newnode->next=newnode;
  *head=newnode;
  return 1;
  }

  if(prev==NULL)//at head
   {
     last=*head;
     newnode->next=*head;
     while(last->next!=*head)
     {last=last->next;}
     last->next=newnode;
     *head=newnode;
     return 1;
   }
  else//at middle or end
   {
    newnode->next=prev->next;
    prev->next=newnode;
    return 1;
   }

}

int traversenode(struct node *head)
 {
  struct node *temp=head;
  printf("\nthe present list is :");
  do
   {

    printf("%d ",temp->data);
    temp=temp->next;
   }while(temp!=head);
   return 1;
 }

int deletenode(struct node **head,int data)
 {
  struct node *prev=NULL,*temp=NULL,*last=NULL;
  if(!searchnode(*head,data,&prev))
  { return 0; }

  if((*head)->next==*head)
  {
   free(*head);
   *head=NULL;
   return 1;
  }
  if(prev==NULL)
   {last=*head;
    temp=*head;
    do
     {
     last=last->next;
     }while(last->next!=(*head));
      *head=(*head)->next;
    last->next=*head;
    free(temp);
    return 1;
   }
  else
   {
    temp=prev->next;
    prev->next=temp->next;
    free(temp);
    return 1;
   }

  }

 //main function
int main()
 {
  struct node *head=NULL;
  int i,n,data;
  clrscr();
  printf("\nenter the number of terms :");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
   {
     printf("\nenter %d the number :",i);
     scanf("%d",&data);
    insertnode(&head,data);

    traversenode(head);
   }

  printf("\nenter the number to be deleted :");
  scanf("%d",&data);

  deletenode(&head,data);

  traversenode(head);
  getch();
  return 1;
 }