#include <stdio.h>
#include <string.h>

char* transToMar(int);
int str2num(char*);
int search(char* , char[][5]);
char table1[13][5] = {"tret", "jan", "feb","mar","apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
char table2[13][5] = {"tret", "tam", "hel","maa","huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int main(void)
{
    int N;  scanf("%d", &N);
    char cc[5];
	for(int i=0;i<N;i++) {
		scanf("%s", cc);
		if (cc[0]<='9' && cc[0]>='0') {
			int k = str2num(cc);
			if(k>12){
				printf("%s", &table2[k/13][0]);
                if(k%13!=0)
                    printf(" %s", &table1[k%13][0]);
			} else 
				printf("%s", &table1[k%13][0]);
			

			printf("\n");
		} else {
			int index1 = search(cc, table1);
			if (index1 >= 0) {//in table1
				printf("%d\n", index1);
			} else {
				int index2 = search(cc, table2);
				if (getchar() == ' ') {
					scanf("%s", cc);
					index1 = search(cc, table1);
				} else 
					index1 = 0;
				printf("%d\n", 13*index2+index1);
			}
		}
	}

    return 0;
}

int str2num(char* s) {
    int num=0;
    for(int i=0;s[i]!='\0';i++)
        num = num*10 + (s[i]-'0');
    return num;
}

int search(char* cc, char table[][5]) {
    for(int i=0;i<13;i++)
        if(strcmp(cc, &table[i][0]) == 0)
            return i;
    return -1;
}
void inc(void){
__asm__("INC EXA");
}