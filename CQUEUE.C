#include <cqueue.h>
#include <stdio.h>
#include <conio.h>

int isMyEmpty(struct cqueue *q)
 {
  if(q->front==-1&&q->rear==-1)
  return 1;
  else
  return 0;
 }
int isMyFull(struct cqueue *q)
 {
  if((((q->rear)+1)%SIZE)==q->front)
  return 1;
  else
  return 0;
 }
int myEnqueue(struct cqueue *q,char data)
 {
  if(isMyFull(q))
  { return 0;}
  if(isMyEmpty(q))
   {
    q->rear=0;
    q->front=0;
    }
   else
    {q->rear=(((q->rear)+1)%SIZE); }
    q->arr[q->rear]=data;
  return 1;
 }
int myDequeue(struct cqueue *q,char *data)
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
   {q->front=((q->front)+1)%SIZE;}
   return 1;
 }

int getFront(struct cqueue *q,char *data)
 {
  if(isMyEmpty(q))
   {return 0;}
  else
   {
    *data=q->arr[q->front];
    return 1;
   }
  }

int getRear(struct cqueue *q,char *data)
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
   struct cqueue q;
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
    printf("\n\tThe front pointer points to :%d",q.front);
    getFront(&q,&c);
    printf("\n\tThe front pointer points to :%c",c);


   printf("\n\tThe rear pointer points to :%d",q.rear);
   getRear(&q,&c);
   printf("\n\tThe rear pointer points to :%c",c);

   myDequeue(&q,&c);
   printf("\n\tthe dequeued element is :%c",c);

   myDequeue(&q,&c);
   printf("\n\tthe dequeued element is :%c",c);

     myEnqueue(&q,'c');
     myEnqueue(&q,'c');
     printf("\n\tnew circular queue :");


   printf("\n\tThe front pointer points to :%d",q.front);
    getFront(&q,&c);
    printf("\n\tThe front pointer points to :%c",c);


   printf("\n\tThe rear pointer points to :%d",q.rear);
   getRear(&q,&c);
   printf("\n\tThe rear pointer points to :%c",c);

   printf("\n\tThe dequeued string is :");
   while(isMyEmpty(&q)!=1)
    {
     myDequeue(&q,&c1);
     printf("%c",c1);
     }
    getch();
    }


