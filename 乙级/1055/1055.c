#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ren {
    int height;
    char name[9];
};
void my_qsort(struct ren**, int, int);

//50% faster than mine
int cmp(const void *a, const void *b) {
	struct ren ** A = (struct ren **) a;
	struct ren ** B = (struct ren **) b;
    if((*A)->height != (*B)->height)
        return  (*B)->height - (*A)->height;
    return strcmp((*A)->name, (*B)->name);
}
int main(void)
{
    int N,K;    scanf("%d %d", &N, &K);
    struct ren *people[N];
    for(int i=0;i<N;i++) {
        people[i] = (struct ren*) malloc(N*sizeof(struct ren));
        scanf("%s %d\n", people[i]->name, &(people[i]->height));
    }
    //my_qsort(people,0,N-1);
	qsort(people, N, sizeof(struct ren*), cmp);
	for(int i=0;i<N;i++) {
        printf("%s %d\n", people[i]->name, people[i]->height);
    }
	int m = N - (K-1)*(N/K);//last row first
	char *row[m > (N/K)? m:(N/K)];

	for(int j=0,t=0;j<K;j++) {
		if(j==0)	m = N - (K-1)*(N/K);
		else		m = N/K;
		for(int i=0,pos=m/2,sign=1;i<m;i++) {
			pos = m/2 + (i+1)/2*sign;
			row[pos] = people[t++]->name;
			sign = -1*sign;
		}
		for(int i=0;i<m;i++) {
			printf("%s",row[i]);
			if(i<m-1)
				printf(" ");
			else
				printf("\n");
		}
	}
    return 0;
}

void my_qsort(struct ren *people[], int head, int tail) {
    if(head < tail) {
        struct ren *x=people[head];int i=head,j=tail;
        while(i < j) {
            while(i<j && ((people[j]->height < x->height) ||
						  (people[j]->height == x->height && strcmp(people[j]->name,x->name) > 0))
				 )	j--;
            if(i < j)	people[i++] = people[j];
            while(i<j && ((people[i]->height > x->height) ||
						  (people[i]->height == x->height && strcmp(people[i]->name,x->name) < 0))
				 )	i++;
            if(i < j)	people[j--] = people[i];
        }
        people[i] = x;
        my_qsort(people, head, i-1);
        my_qsort(people, i+1, tail);
    }
}
