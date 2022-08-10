#include <stdio.h>
#include <string.h>
int main(void)
{
    int N, M;   scanf("%d %d", &N, &M);
    char things[M][5];
    for(int i=0;i<M;i++)
        scanf("%s", &things[i][0]);
    //for(int i=0;i<M;i++)
    //   printf("%s ", &things[i][0]);
    char name[5], thing[5];
    int person=0, item=0;
    for(int i=0,k=0, flag=0;i<N;i++) {
        scanf("%s", name);
        while (getchar()!='\n') {//判断到达行末的方法。。
            scanf("%s",thing);
            while (k<M) {
                 if (strcmp(thing,&things[k][0])!=0)
                     k++;
                else {
                    if(flag==0){
                        printf("%s:", name);
                        flag =1;
                        person++;
                    }
                    printf(" %s", thing);
                    item++;
                    break;
                }
            }
            k=0;
        }
        if(flag == 1)
            printf("\n");
        flag =0;
    }
    printf("%d %d", person, item);
    return 0;
}