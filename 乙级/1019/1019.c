#include <stdio.h>
#define Kaprekar 6174
int abs(int);

int main(void)
{
    int cnt[10]={};char c;scanf("%c", &c);
    for(int i=0;c!='\n';i++,scanf("%c",&c))
        cnt[c-'0']++;
    int min=0,max=0,t;
    while(1){
        for(int i=9,j=4;j>0 && i>=0;i--) {
            while(cnt[i] > 0) {
                max = 10*max + i;
                cnt[i]--;
                j--;
            }
            while(i==0 && j>0)  {max*=10;j--;}
        }
        for(int i=0,temp=max;i<4;i++){
            min = 10*min + temp%10;
            temp = temp/10;
        }
        if(max-min<0) {
            max = min + max;
            min = max - min;
            max = max - min;
        }
        t = max -min;
        printf("%04d - %04d = %04d\n", max, min, t);
        if(t==Kaprekar || t==0) break;
        max=0;min=0;
        for(int i=0;i<4;i++) {
            cnt[abs(t%10)]++;
            t = t/10;
        }
    }
}

int abs(int a) {
    return a>0 ? a : -1*a;
}