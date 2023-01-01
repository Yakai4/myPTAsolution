/**
 * 3636KB 41ms
*/
#define MAX 100000
#include <stdio.h>
#include <stdlib.h>
//class simple stack
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
    for(int i=0;i<N;i++) {
        scanf("%d %d %d", &ind,&data,&next);
        a[ind].data =data;
        a[ind].next =next;
    }

    int positive=0,negetive=0,gk=0,valid=0;
    ind = beginAddr;
    Stack S;init(&S, N);   

    while(ind!=-1) {
        push(&S,ind);
        ind = a[ind].next;
        valid++;
    }   
    for(int i=0;i<=S.top;i++) {
        ind = S.data[i];
        if(a[ind].data>K)
			gk++;
		else if(a[ind].data<0)	
			negetive++;
		else 
			positive++;
    }

    Stack Positive_S, Negetive_S,GreaterK_S;
    init(&Positive_S, positive);init(&Negetive_S,negetive);init(&GreaterK_S,gk);

	for(int i=0;i<valid;i++) {
		ind = pop(&S);
		if(a[ind].data<0)
			push(&Negetive_S,ind);
		else if(a[ind].data<=K)
			push(&Positive_S,ind);
		else 
			push(&GreaterK_S,ind);
    }
	
	for(int i=0;i<gk;i++) 
		push(&S,GreaterK_S.data[i]);

	for(int i=0;i<positive;i++)
		push(&S, Positive_S.data[i]);
	
	for(int i=0;i<negetive;i++) {
		push(&S,Negetive_S.data[i]);
	}
    for(int i=valid-1;i>0;i--) {
        printf("%05d %d %05d\n", S.data[i], a[S.data[i]].data, S.data[i-1]);
    }
    printf("%05d %d %d\n", S.data[0], a[S.data[0]].data, -1);

    return 0;
}
