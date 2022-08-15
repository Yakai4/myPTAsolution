#include <stdio.h>
#include <stdlib.h>

struct stu {
    char* test_id;
    int jishi;
    int kaoshi;
};
//	把第二个结构体复制给第一个
void cpy(struct stu*, struct stu*);
void my_qsort(struct stu*, int ,int);

int main(void)
{
    int N;  scanf("%d", &N);
    struct stu S[N];
    for(int i=0;i<N;i++) {
        S[i].test_id = (char*) malloc(17*sizeof(char));
        scanf("%s %d %d", S[i].test_id, &S[i].jishi, &S[i].kaoshi);
    }
    int M;  scanf("%d", &M);
    int num;
    my_qsort(S,0,N-1);
    for(int i=0;i<M;i++) {
        scanf("%d", &num);
        num--;
        printf("%s %d\n", S[num].test_id, S[num].kaoshi);
    }
    return 0;
}

void my_qsort(struct stu* S,  int head, int tail) {
    if(head<tail) {
        int i=head, j=tail;	struct stu x=S[i];
        while(i<j) {
            while(i<j && S[j].jishi > x.jishi)    j--;
            if(i<j) cpy(&S[i++], &S[j]);
            while(i<j && S[i].jishi < x.jishi)    i++;
            if(i<j) cpy(&S[j--], &S[i]);
        }
        cpy(&S[i], &x);
        my_qsort(S, head, i-1);
        my_qsort(S, i+1, tail);
    }
}

void cpy(struct stu* S1, struct stu* S2) {
    S1->test_id = S2->test_id;
    S1->jishi   = S2->jishi;
    S1->kaoshi  = S2->kaoshi;
}