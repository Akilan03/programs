#include <stdio.h>
#include <conio.h>


struct node
 {
  int coeff;
  int exp;
  struct node *next;
 };

int searchnode(struct node *head, int data, struct node **prev) {
	struct node *temp = head;
	*prev=NULL;
	while(temp && data<temp->exp)
	  {
	   *prev=temp;
	   temp=temp->next;
	  }
	if(!temp)
		return 0;
	else if(data==temp->exp)
		return 1;
	else
		return 0;
 }


int insertnode(struct node **head,int data,int exp)
 {
  struct node *newnode=(struct node *)malloc(sizeof(struct node));
  struct node *prev=NULL;
  if(searchnode(*head,exp,&prev)==1)
   {
    printf("\nduplicate insertion");
   return 0;
   }

  if(newnode==NULL)
 { return 0;}

  newnode->coeff=data;
  newnode->exp=exp;


  if(prev==NULL)
   {
    newnode->next=*head;
    *head=newnode;
   }
  else
   {
    newnode->next=prev->next;
    prev->next=newnode;
   }
    return 1;
}
int traversenode(struct node *head)
 {
  struct node *temp=head;
  while(temp)
   {

    printf("%dx^%d ",temp->coeff,temp->exp);
    temp=temp->next;
   }
   return 1;
 }
int add(struct node *p1,struct node *p2,struct node **p3) {
	struct node *temp1=p1;
	struct node *temp2=p2;

	while(temp1 &&temp2)
	  {
	    if(temp1->exp<temp2->exp)
	     {
	       insertnode(p3,temp2->coeff,temp2->exp);
	       temp2=temp2->next;
	     }
	    else if(temp1->exp>temp2->exp)
	     {
	       insertnode(p3,temp1->coeff,temp1->exp);
	       temp1=temp1->next;
	     }
	    else
	     {
	      insertnode(p3,(temp2->coeff+temp1->coeff),temp2->exp);
	       temp1=temp1->next;
	       temp2=temp2->next;
	     }

	  }
	if(temp1)
	 {
	  temp2=temp1;
	 }
	while(temp2)
	 {
	  insertnode(p3,temp2->coeff,temp2->exp);
	       temp2=temp2->next;
	 }
	 return 1;
}






  //main function
int main()
 {
  struct node *p1=NULL;
  struct node *p2=NULL;
  struct node *p3=NULL;
  int i,n1,n2,data1,data2;
  clrscr();
  i=1;
  printf("\nenter the number of terms in polynomial 1 :");
  scanf("%d",&n1);
  while(i<=n1)
   {  printf("\nenter %d the coefficient :",i);
     scanf("%d",&data1);
     printf("\nenter %d the exponential :",i);
     scanf("%d",&data2);
    insertnode(&p1,data1,data2);
    i=i+1;
   }

  printf("\nenter the number of terms in polynomial 2 :");
  scanf("%d",&n2);
  for(i=1;i<=n2;i++)
   {
     printf("\nenter %d the coefficient :",i);
     scanf("%d",&data1);
     printf("\nenter %d the exponential :",i);
     scanf("%d",&data2);
    insertnode(&p2,data1,data2);

   }
  add(p1,p2,&p3);
  printf("\n  polynomial 1 :");
  traversenode(p1);
  printf("\n  polynomial 2 :");
  traversenode(p2);
   printf("\nthe terms in the added polynomial are :");
  traversenode(p3);
  getch();
  return 1;
 }
