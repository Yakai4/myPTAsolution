/** first version
 *  failed in test point 3 dont know why.
*/
#include <stdio.h>
#include <stdlib.h>

struct question {
    int fullMark;
    int options;
    int corretOpt;
    char ans[5];
};
struct answerStu {
    int quantity;
    char* ansStu;
};
void judge(struct answerStu*, struct question*, int[], int);

int main(void) {
    int N,M;    scanf("%d %d", &N, &M);
    struct question* Questions = (struct question*) malloc(M*sizeof(struct question));
    struct answerStu* Answers = (struct answerStu*) malloc(M*sizeof(struct answerStu));
    for(int i=0;i<M;i++) {
        scanf("%d %d %d", &Questions[i].fullMark, &Questions[i].options, &Questions[i].corretOpt);
        for(int j=0;j<Questions[i].corretOpt;j++)
            scanf(" %c", &Questions[i].ans[j]);
    }
int  k=0, score = 0; char x;
int cnt[101]={};
for(int i=0;i<N;i++) {
    x = getchar(); x = getchar();//read "\n("
    while(k<M) {
            scanf("%d", &Answers[k].quantity);
            Answers[k].ansStu = (char*) malloc(Answers[k].quantity*sizeof(char));
            for(int j=0;j<Answers[k].quantity;j++) {
                scanf(" %c", &x);
                Answers[k].ansStu[j] = x;
            }
			if (k < M-1) {
            	x = getchar();x = getchar();x = getchar();//read ") ("
			} else {
				x = getchar();x = getchar();//read ")\n"
			}
            k++;
    }
	judge(Answers, Questions, cnt, M);
    k=0;
}
    int max = 0;
    for(int i=0;i<100;i++)
        if(max < cnt[i])
            max = cnt[i];
    if(max == 0)
        printf("Too simple");
    else { 
        printf("%d", max);
        for(int i=0;i<101;i++) 
            if(cnt[i] == max)
                printf(" %d", i+1);
    }
    printf("\n");
	return 0;
}

void judge(struct answerStu* A, struct question* Q, int cnt[],int M) {
	int score = 0, flag;
	for(int i=0;i<M;i++) {
		flag = 1;
		if(A[i].quantity == Q[i].corretOpt) {
			for(int j=0;j<A[i].quantity;j++) 
				if(A[i].ansStu[j]!=Q[i].ans[j]) {
					flag = 0;
					break;
				}
		} else flag = 0;
		if(flag)
            score += Q[i].fullMark;
        else 
            cnt[i]++;
	}
	printf("%d\n", score);
}