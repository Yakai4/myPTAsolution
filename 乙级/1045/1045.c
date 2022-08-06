#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N, ans=0;
    scanf("%d",&N);
    int * num = (int*)malloc(N*sizeof(int));
    int * flag = (int*)calloc(N,sizeof(int));
    int * rmin = (int*)calloc(N, sizeof(int));//rmin[i] = minium number @i's right side
    int * lmax = (int*)calloc(N, sizeof(int));
    for(int i=0;i<N;i++)
        scanf("%d", &num[i]);
    lmax[0] = -1; rmin[N-1] = __INT_MAX__;
    for(int i=0, max=0;i<N-1;i++) {    //Update lmax
    if(max < num[i])    max = num[i];
    lmax[i+1] = max;    
    }
    /*for(int i=0;i<N;i++) {
        printf("%d ", lmax[i]);
    }
    printf("\n");*/
    for(int i=N-1, min = __INT_MAX__; i>0;i--) {
        if(min > num[i])    min = num[i];
        rmin[i-1] = min;
    }
    /*for(int i=0;i<N;i++) {
        printf("%d ",rmin[i]);
    }*/
    for(int i=0;i<N;i++) 
        if(num[i] > lmax[i] && num[i] < rmin[i])    ans++;
    printf("%d\n", ans);
    for(int i=0;i<N;i++) {
        if(num[i] > lmax[i] && num[i] < rmin[i]) {
            printf("%d", num[i]);
            ans--;
            if(ans > 0)   printf(" ");
        }
    }
    printf("\n");//?测试点2什么鬼啊啊啊啊
}
