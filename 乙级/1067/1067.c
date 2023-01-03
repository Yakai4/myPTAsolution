/*
*    welcome! This file is created by create.sh!
*/
#include <stdio.h>
#include <string.h>

int main() {
	char pswd[21]={},in[41]={};
	int N,i=0;
	scanf("%s %d", pswd, &N);
    getchar();
	while(1) {
		scanf("%[^\n]%*c", in);
		if (strcmp(in, "#") == 0)
			break;
		if (strcmp(in, pswd) != 0) {
			printf("Wrong password: %s\n", in);
			i++;
			if (i == N)	{
				printf("Account locked\n");
				break;
			}
		} else {
			printf("Welcome in\n");
			break;
		}
	}
	return 0;
}
/**
123 3
 
#

*/