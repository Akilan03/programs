#define SIZE 100
struct twostack {
char arr[SIZE];
int top1,top2;
};
int push1(struct twostack*,char );
int push2(struct twostack*,char );
int pop1(struct twostack*,char*);
int pop2(struct twostack*,char*);
int peek1(struct twostack*,char*);
int peek2(struct twostack*,char*);
int isempty1(struct twostack*);
int isempty2(struct twostack*);
int isfull1(struct twostack*);




