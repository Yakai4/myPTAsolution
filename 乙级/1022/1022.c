#include <stdio.h>
//__INT_MAX__
struct stk {
    int remainder[30];
    int top;
} r_stack;

int main(void)
{
    int A,B,D;
    scanf("%d %d %d", &A, &B,&D);
    int m = A+B;
    if(m==0)    printf("0");
    else {
        int k=0; r_stack.top=0;
        while(m>0) {
            k = m % D;
            r_stack.remainder[r_stack.top++] = k;
            m = m/D;
        }
        while(r_stack.top>0)
            printf("%d",r_stack.remainder[--(r_stack.top)]);
        }
    return 0;   
}