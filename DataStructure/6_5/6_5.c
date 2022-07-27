#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

Position Find( List L, ElementType X );
List Insert( List L, ElementType X, Position P );
List Delete( List L, Position P );

int main()
{
    List L;
    ElementType X;
    Position P, tmp;
    int N;

    L = NULL;
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        L = Insert(L, X, L);
        if ( L==ERROR ) printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else {
            L = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if ( L==ERROR )
                printf("Wrong Answer or Empty List.\n");
        }
    }
    L = Insert(L, X, NULL);
    if ( L==ERROR ) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    tmp = Insert(L, X, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    tmp = Delete(L, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    for ( P=L; P; P = P->Next ) printf("%d ", P->Data);
    return 0;
}

/* 你的代码将被嵌在这里 */
Position Find( List L, ElementType X)
{
    while(L!=NULL && L->Data!=X)
        L=L->Next;
    if(L!=NULL)
        return L;
    else
        return ERROR;
}

List Insert( List L, ElementType X, Position P )
{
    if(L == NULL){
        if(P!=NULL){
            printf("Wrong Position for Insertion\n");
            return ERROR;
        }
        L = malloc(sizeof(struct LNode));
        L->Next = NULL;
        L->Data = X;
        return L;
    }
    List Head = L, pre = NULL;
    while(L!=NULL && L!=P){
        pre = L;
        L=L->Next;
    }
        if(L == P){
            List node = malloc(sizeof(struct LNode));
            node->Next = P;
            node->Data = X;
            if(pre == NULL) 
                Head = node;
            else 
                pre->Next = node;
            return Head;
        } else {
            printf("Wrong Position for Insertion\n");
            return ERROR;
        }
}

List Delete( List L, Position P )
{
    if(P == NULL){
        printf("Wrong Position for Deletion\n");
        return ERROR;
    }
    List Head = L, pre = NULL;
    while(L!=NULL && L!=P){
        pre =L;
        L = L->Next;
    }
    if(L==P){
        if(pre==NULL){
            Head = P->Next;
            free(P);
            return Head;
        } else {
            pre->Next = P->Next;
            free(P);
            return Head;
        }
    } else {
        printf("Wrong Position for Deletion\n");
        return ERROR;
    }
}