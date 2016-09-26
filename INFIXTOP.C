#include <stdio.h>
#include <conio.h>
#include <mystack2.h>
int isempty1(struct mystack *s) {
    if (s->top==-1)
    return 1;
else
    return 0;
}
int isfull1(struct mystack *s) {
    if (s->top==SIZE-1)
    return 1;
else
    return 0;
}

int push1(struct mystack *s,char c) {
    if (isfull1(s)) {
    return 0;
} else {
    s->top=s->top+1;
    s->arr[s->top]=c;
    return 1;
   }
}

int pop1(struct mystack *s,char *c)
 {
    if (isempty1(s)) {
    return 0;
   } else {
    *c=s->arr[s->top];
    s->top=s->top-1;
    return 1;
   }

}

 int peek1(struct mystack *s,char *c)
 {
  if(isempty1(s))
   return 0;
  else
   {
    *c=s->arr[s->top];
    return 1;
   }
 }

void main()
 {
 char str[100];char post[100];  int i=0;int j=0;char temp='\0';
  struct mystack s;
  s.top=-1;
	      clrscr();
  printf("\n Enter the infix string :");
 scanf("%s", str);

 while(str[i]!='\0')
  {
   if(isOperand(str[i])==1)
    {
     post[j++]=str[i];
    }
   else if(str[i]=='(')
    {
     push1(&s,str[i]);
    }
   else if(str[i]==')')
    {
      pop1(&s,&temp);
     while(temp!='('&&isempty1(&s)!=1)
      {
       post[j++]=temp;
       pop1(&s,&temp);
      }
    }
   else
    {
     peek1(&s,&temp);
     while(isempty1(&s)!=1 && priority(str[i])<=priority(temp))
      {
       pop1(&s,&temp);
	post[j++]=temp;
	peek1(&s,&temp);
      }
     push1(&s,str[i]);
    }
    i=i+1;
  }
  while(isempty1(&s)!=1)
   {
    pop1(&s,&temp);
    post[j++]=temp;
   }

  printf("\nthe postfix string is :%s",post);
   getch();
}

 int isOperand(char c)
  {
   if(c=='+'||c=='-'||c=='*'||c=='/'||c=='('||c==')')
   return 0;
   else
   return 1;
  }

 int priority(char c)
  {
   if(c=='+'||c=='-')
   return 1;
   else if(c=='*'||c=='/')
   return 2;
   else
   return 0;
  }
