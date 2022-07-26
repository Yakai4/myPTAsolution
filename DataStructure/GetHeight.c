#include <stdio.h>
#include <stdlib.h>
typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
}; 
BinTree CreateBinTree();
BinTree CreateBinTree2();
int GetHeight(BinTree);
int TrackD1(BinTree);
int TrackD2(BinTree);
int TrackD0(BinTree);
void PreOrdAdd(BinTree, char**);
void PreOrdVisit(BinTree);
void RemoveLeaf(BinTree);
void Del_0(BinTree);//a wrong example..pit!
void Del_1(BinTree);//PostOrd.wrong example 2.. rm all non-root node. rm -r -f and run..
void Del_2(BinTree);//MidOrd. also wrong
char PreOrdSerial[]={'A','B','D','F','E','C','G','H','I'};

int main(void)
{
    char* pre = PreOrdSerial;
    BinTree BT = CreateBinTree();
	BT = CreateBinTree2();
    //PreOrdAdd(BT,&pre);
    printf("\n%d\n", TrackD1(BT));
    printf("%d\n", TrackD2(BT));
    printf("%d\n", TrackD0(BT));
    PreOrdVisit(BT);
    printf("\n");
    //RemoveLeaf(BT);
	//Del_0(BT);
	//Del_1(BT);
	Del_2(BT);
    printf("\n");
 	PreOrdVisit(BT);
    printf("\n");
    return 0;
}

BinTree CreateBinTree()
{
    BinTree head = malloc(sizeof(struct TNode));
    head->Left = malloc(sizeof(struct TNode));
    head->Left->Left = malloc(sizeof(struct TNode));
    head->Left->Left->Left = NULL;
    head->Left->Left->Right = NULL;

    head->Left->Right = malloc(sizeof(struct TNode));
    head->Left->Right->Left = malloc(sizeof(struct TNode));
    head->Left->Right->Right = NULL;

    head->Right = malloc(sizeof(struct TNode));
    head->Right->Left = malloc(sizeof(struct TNode));
    head->Right->Left->Left = NULL;
    head->Right->Left->Right = malloc(sizeof(struct TNode));
    head->Right->Right = malloc(sizeof(struct TNode));
    head->Right->Right->Right = NULL;
    head->Right->Right->Left = NULL;
    return head;
}
int GetHeight(BinTree BT)
{
    if(BT!=NULL){
        int a = GetHeight(BT->Left);
        int b = GetHeight(BT->Right);
        return (a>b) ? a+1:b+1;
    } else 
        return 0;
}

int TrackD1(BinTree BT)
{
    if(BT!=NULL)
    {
        int D = 0;
        if(BT->Left!=NULL && BT->Right == NULL) D = 1;
        if(BT->Left==NULL && BT->Right != NULL) D = 1;
        return D + TrackD1(BT->Left) + TrackD1(BT->Right);
    } else 
        return 0;
}

int TrackD2(BinTree BT)
{
    if(BT!=NULL)
    {
        int D = 0;
        if(BT->Left!=NULL && BT->Right != NULL) D=1;
        return D + TrackD2(BT->Left) + TrackD2(BT->Right);
    } else 
        return 0;
}

int TrackD0(BinTree BT)
{
    if(BT!=NULL)
    {
        int D = 0;
        if(BT->Left == NULL && BT->Right == NULL) D=1;
        return D + TrackD0(BT->Left) + TrackD0(BT->Right);
    } else
        return 0;
}

void RemoveLeaf(BinTree BT)
{
    if(BT!=NULL)
    {
        if(BT->Left==NULL && BT->Right==NULL){  //if self is leaf
            free(BT);
            return;
        } else {
            if(BT->Left==NULL)  ;//do nothing
            else if(BT->Left->Left==NULL && BT->Left->Right == NULL){    //if lchild is leaf
                free(BT->Left);
                BT->Left=NULL;
            } 
            if(BT->Right==NULL) return;
            else if(BT->Right->Left==NULL && BT->Right->Right == NULL){   //if rchild is leaf
                free(BT->Right);
                BT->Right=NULL;
            }
        }
        RemoveLeaf(BT->Left);
        RemoveLeaf(BT->Right);
    }
}

