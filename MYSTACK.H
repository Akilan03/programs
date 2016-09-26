#define SIZE 100
struct mystack {
char arr[SIZE];
int top;
};
int push1(struct mystack*s,char c);
int pop1(struct mystack*s,char*c);
int peek1(struct mystack*s,char*c);
int isempty1(struct mystack*s);
int isfull1(struct mystack*s);

