/** it has benn accepted
 *  final version
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct question {
    int fullMark;
    int corretOpt;
    char ans[6];
};

int main(void) {
    int N,M;    scanf("%d %d", &N, &M);
    struct question* Questions = (struct question*) malloc(M*sizeof(struct question));
    int cnt[101]={},waste;
    for(int i=0;i<M;i++) {
        scanf("%d %d %d", &Questions[i].fullMark, &waste, &Questions[i].corretOpt);
        for(int j=0;j<Questions[i].corretOpt;j++)
            scanf(" %c", &Questions[i].ans[j]);
		Questions[i].ans[Questions[i].corretOpt] = '\0';
    }
int  k,t,score; char x, ansChar[6];
    for(int i=0;i<N;i++) {
		k=0; score = 0; t=0;
		x = getchar(); x= getchar();
        while(k < M) {
			x = getchar();
            if( (int)(x-'0') == Questions[k].corretOpt) {
                while(x!=')') {
                   if(x<='z' && x>='a') 
                        ansChar[t++] = x;
                  	x = getchar();
                }
				ansChar[t] = '\0';
				t=0;
            	if(strcmp(ansChar, Questions[k].ans) != 0) 	
					cnt[k]++;
				else 
					score += Questions[k].fullMark;
            } else {
				cnt[k]++;
				while(x!=')')
					x = getchar();
			}
			k++;
			while(k<M && x!='(')
				x = getchar();
        }
		printf("%d\n",score);
    }
    int max = 0;
    for(int i=0;i<100;i++)
        if(max < cnt[i])
            max = cnt[i];
    if(max == 0)
        printf("Too simple");
    else { 
        printf("%d", max);
        for(int i=0;i<100;i++) 
            if(cnt[i] == max)
                printf(" %d", i+1);
        
    }
    printf("\n");
	return 0;
}
