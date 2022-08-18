#include <stdio.h>
#include <stdlib.h>

//返回最小值
int min(int, int);

//打印排序后的数组
void print(int[], int);

//返回数列中从 begin 开始最长的递增子列末尾下标的位置
int getOrder(int[], int, int);

//在 begin 到 end 下标范围比较 origin 和 sorted 是否一致
int arrEqu(int[], int[], int, int);

//插入排序，从 begin 开始
void insertSort(int[], int);

//归并排序，间隔为 interval
void mergeSort(int[], int, int);

//返回最小归并间隔
//deprecated
int getMinInterval(int[], int);

int main(void)
{
	int N;	scanf("%d", &N);
	int origin[N],	sorted[N];
	for(int i=0;i<N;i++) 
		scanf("%d", &origin[i]);
	for(int i=0;i<N;i++) 
		scanf("%d", &sorted[i]);
	
	int dist = getOrder(sorted,0,N)+1;		//下标为 dist 的数不再递增
	
	if(arrEqu(origin, sorted, dist, N-1)) {
		printf(("Insertion Sort\n"));
		insertSort(sorted, dist);
		print(sorted,N);
	} else {
		printf("Merge Sort\n");
		int interval = 1; // getMinInterval(sorted, N);
		while(!arrEqu(origin, sorted, 0, N-1)) {
			mergeSort(origin, interval, N);
			interval*=2;
		}
		mergeSort(origin, interval, N);
		print(origin,N);
	}
}

int getOrder(int arr[], int begin, int length) {
	for(int i = begin; i < length; i++)
		if( !(arr[i] <= arr[i+1]) )
			return i;

	return length-1;
}

void insertSort(int arr[], int begin) {
	int i=0, temp = arr[begin];
	while(temp > arr[i])	i++;
	while(i < begin) {
		arr[begin] = arr[begin-1];
		begin--;
	}
	arr[i] = temp;
}

void mergeSort(int arr[], int interval, int N) {
	int *temp = (int*) malloc(N*sizeof(int));
	for(int i=0;i<N;i++) 
		temp[i] = arr[i];
	int i=0, j=interval, head=0, segement=0;
	while( head < N ) {
		while( i < min(segement+interval,N) && j < min(segement+2*interval, N) )
			arr[head++] = temp[i] > temp[j] ? temp[j++] : temp[i++];
		while( i < min(segement+interval,N) ) // Not i<segement+interval. For example N=100,segement=12*8,interval=8
			arr[head++] = temp[i++];
		while( j < min(segement+2*interval, N) )
			arr[head++] = temp[j++];
	
		if(head % (2*interval) == 0) {
			segement+=2*interval;
			i = segement;
			j = i + interval;
		}
	}
	free(temp);
}

int arrEqu(int origin[], int sorted[], int begin, int end) {
	int flag =1;
	for(int i=begin;i<=end;i++) 
		if(origin[i]!=sorted[i]) {
			flag = 0;
			break;
		}

	return flag;
}

void print(int toBePrinted[], int N) {
	printf("%d", toBePrinted[0]);
	for(int i=1;i<N;i++)
		printf(" %d", toBePrinted[i]);
	printf("\n");
}

int min(int a, int b) {
	return a>b? b:a;
}