#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STRLEN 6
/*typedef struct LNode{
    char* addr;
    int Data;
    struct LNode* Next;
}*/
int main(void)
{
    char* initAddr = (char*) malloc(STRLEN*sizeof(char));
    int N,K,head;
    scanf("%s %d %d", initAddr, &N, &K);
    char* Addr = (char*) malloc(N*STRLEN*sizeof(char));
    int * Data = (int* ) malloc(N*sizeof(int));
    char* Next = (char*) malloc(N*STRLEN*sizeof(char));
    int*  logicalNext = (int* ) calloc(N, sizeof(int));
    for(int i=0;i<N;i++) {
        scanf("%s %d %s", &Addr[STRLEN*i], &Data[i], &Next[STRLEN*i]);
        if(strcmp(initAddr, &Addr[STRLEN*i]) == 0)   head = i;
    }
    printf("head is %d\n", head);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if (strcmp(&Addr[STRLEN*i],&Next[STRLEN*j])==0)
                logicalNext[j] = i;
    int * stk = (int* ) malloc(K*sizeof(int));
    int top =0, tail =head;
    while(top < K) {
        stk[top++] = head;
        head = logicalNext[head];
    }
    int newHead = stk[--top];
    logicalNext[tail] = logicalNext[newHead];
    strcpy(&Next[STRLEN * tail], &Addr[STRLEN * logicalNext[tail]]);
    while(top>0) {
        logicalNext[head] = stk[--top];
        strcpy(&Next[STRLEN * head], &Addr[STRLEN * logicalNext[head]]);
        head = logicalNext[head];
    }
    for(int i=0, j=newHead;i<N;i++) {
        printf("%s %d %s\n", &Addr[STRLEN*j], Data[j], &Next[STRLEN*j]);
        j = logicalNext[j];
    }
    /*while( strcmp("-1", &Next[STRLEN*head]) !=0 ) {
        printf("%s %d %s\n", &Addr[STRLEN*head], Data[head], &Next[STRLEN*head]);
        head = logicalNext[head];
    }*/
    printf("%s %d %s\n", &Addr[STRLEN*head], Data[head], &Next[STRLEN*head]);
    return 0;
}

