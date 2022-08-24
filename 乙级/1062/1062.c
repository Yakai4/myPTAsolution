#include <stdio.h>
int gcd0(int, int);
int gcd1(int, int);
void swap(int *a, int *b) {
    int *temp;
    *temp = *a;
    *a = *b;
    *b = *temp;
}

int main(void) 
{
    int N1,M1,N2,M2,K;    scanf("%d/%d %d/%d %d", &N1, &M1,&N2,&M2,&K);
    if(N1*M2>N2*M1) {
        swap(&N1,&N2);
        swap(&M1,&M2);
    }
    //assume that N1/M1 < N2/M2. i/K
    int i=1;
        for(;;i++) {
            if( i*M1 > N1*K && i*M2 < N2*K && gcd0(i,K) == 1){
                printf("%d/%d", i,K);
                break;
            }
        }
    i++;
         for(;i<K;i++) {
            if( i*M1 > N1*K && i*M2 < N2*K && gcd0(i,K) == 1){
                printf(" %d/%d", i,K);
            }
        }

    printf("\n");
    return 0;
}

int gcd0(int a, int b) {
    while(a!=b) {
        while(a>b)
            a -=b;
        while(b>a)
            b -=a; 
    }
    return a;
}
int gcd1(int a,int b) {
    if(a==b)
        return a;
    if(a>b)
        return gcd(a-b,b);
    if(a<b)
        return gcd(b-a,a);
}

