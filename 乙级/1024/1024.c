#include <stdio.h>
#include <string.h>
#define MAXSIZE 10010

int main(void)
{
    char num[MAXSIZE];
    char sign_exp;
    int num_exp;
    memset(num, '0', MAXSIZE*sizeof(char));
    num[0] = getchar();
    int k=1 ,flag;
    num[1] = getchar();
    while(num[k]<='9' && num[k]>='0' || num[k] == '.') {//until encounter 'E'
        if(num[k] == '.')   flag = k;
        num[++k] = getchar();
    }
    num[k]='0';
    sign_exp = getchar();
    scanf("%d", &num_exp);
    //printf("num_exp: %d\n", num_exp);
    if(num[0] == '-')   printf("-");//exclude a situation that every digit is zero.
    if(num_exp == 0) {
        for(int i=1; i<k; i++) 
            printf("%c", num[i]);
    } else {
        if(sign_exp == '+') {
            for(int i=flag; i<flag+num_exp; i++)
                num[i] = num[i+1];
            num[flag+num_exp] = '.';
            for(int i=1, j=0; i<flag+num_exp; i++)//print part before the dot
                if(num[i] != '0' || j ==1)   {printf("%c", num[i]);j=1;}
                else if(i == flag+num_exp-1) {//num[i]=='0' && j ==0 && num[i+1] == '.'
                    printf("0");
                }
            if(flag+num_exp+1 < k)  printf(".");
            for(int i = flag+num_exp+1; i < k; i++) // print part after '.'
                printf("%c", num[i]);
        } else {
            printf("0.");
            for(int i=1; i<num_exp; i++)
                printf("0");
            for(int i=1; i < k; i++) 
                if(num[i]!='.')
                    printf("%c", num[i]);
        }
    }
    return 0;
}