#define SIZE 100
struct myqueue
 {
  char arr[SIZE];
  int front;
  int rear;
 };
 int isMyEmpty(struct myqueue *);
 int isMyFull(struct myqueue *);
 int myEnqueue(struct myqueue *,char );
 int myDequeue(struct myqueue *,char *);
 int getFront(struct myqueue *,char *);
 int getRear(struct myqueue *,char *);
