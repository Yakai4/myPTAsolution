#include <stdio.h>
#include <stdlib.h>
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
void my_qsort(int*, int ,int);
int cmp(const void * a, const void *b) {
    return *(int *)b - *(int *)a;
}
int main(void)
{
    int m=0,n=0,N;  scanf("%d", &N);
    //while(N>25);测试点2小于50大于25，快排有问题。
    for(int i=1;i*i<=N;i++)//O(sqrt(N))
        if(N%i==0)  n=i;
    m=N/n;
    int num[N],ans[m][n];
    for(int i=0;i<N;i++)
        scanf("%d", &num[i]);
    //qsort(num,N,sizeof(int),cmp);
    my_qsort(num,0,N-1);//这里超时 更新：鬼知道为什么。我的快排写得有问题。。原：可能测试点2，6，7都是有序的数列？（大小为9999）
	/*printf("sorted array is %d", num[0]);
	for(int i=1;i<N;i++)
		printf(" %d", num[i]);
		printf("\n");*/
    for(int i=0, col=0,row=0,state=RIGHT,up_border=-1,left_border=-1,right_border=n,down_border=m;i<N;i++) {
        if(state == RIGHT)
            ans[row][col++] = num[i];
        else if(state == DOWN)
            ans[row++][col] = num[i];
        else if(state == LEFT)
            ans[row][col--] = num[i];
        else if(state == UP)
            ans[row--][col] = num[i];
        //Update(state)
        /*
        if(col == right_border && row == up_border+1) {
            state = DOWN;
            up_border++;
			col--;
			row++;
        } else if(col == right_border-1 && row == down_border) {
            state = LEFT;
            right_border--;
			row--;
			col--;
        } else if(col == left_border && row == down_border-1) {
            state = UP;
            down_border--;
			col++;
			row--;
        } else if(col == left_border+1 && row == up_border) {//if(state==UP && row == up_border)
            state = RIGHT;
            left_border++;
			row++;
			col++;
        }*/
		//优化后如下
        if(col == right_border && state == RIGHT) {
            state = DOWN;
            up_border++;
			col--;
			row++;
        } else if(state == DOWN && row == down_border) {
            state = LEFT;
            right_border--;
			row--;
			col--;
        } else if(col == left_border && state == LEFT) {
            state = UP;
            down_border--;
			col++;
			row--;
        } else if(state == UP && row == up_border) {
            state = RIGHT;
            left_border++;
			row++;
			col++;
        }
    }
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++){
            printf("%d", ans[i][j]);
            if(j<n-1)
                printf(" ");
        }
        if(i<m-1)
            printf("\n");
    }
    return 0;
}

void my_qsort(int * arr, int head, int tail) {
    if(head < tail) {
        int i=head,j=tail,x=arr[head];
        while(i<j) {
            while(i<j && x > arr[j])    j--;
            if(i<j) arr[i++] = arr[j];
            while(i<j && x < arr[i])    i++;
            if(i<j) arr[j--] = arr[i];
        }
        arr[i] = x;
        my_qsort(arr, head, i-1);//铁bug我擦。能写my_qsort(arr, 0,i-1);也是牛的嗷。。
        my_qsort(arr, i+1, tail);
    }
}