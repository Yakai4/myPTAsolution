#include <stdio.h>

int main(void)
{
    int N; float e; int D; scanf("%d %f %d", &N, &e, &D);
    int K,poss=0,less,empty=0; float usage;
    for(int i=0;i<N;i++) {
        scanf("%d", &K);
        less  = 0;
        for(int j=0;j<K;j++) {
            scanf("%f", &usage);
            if(usage<e)
                less++;
        }
		
        if(2*less > K){
            poss++;
        }
        if(K>D && 2*less>K) {
            empty++;
            poss--;
        }
    }
    printf("%.1f%% %.1f%%\n", 100.0*poss/N, 100.0*empty/N);
    return 0;
}