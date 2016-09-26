#include<stdio.h>
#include<conio.h>

struct node
 {
  int data;
  struct node *next;
 };

int searchnode(struct node *,int ,struct node ** );
int insertnode(struct node **,int);
int traversenode(struct node *);
int deletenode(struct node **,int);