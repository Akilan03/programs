#include <myqueue.h>
#include <stdio.h>
#include <conio.h>

int isMyEmpty(struct myqueue *q)
 {
  if(q->front==-1&&q->rear==-1)
  return 1;
  else
  return 0;
 }
int isMyFull(struct myqueue *q)
 {
  if(q->rear==(SIZE-1))
  return 1;
  else
  return 0;
 }
int myEnqueue(struct myqueue *q,char data)
 {
  if(isMyFull(q))
  { return 0;}
  if(isMyEmpty(q))
   {
    q->rear=q->rear+1;
    q->front=q->front+1;
    q->arr[q->rear]=data;
   }
   else
   {
    q->rear=q->rear+1;
    q->arr[q->rear]=data;
   }
  return 1;
 }
int myDequeue(struct myqueue *q,char *data)
 {
  if(isMyEmpty(q))
   {return 0;}
    *data=q->arr[q->front];
    if(q->front==q->rear)
   {
     q->front=-1;
     q->rear=-1;
   }
   else
   q->front=q->front+1;
   return 1;
 }

int getFront(struct myqueue *q,char *data)
 {
  if(isMyEmpty(q))
   {return 0;}
  else
   {
    *data=q->arr[q->front];
    return 1;
   }
  }

int getRear(struct myqueue *q,char *data)
 {
  if(isMyEmpty(q))
   return 0;
  else
   {
    *data=q->arr[q->rear];
    return 1;
   }
  }



 //TEST CODE :
 void main()
  {

   char a[100];
   int i=0;
    char c='\0';
   char c1='\0';
   struct myqueue q;
   q.front=-1;
   q.rear=-1;
   clrscr();
   printf("\nEnter a string :");
   scanf("%s",&a);
   while(a[i]!='\0')
    {
     myEnqueue(&q,a[i]);
     i++;
    }
    printf("\n%s",a);
    printf("\nThe front pointer points to :%d",q.front);
    getFront(&q,&c);
    printf("\nThe front pointer points to :%c",c);


   printf("\nThe rear pointer points to :%d",q.rear);
   getRear(&q,&c);
   printf("\nThe rear pointer points to :%c",c);
   i=1;
   printf("\nThe dequeued string is :");
   while(isMyEmpty(&q)!=1)
    {
     myDequeue(&q,&c1);
     printf("%c",c1);
     }
    getch();
    }


