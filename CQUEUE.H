#define SIZE 6
struct cqueue
 {
  char arr[SIZE];
  int front;
  int rear;
 };
 int isMyEmpty(struct cqueue *);
 int isMyFull(struct cqueue *);
 int myEnqueue(struct cqueue *,char );
 int myDequeue(struct cqueue *,char *);
 int getFront(struct cqueue *,char *);
 int getRear(struct cqueue *,char *);



