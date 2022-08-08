#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char x =getchar(); 
    char * hands[10];//10 kinds
    int k=0, j;
    while(x!='\n') {

        if(x == '[') {
			hands[k] = malloc(5 * sizeof(char));
			x = getchar();
			while(x!=']'){
            	hands[k][j++] = x;
				x = getchar();
			}
        }
		if(x==']') {
            hands[k][j++] = '\0';
			k++;
			j=0;
		}
        x = getchar();
    }
    for(int i=0;i<j;i++) {
        printf("%s ", hands[k]);
    }
    return 0;
}