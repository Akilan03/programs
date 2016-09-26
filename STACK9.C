#include <stack9.h>
#include <stdio.h>
#include <conio.h>


int isemptyAkil(struct mystack *s) {
    if (s->top==1)
    return 1;
else
    return 0;
}
int isfullAkil(struct mystack *s) {
    if (s->top==SIZE-1)
    return 1;
else
    return 0;
}

int pushAkil(struct mystack *s,char c) {
    if (isfullAkil(s)) {
    return 0;
} else {
    s->top=s->top+1;
    s->arr[s->top]=c;
    return 1;
   }
}

int peekAkil(struct mystack *s,char *c)
 {
  if(s->top==-1)
   return 0;
  else
   {
    *c=s->arr[s->top];
    return 1;
   }
 }
int popAkil(struct mystack *s,char *c) {
    if (isemptyAkil(s)) {
    return 0;
   } else {
    *c=s->arr[s->top];
    s->top=s->top-1;
    return 1;
   }
}






