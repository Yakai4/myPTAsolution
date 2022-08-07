#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N; scanf("%d\n", &N);
    char* id = (char*) malloc(5*N*sizeof(char));
	char id2[N][5];
	int champion_x=100,champion_y=100,noob_x=0,noob_y=0;
    int champion_id, noob_id;
    for (int i=0,x=0,y=0;i<N;i++) {
        scanf("%s %d %d", &id2[i][0], &x, &y);
        if(x*x+y*y < champion_x*champion_x+champion_y*champion_y) {
            champion_id = i;
            champion_x=x;champion_y=y;
        }
        if(x*x+y*y > noob_x*noob_x+noob_y*noob_y) {
            noob_id = i;
            noob_x=x;noob_y=y;
        }
    }
    printf("%s %s", &id2[champion_id][0], &id2[noob_id][0]);
	return 0;
}