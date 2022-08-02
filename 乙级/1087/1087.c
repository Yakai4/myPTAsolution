#include <stdio.h>
#define MAXSIZE 12834
int main(void)
{
    int n,Set[MAXSIZE]={};
    scanf("%d", &n);
    int temp=n;
    for(int i=1;i<=n;i++)
        Set[i/2+i/3+i/4+i/5]++;
    for(int i=1;i<=n;i++)
        if(Set[i/2+i/3+i/4+i/5]-->1)
            temp--;
    printf("%d", temp);
}