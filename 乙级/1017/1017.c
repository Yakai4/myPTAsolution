#include <stdio.h>
#include <string.h>

int main()
{
    int B=0;
    int t[1000] = {};
    unsigned char s[1000]={};
    scanf("%s %d",s,&B);
    int len_s = strlen(s);
    //while(B==9);
    //while(len_s==23);
    int first=0;
    if(len_s > 1)
    {
        for(int i=1;i<len_s;i++) {
                while(s[i-1]-'0'>=B) {
                  s[i-1] -= B; 
                  t[i-1]++;
                }
                s[i] += 10*(s[i-1]-'0');
                s[i-1] = '0';
                first=i;
        }
        if(s[len_s-2] != '0') {
           s[len_s-1] +=10*(s[len_s-2]-'0');
           s[len_s-2] = '0';
        }
        while(s[len_s-1]-'0'>=B) {
            s[len_s-1] -= B;
            t[len_s-1]++;
        }
    } else {
        t[0]=(s[0]-'0')/B;
        s[0]-=t[0]*B;
    }

    for(int i=0;i<len_s;++i)
        if(t[i]!=0) {first=i;break;}
    for(int i=first;i<len_s;++i)
        printf("%d",t[i]);
    printf(" %d",s[len_s-1]-'0');

    return 0;
}