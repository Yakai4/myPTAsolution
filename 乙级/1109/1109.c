#include <stdio.h>
int abs(int x) {
	return x > 0 ? x:-x;
}

// 把单词读入 x 并返回字母数量
int getWord(char x[]);

int main(void) {
    char hello[26][7][7] ={};
    for(int i=0;i<26;i++) {
        for(int j=0;j<7;j++) {
            scanf("%s", &hello[i][j][0]);
        }
    }
    char x[11]={};getchar();
    int wordLen = getWord(x);
    
    while (wordLen != 0) {
        for (int line = 0; line < 7; line++) {
            for (int pos = 0; pos<abs(wordLen); pos++) {
                printf("%s", &hello[x[pos]-'A'][line][0]);
				if(pos < abs(wordLen)-1)
				printf(" ");
            }
            printf("\n");
        }
		if (wordLen < 0)
			break;
		if (wordLen > 0)
			wordLen = getWord(x);
		if (wordLen == 0)
			break;

		printf("\n");

    }
    return 0;
}

int getWord(char x[]) {
    int i=0;
    x[i] = getchar();
	while( !(x[i]>='A' && x[i]<='Z') && x[i]!='\n') 
		x[i] = getchar();
	while(x[i]>='A' && x[i]<='Z') 
		x[++i] = getchar();

	x[i+1] = '\0';

	if( x[i] == '\n')
		i = -1*i;

    return i;
}
