#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char A[10],B[10];
    int Da, Db;
    long Ra=0, Rb=0;
    scanf("%s %d %s %d", A, &Da, B, &Db);
    //printf("%ld\n",strlen(A));
    for(int i=0;i<strlen(A);i++)    
    {
        if(A[i] == Da+'0')  Ra = 10*(Ra+Da);  
    }
    for(int i=0;i<strlen(B);i++)
    {
        if(B[i] == Db+'0')  Rb = 10*(Rb+Db);
    }
    printf("%ld\n",Ra/10+Rb/10);
    return 0;
}
//999999999