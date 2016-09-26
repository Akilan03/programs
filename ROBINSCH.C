#include<stdio.h>
#include<conio.h>
#include<queue.h>

int isEmpty(struct myqueue *q)
	{
	 if(q->front==-1 && q->rear==-1)
		return 1;
	 else
		return 0;
	}

int isFull(struct myqueue *q)
	{
	 if((q->rear+1)%SIZE==q->front)
		return 1;
	 else
		return 0;
	}

int enQueue(struct myqueue *q, int data)
	{
	 if(isFull(q))
		return 0;
	 if(isEmpty(q))
		{
		q->front=q->front+1;
		q->rear=(q->rear)+1;
		q->arr[q->rear]=data;
		}
	 else
		{
		q->rear=(q->rear+1)%SIZE;
		q->arr[q->rear]=data;
		}
		return 1;
	}

int deQueue(struct myqueue *q, int *data)
	{
	 if(isEmpty(q))
		return 0;
	 *data=q->arr[q->front];
	 if(q->front==q->rear)
	 {
	  q->front=-1;
	  q->rear=-1;
	 }
	 else
	  q->front=(q->front+1)%SIZE;
	  return 1;
	}

int getFront(struct myqueue *q, int *data)
	{
	 if(isEmpty(q))
		return 0;
	 else
		{
		 *data=q->arr[q->front];
		 return 1;
		}
	}

int getRear(struct myqueue *q, int *data)
	{
	 if(isEmpty(q))
		return 0;
	 else
		{
		 *data=q->arr[q->rear];
		 return 1;
		}
	}
//roundrobin
int main(){
int a[100],b[100],rem=0;
int n,i,j,c,p,flag=0;
int cpu=3;
int n1;
struct myqueue q,q1,q2;
q.front=-1;q.rear=-1;
q1.front=-1;q1.rear=-1;
q2.front=-1;q2.rear=-1;
clrscr();
printf("\nenter the number of processes :");
scanf("%d",&n1);
for(i=0;i<n1;i++)
 {
  printf("\nenter the id for the %d process :",(i+1));
  scanf("%d",&b[i]);
  printf("\nenter the time for the %d process :",(i+1));
  scanf("%d",&a[i]);
  enQueue(&q,a[i]);
  enQueue(&q1,b[i]);
  enQueue(&q2,a[i]);
  }
  printf("\nid  processtime  remainingtime  status");
  i=0;
  for(j=0;;)
    {
     deQueue(&q,&n);
     deQueue(&q1,&c);
     deQueue(&q2,&p);
     if(n<=cpu)
      {
       rem=0;
       printf("\n%d           %d             %d  completed",c,p,rem);
       j++;
       if(j==n1)
       break;
      }
    else
    {
      rem=n-cpu;
     printf("\n%d           %d             %d  incomplete",c,p,rem);
     enQueue(&q,rem);
     enQueue(&q1,c);
     enQueue(&q2,p);
    }
  }

 getch();
 return 0;
}




