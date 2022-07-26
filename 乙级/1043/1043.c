#include <stdio.h>

int main(void)
{
    int i=0, other=0;
    int count[6]={};
    char ch[10001];
    scanf("%s",ch);
    while(ch[i]!='\0'){
        if(ch[i]=='P')  count[0]++;
        else if(ch[i]=='A')  count[1]++;
        else if(ch[i]=='T')  count[2]++;
        else if(ch[i]=='e')  count[3]++;
        else if(ch[i]=='s')  count[4]++;
        else if(ch[i]=='t')  count[5]++;
        else other++;
        i++;
    }
    int sum=0;
    for(int k=0;k<6;k++)
        sum+=count[k];
    //printf("%d and %d\n",sum, i-other);
    for(int k=0 ;i-other>0;k++)
    {
        if(count[k%6] != 0) { 
            count[k%6]--;
            if(k%6==0)  printf("P");
            if(k%6==1)  printf("A");
            if(k%6==2)  printf("T");
            if(k%6==3)  printf("e");
            if(k%6==4)  printf("s");
            if(k%6==5)  printf("t");
            i--;
        }
    }
    return 0;
}