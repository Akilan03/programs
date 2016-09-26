#include <stdio.h>
#include <conio.h>
#include <myStack1.h>


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



void main()
 {
 char str[100];int i=0;int res=0; int op1;   int op2;
  struct myStack s;
  s.top=-1;
  clrscr();
  printf("\nEnter the postfix string :");
 scanf("%s", str);

 while(str[i]!='\0')
  {
   if(isOperand(str[i])==1)
    {
     myPush(&s,str[i]-'0');
    }
   else
    {
     myPop(&s,&op2);
     myPop(&s,&op1);
     res=result(op1,op2,str[i]);
     myPush(&s,res);
    }
   i=i+1;
   }
  myPop(&s,&res);
  printf("%d",res);
  getch();
  }

 int result(int a,int b,char c)
  {
   if(c=='+')
   return (a+b);
   else if(c=='-')
   return (a-b);
     else if(c=='*')
   return (a*b);
     else
   return (a/b);
   }
    int isOperand(char c)
  {
   if(c=='+'||c=='-'||c=='*'||c=='/'||c=='('||c==')')
   return 0;
   else
   return 1;
  }