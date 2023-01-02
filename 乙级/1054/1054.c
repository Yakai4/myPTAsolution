#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 41	//测试点三，40位长度的字符串，比如1111111111111111111111111111111111111111
					//与网上说的123.之类的数据不一样，应该是修改过测试数据了
typedef struct
{
	int sign,exp,A;//<sign,10^exp,A> ----> (sign)*(10^exp)*A
}NUM;

int judge(char *, NUM *);
void add(NUM *, NUM *);
void clean(NUM *);

int main() {
	int i=0,j=0,N,valid=0,state=0;
	char buffer[MAXLEN]={},c;
	NUM *num = malloc(sizeof(NUM)),*aver=malloc(sizeof(NUM));
	clean(aver);
	scanf("%d\n", &N);
	while(i<N) {
		scanf("%c", &c);
		if(c == '\n' || c == ' ') {
			buffer[j] = '\0';
			j=0;i++;
			state = judge(buffer, num);
			if(state ==-1)
				printf("ERROR: %s is not a legal number\n", buffer);
			else {
				add(aver,num);
				valid++;
			}
			clean(num);
		} else
			buffer[j++] = c;
	}
	if(valid==0) 
		printf("The average of 0 numbers is Undefined\n");
	else if(valid==1)
		printf("The average of 1 number is %.2f\n", aver->A * 0.01);
	else
		printf("The average of %d numbers is %.2f\n", valid,  aver->sign * aver->A * 0.01 / (1.0 * valid));
	return 0;
}

int judge(char *buffer, NUM * number) {
	int state=-1,dot=0;
	number->sign = buffer[0]=='-'? -1:1;
	for(int i=0;buffer[i]!='\0';i++) {
        if(i>8) {//-1000.00是字符最多的情况，多于8个字符一律非法
            state =-1;
            break;
        } else if(buffer[i] == '.') {
			dot++;
			if(dot>1) {
				state=-1;
                break;
            }
		} else if('0' <= buffer[i] && buffer[i] <= '9') { 
            state=1;
			number->A = number->A*10+(int)(buffer[i]-'0');
			if (dot==1) {
				number->exp--;
				if (number->exp < -2) {
					state = -1;
					break;
				}
			}
		} else if (('a' <= buffer[i] && buffer[i] <= 'z') || ('A' <= buffer[i] && buffer[i] <= 'Z')){
			state = -1;
            break;
        }
	}
    while(state && number->exp>-2) {
        number->A *= 10;
        number->exp--;
    }
	if(number->A > 100000)	state = -1;
	return state;
}
void add(NUM *a,NUM *b) {
	a->A = a->sign * a->A + b->sign * b->A;
	a->sign = (a->A < 0) ? -1 : 1;
}

void clean(NUM *a) {
	a->sign = 0;
	a->A = 0;
	a->exp = 0;
}