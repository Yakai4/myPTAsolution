#include <stdio.h>
#include <string.h>

int isPrime(int x)
{
    if(x<2) return 0;
    for(int i=2;i*i<=x;i++)
    {
        if(x % i ==0)    return 0;
    }
    return 1;
}
int main(void)
{
    int N;
    scanf("%d",&N);
    if(isPrime(N)&&(isPrime(N-6)||isPrime(N+6)))
    {
        printf("Yes\n");
        if(isPrime(N-6))    printf("%d",N-6);
        else    printf("%d",N+6);
    } else {
        printf("No\n");
        for(N++;!(isPrime(N)&&(isPrime(N-6)||isPrime(N+6)));N++);
        printf("%d",N);
    }
    return 0;
}
