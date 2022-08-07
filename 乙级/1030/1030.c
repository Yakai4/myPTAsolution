#include <stdio.h>
void qsort(int*, int ,int);
int main(void)
{
    int N; long p; scanf("%d %ld", &N, &p);
    int arr[N], end = N, ans=1, head=0,tail=head+1;
    for(int i=0;i<N;i++)
        scanf("%d", &arr[i]);
    qsort(arr, 0, N-1);

    while(head<end-1/*some conditions*/) {
        while( tail <end && arr[head]*1l <= arr[tail]*p ) 
            tail++;
		ans = (ans > tail-head) ? ans: tail-head;
        head++;
//tail = head+1;
	}
    printf("%d\n", ans);

}

void qsort(int* arr, int head, int tail) {
    if(head<tail) {
        int i=head,j=tail,x=arr[head];
        while(i < j){
            while( i<j && arr[j] < x)   j--;
            if(i<j) arr[i++] = arr[j];
            while( i<j && arr[i] > x)   i++;
            if(i<j) arr[j--] = arr[i];
        }
        arr[i] = x;
        qsort(arr, head,i-1);
        qsort(arr, i+1, tail);
    }
}