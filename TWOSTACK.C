#include <twostack.h>
#include <stdio.h>
#include <conio.h>

int isempty1 (struct twostack*s) {
    if (s->top1==-1)
    return 1;
else
    return 0;
}
int isempty2 (struct twostack*s) {
    if (s->top2==SIZE)
    return 1;
else
    return 0;
}

int isfull (struct twostack*s) {
    if (s->top1==(s->top2-1))
    return 1;
else
    return 0;
}

int push1(struct twostack*s,char c) {
    if (isfull(s)) {
    return 0;
} else {
   s->top1=s->top1+1;
   s->arr[s->top1]=c;
   return 1;
   }
}
int push2(struct twostack*s,char c) {
    if (isfull(s)) {
    return 0;
} else {
   s->top2=s->top2-1;
   s->arr[s->top2]=c;
   return 1;
   }
}

int pop1(struct twostack*s,char*c) {
    if (isempty1(s)) {
    return 0;
} else {
    *c=s->arr[s->top1];
    s->top1=s->top1-1;
    return 1;
  }
}
int pop2(struct twostack*s,char*c) {
    if (isempty2(s)) {
    return 0;
} else {
    *c=s->arr[s->top2];
    s->top2=s->top2+1;
    return 1;
  }
}

int peek1(struct twostack*s,char*c) {
    if (isempty1(s)) {
    return 0;
} else {
    *c=s->arr[s->top1];
    return 1;
   }
}

int peek2(struct twostack*s,char*c) {
    if (isempty2(s)) {
    return 0;
} else {
    *c=s->arr[s->top2];
    return 1;
   }
}

int main ()  {

       struct twostack s;
       char a[100],b[100];
       char c='\0',d='\0';
       int i=0;
       clrscr();
       printf("\nstack 1:");
       scanf("%s",a);
       printf("\nstack 2:");
       scanf("%s",b);
       s.top1=-1;
       s.top2=SIZE;

       while(a[i]!='\0')
	{
	 push1(&s,a[i]);
	 i++;
	 }
	i=0;
	while(b[i]!='\0')
	{
	 push2(&s,b[i]);
	 i++;
	 }
       peek1(&s,&c);
       printf("\ntop 1 element :%c",c);
       peek2(&s,&d);
       printf("\ntop 2 element :%c",d);
       printf("\nstack 1:");
       while(!isempty1(&s))
       {
	pop1(&s,&c);
	printf("%c",c);
       }
	printf("\nstack 2:");
	while(!isempty2(&s))
       {
	pop2(&s,&d);
	printf("%c",d);
       }

       getch();
       return 0;
}
