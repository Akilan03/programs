#include "mystack.h"
#include <stdio.h>
#include <conio.h>

int isempty1 (struct mystack*s) {
    if (s->top==-1)
    return 1;
else
    return 0;
}
int isfull1 (struct mystack*s) {
    if (s->top==SIZE-1)
    return 1;
else
    return 0;
}

int push1(struct mystack*s,char c) {
    if (isfull1(s)) {
    return 0;
} else {
   s->top=s->top+1;
   s->arr[s->top]=c;
   return 1;
   }
}

int pop1(struct mystack*s,char*c) {
    if (isempty1(s)) {
    return 0;
} else {
    *c=s->arr[s->top];
    s->top=s->top-1;
    return 1;
  }
}

int peek1(struct mystack*s,char*c) {
    if (isempty1(s)) {
    return 0;
} else {
    *c=s->arr[s->top];
    return 1;
   }
}


int main ()  {
       struct mystack s;
       char str[100];
       char c='1';
       s.top=-1;
       push1(&s,'e');
       pop1(&s,&c);
       printf("%c",c);
       getch();
       return 0;
}
