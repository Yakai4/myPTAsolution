#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 6
struct queue{
    int data[MAXSIZE];
    int front, rear;
};
struct queue* initQueue();
int enQueue(struct queue*, int);
int deQueue(struct queue*);
int isFull(struct queue*);
int isEmpty(struct queue*);

int main(int argc, char const *argv[])
{
    int num[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,15,16,17,18,19,20};
    struct queue* Q = initQueue();
    printf("enQueueing!...\n");
    for(int i=0;i<20;++i){
        enQueue(Q,num[i]);
        printf("deQ->%d ;",deQueue(Q));
    }

    return 0;
}

struct queue* initQueue()
{
    struct queue* Q = malloc(sizeof(struct queue));
    Q->front = 0;
    Q->rear = -1;
    return Q;
}

int enQueue(struct queue* Q, int num)
{
    if(isFull(Q))   return 0;
    Q->data[++(Q->rear)] = num;  
    if(Q->rear+1 >= MAXSIZE)  Q->rear -= MAXSIZE;//rear=-1
    return 1;
}

int deQueue(struct queue* Q)
{
    if(isEmpty(Q))  return 0;
    int ret = Q->data[(Q->front)++];
    if(Q->front >= MAXSIZE) Q->front -= MAXSIZE;
    return ret;
}

int isFull(struct queue* Q)
{
    if(((Q->rear)+2) % MAXSIZE == Q->front)  return 1;
    return 0;
}

int isEmpty(struct queue* Q)
{
    if(((Q->rear)+1) % MAXSIZE == Q->front)  return 1;
    return 0;
}