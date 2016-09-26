#include "myStack1.h"


int myIsEmpty(struct myStack *s)
 {
  if(s->top==-1)
   return 1;
  else
   return 0;
 }

int myIsFull(struct myStack *s)
 {
  if(s->top==SIZE-1)
   return 1;
  else
   return 0;
 }

int myPush(struct myStack *s,int data)
 {
   if(s->top==SIZE-1)
    return 0;
   else
    {
      s->top+=1;
      s->arr[s->top]=data;
      return 1;
    }
 }

int myPop(struct myStack *s,int *data)
 {
  if(s->top==-1)
   return 0;
  else
   {
    *data=s->arr[s->top];
    s->top-=1;
    return 1;
   }
 }

int myPeek(struct myStack *s,int *data)
 {
  if(s->top==-1)
   return 0;
  else
   {
    *data=s->arr[s->top];
    return 1;
   }
 }




