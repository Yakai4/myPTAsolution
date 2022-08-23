//note: wprintf() and printf() can't validate at the same time
//however, we can process char array in code of utf-8 or gbk which depends on your Encoding settings
//only a single char will be encoded into ascii.
//so let's create a new file 10523.c and remake.
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>

//read emoji and return actual quantity of chararter
//等价于read(wchar_t (*emoji)[4]);
int read(wchar_t emoji[10][4]);

//paint emoji
void paint(int, wchar_t(*)[4]);

int main(void)
{
    char *locale = setlocale(LC_ALL, "");
    setlocale(LC_CTYPE,locale);
    wchar_t hands[10][4],eyes[10][4],mouths[10][4];
    //wchar_t *sup[5] = {hands, eyes, mouths, eyes, hands}; 该怎么写？
    int ret_hands = read(hands);
    int ret_eyes = read(eyes);
    int ret_mouths = read(mouths);
    //wchar_t (*a)[4]; a= sup[0];
    //int ret_hands = wprintf(L"and it is: %lc\n",hands[6][0]);
    //int ret_eyes = wprintf(L"and it is: %lc\n",eyes[8][0]);
    //int ret_mouths = wprintf(L"and it is: %lc\n",mouths[4][0]);
    //printf("ret_hands: %d\tret_eyes: %d\tret_mouths: %d\n", ret_hands,ret_eyes,ret_mouths);
    int k,x[5];    wscanf(L"%d", &k);
    for(int i=0, flag=1;i<k;i++) {
        flag = 1;
        for(int j=0;j<5;j++){
            wscanf(L"%d", &x[j]);
            switch (j)
            {
            case 0:
            case 4:
                if(x[j]>ret_hands)
                    flag = 0;
                break;
            case 1:
                if(x[j]>ret_eyes)
                    flag = 0;
                break;
            case 3:
                if(x[j]>ret_eyes)
                    flag = 0;
                break;
            case 2:
                if(x[j]>ret_mouths)
                    flag = 0;
                break;
            default:
                break;
            }
        }
        if(!flag)
            wprintf(L"Are you kidding me? @\\/@");
        else {
            for(int j=0;j<5;j++) {
                switch (j)
                {
                case 0:
                case 4:
                    paint(x[j],hands);
                    break;
                case 1:
                    wprintf(L"(");
                    paint(x[j],eyes);
                    break;
                case 3:
                    paint(x[j],eyes);
                    wprintf(L")");
                    break;
                case 2:
                    paint(x[j],mouths);
                    break;
                default:
                    break;
                }
            }
            wprintf(L"\n");
        }
    }
    return 0;
}

int read(wchar_t emoji[10][4]) {
    int sum=0;
    wchar_t temp = getwchar();
    for(int line =0, p=0, k=0;;) {
        while(temp != L'[') {
            temp = getwchar();
            if (temp == L'\n')
                return sum;
        }
        if(temp == L'[') {
            temp = getwchar();
            while(temp != L']'){
                emoji[p][k++] =temp;
                temp = getwchar();
            }
            emoji[p++][k] = L'\0';
            k = 0;
            sum++;
        }
    }
    return sum;
}

void paint(int x, wchar_t (*emoji)[4]) {
    x--;
    int pos = 0;
    wchar_t temp = emoji[x][pos++];
    while ( temp != L'\0' ) {
        wprintf(L"%lc", temp);
        temp = emoji[x][pos++];
    }
}