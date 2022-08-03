#include <stdio.h>
#include <stdlib.h>
void my_qsort(int* num, int head, int tail);
int main(void) 
{
    int N;
    scanf("%d", &N);
    int * num = malloc(N*sizeof(int));
    for(int i=0;i<N;i++)
        scanf("%d", &num[i]);
    my_qsort(num, 0, N-1);
    for(int i=0;i<N;i++)
        printf("%d ", num[i]);
        //num[i] = (num[i-1] + num[i]) / 2; 
    printf("%d", num[N-1]);
    free(num);
    return 0;
}
void my_qsort(int* num, int head, int tail) {
    if(head<tail) {
        int i=head,j=tail,x=num[head];
        while(i<j) {
            while(i<j&& x <= num[j]) j--;
            if(i<j) num[i++] = num[j];
            while(i<j&& x > num[i])  i++;
            if(i<j) num[j--] = num[i];
        }
        num[i] = x;
        my_qsort(num, head, i-1);
        my_qsort(num, i+1, tail);
    }
}