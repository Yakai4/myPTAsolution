//In fact, we can process char array in code of utf-8 or gbk which depends on your text Encoding settings
//only a single char, like char ch ='Z', will be encoded into ascii.
//so let's go here and remake.
#include <stdio.h>
#include <stdlib.h>
//#include <locale.h>
//#include <wchar.h>
#define LENGTH 10
#define WIDTH 20

//read emoji and return actual quantity of chararter
//等价于read(wchar_t (*emoji)[WIDTH]);
int read(char emoji[LENGTH][WIDTH]);

//paint emoji
void paint(int, char(*)[WIDTH]);

int main(void)
{
    //char *locale = setlocale(LC_ALL, "");
    //setlocale(LC_CTYPE,locale);

    char hands[LENGTH][WIDTH],eyes[LENGTH][WIDTH],mouths[LENGTH][WIDTH];
    //char *sup[5] = {hands, eyes, mouths, eyes, hands}; 该怎么写？

	int ret_hands = read(hands);
    int ret_eyes = read(eyes);
    int ret_mouths = read(mouths);
    int k,x[5];    scanf("%d", &k);
    for(int i=0, flag=1;i<k;i++) {
        flag = 1;
        for(int j=0;j<5;j++){
            scanf("%d", &x[j]);
            switch (j) {
            case 0:
            case 4:
                if(x[j]<1 || x[j]>ret_hands)
                    flag = 0;
                break;
            case 1:
                if(x[j]<1 || x[j]>ret_eyes)
                    flag = 0;
                break;
            case 3:
                if(x[j]<1 || x[j]>ret_eyes)
                    flag = 0;
                break;
            case 2:
                if(x[j]<1 || x[j]>ret_mouths)
                    flag = 0;
                break;
            default:
                break;
            }
        }
        if(!flag)
            printf("Are you kidding me? @\\/@");
        else {
            for(int j=0;j<5;j++) {
                switch (j) {
                case 0:
                case 4:
                    paint(x[j],hands);
                    break;
                case 1:
                    printf("(");
                    paint(x[j],eyes);
                    break;
                case 3:
                    paint(x[j],eyes);
                    printf(")");
                    break;
                case 2:
                    paint(x[j],mouths);
                    break;
                default:
                    break;
                }
            }
        }
        printf("\n");
    }
    return 0;
}

int read(char emoji[LENGTH][WIDTH]) {
    int sum=0;
    char temp = getchar();
    for(int line =0, p=0, k=0;;) {
        while(temp != L'[') {
            temp = getchar();
            if (temp == '\n')
                return sum;
        }
        if(temp == '[') {
            temp = getchar();
            while(temp != ']'){
                emoji[p][k++] =temp;
                temp = getchar();
            }
            emoji[p++][k] = '\0';
            k = 0;
            sum++;
        }
    }
    return sum;
}

void paint(int x, char (*emoji)[WIDTH]) {
    x--;
    printf("%s", &emoji[x][0]);
}