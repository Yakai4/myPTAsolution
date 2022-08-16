#include <stdio.h>

int main(void)
{
    int letter[6]={}, total = 0;
    char STRING[] = {'S','t','r','i','n','g'};
    char ch;
    while(scanf("%c", &ch)!=EOF) {//only Linux would return EOF as end
        switch(ch) {
            case 'S':
                letter[0]++;
                break;
            case 't':
                letter[1]++;
                break;
            case 'r':
                letter[2]++;
                break;
            case 'i':
                letter[3]++;
                break;
            case 'n':
                letter[4]++;
                break;
            case 'g':
                letter[5]++;
                break;
            default:
                break;
        }
    }
    for(int i=0;i<6;i++) 
        total += letter[i];
    for(int i=0, j=0; i<total; j++)
        if(letter[j%6]-->0) {
            printf("%c", STRING[j%6]);
            i++;
        }
    return 0;
}