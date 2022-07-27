#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 1000000007

int main(void)
{
    int count_p=0, count_pa=0, count_pat=0;
    char x = getchar();
    while(x != '\n'){
        if (x == 'P') {
            count_p++;
        } else if (x == 'A' ) {
            count_pa+=count_p;
        } else if (x == 'T') {
            count_pat+=count_pa;
        }
        if (count_p >= MAXNUM)
            count_p -= MAXNUM;
        if (count_pa >= MAXNUM)
            count_pa -= MAXNUM;
        if (count_pat >= MAXNUM)
            count_pat -= MAXNUM;
        x = getchar();
    }
    printf("%d\n", count_pat);
    return 0;
}