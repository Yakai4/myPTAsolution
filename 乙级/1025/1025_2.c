/*
该版本通过所有测试点。内存占用40788KB，平均用时65ms
*/
#define MAX 100000
#include <stdio.h>
#include <stdlib.h>
//class stack
    typedef struct {
        int *data;
        int top;
    } Stack;
    void init(Stack *S, int size) {
        S->top = -1;
		S->data = (int*) malloc(sizeof(int) * size);
    }
    void push(Stack *S,int num) {
        S->data[++S->top] = num;
    }
    int pop(Stack *S) {    
        return S->data[S->top--];
    }
//end of class stack

struct node {
    int data,next;
};
int main() {
    struct node a[MAX];
    int beginAddr, N, K;
    scanf("%d %d %d", &beginAddr, &N, &K);
    int ind, data,next;
    for(int i=0;i<N;i++) 
    {
        scanf("%d %d %d", &ind,&data,&next);
        a[ind].data =data;
        a[ind].next =next;
    }

    int valid=0;
    ind = beginAddr;
    Stack S;init(&S, N);   

    while(ind!=-1) {
        push(&S,ind);
        ind = a[ind].next;
        valid++;
    }   

    int div = valid/K, mod = valid%K;
    Stack Stks[div],R;
    for(int i=0;i<div;i++)
        init(&Stks[i], div);
    if(mod != 0) {
        init(&R, mod);
        for(int i=0;i<mod;i++)
            push(&R, pop(&S));
    }
    
    for(int i=div-1;i>=0;i--) {
        for(int j=0;j<K;j++)
            push(&Stks[i],pop(&S));
    }

    for(int i=0;i<mod;i++)
        push(&S, R.data[i]);

    for(int i=div-1;i>=0;i--) {
        for(int j=0;j<K;j++)
            push(&S,pop(&Stks[i]));
    }

    for(int i=valid-1;i>0;i--) {
        //a[S.data[i]].next = pop(&S);
        printf("%05d %d %05d\n", S.data[i], a[S.data[i]].data, S.data[i-1]);
    }
    printf("%05d %d %d\n", S.data[0], a[S.data[0]].data, -1);
    return 0;
}

/*
00100 6 3
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
*/