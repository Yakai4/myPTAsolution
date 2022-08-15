#include <stdio.h>

int main(void)
{
    int N,M;    scanf("%d %d", &N, &M);
    int G1,G2=0,min=M,max=0, score, valid=0;
    for(int i=0;i<N;i++) {
        scanf("%d", &G1);
        for(int j=0;j<N-1;j++){
            scanf("%d", &score);
            if (score>=0 && score <= M) {
                valid++;
                G2+=score;
                if (min > score)  min = score;
                if (max < score)  max = score;
            }
        }
        valid-=2;
        G2 -= min+max;
        double g2 =(G2*1.0)/valid;
        double g1 = (1.0*G1);
        printf("%0.lf\n", (g1+g2)/2.0+0.0005);//大于0.5进位，小于等于0.5舍入
        G1=0;G2=0;valid=0;min=M;max =0;
    }
    return 0;
}