void PreOrdAdd(BinTree BT, char** p)
{
    if(BT!=NULL)
    {
        BT->Data = *(*p);
        (*p)++;
        PreOrdAdd(BT->Left,p);
        PreOrdAdd(BT->Right,p);
    }
}

void PreOrdVisit(BinTree BT)
{
    if(BT!=NULL)
    {
        printf("%c", BT->Data);
        PreOrdVisit(BT->Left);
        PreOrdVisit(BT->Right);
    }
}
//wrong example:
void Del_0(BinTree BT)
{
	BinTree p = BT;
	if((p->Left==NULL && p->Right==NULL)|| p==NULL){
		free(p);
		return;
	} else if(p->Left->Left==NULL && p->Left->Right==NULL){
		free(p->Left);
		p->Left=NULL;
	} else if(p->Right->Left == NULL && p->Right == NULL){
		free(p->Right);
		p->Right=NULL;
	}
	Del_0(BT->Left);
	Del_0(BT->Right);
}
//wrong example 2
void Del_1(BinTree BT)
{
	if(BT!=NULL)
    {
		Del_1(BT->Left);
    	Del_1(BT->Right);
        if(BT->Left==NULL && BT->Right==NULL){  //if self is leaf
            return;
        } else {
            if(BT->Left==NULL)  ;//do nothing
            else if(BT->Left->Left==NULL && BT->Left->Right == NULL){    //if lchild is leaf
                free(BT->Left);
                BT->Left=NULL;
            } 
            if(BT->Right==NULL) return;
            else if(BT->Right->Left==NULL && BT->Right->Right == NULL){   //if rchild is leaf
                free(BT->Right);
                BT->Right=NULL;
            }
        }
    }
}

void Del_2(BinTree BT)
{
	if(BT!=NULL)
	{
		Del_2(BT->Left);
		if(BT->Left==NULL && BT->Right==NULL){  //if self is leaf
            return;
        } else {
            if(BT->Left==NULL)  ;//do nothing
            else if(BT->Left->Left==NULL && BT->Left->Right == NULL){    //if lchild is leaf
                free(BT->Left);
                BT->Left=NULL;
            } 
            if(BT->Right==NULL) return;
            else if(BT->Right->Left==NULL && BT->Right->Right == NULL){   //if rchild is leaf
                free(BT->Right);
                BT->Right=NULL;
            }
        }
		Del_2(BT->Right);

	}
}

BinTree CreateBinTree2()
{
    BinTree head = malloc(sizeof(struct TNode));
	head->Data = 'A';
    head->Left = malloc(sizeof(struct TNode));
	head->Left->Data = 'B';
    head->Left->Left = malloc(sizeof(struct TNode));
	head->Left->Left->Data = 'D';
    head->Left->Left->Left = malloc(sizeof(struct TNode));
	head->Left->Left->Left->Data = 'J';
    head->Left->Left->Right = malloc(sizeof(struct TNode));
	head->Left->Left->Right->Data = 'K';

    head->Left->Right = malloc(sizeof(struct TNode));
	head->Left->Right->Data = 'F';
    head->Left->Right->Left = malloc(sizeof(struct TNode));
	head->Left->Right->Left->Data = 'E';
    head->Left->Right->Right = malloc(sizeof(struct TNode));
	head->Left->Right->Right->Data = 'L';

    head->Right = malloc(sizeof(struct TNode));
	head->Right->Data = 'C';
    head->Right->Left = malloc(sizeof(struct TNode));
	head->Right->Left->Data = 'G';
    head->Right->Left->Left = malloc(sizeof(struct TNode));
	head->Right->Left->Left->Data = 'M';
    head->Right->Left->Right = malloc(sizeof(struct TNode));
	head->Right->Left->Right->Data = 'H';
    head->Right->Right = malloc(sizeof(struct TNode));
	head->Right->Right->Data = 'I';
    head->Right->Right->Right = malloc(sizeof(struct TNode));
	head->Right->Right->Right->Data = 'O';
    head->Right->Right->Left = malloc(sizeof(struct TNode));
	head->Right->Right->Left->Data = 'N';
    return head;
}