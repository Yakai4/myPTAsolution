#include <stdio.h>
void qsort(double*, double* , int ,int);
int main(void) 
{
    double storage[1000],total_price[1000];
    int N,D;
    scanf("%d %d", &N, &D);
    for(int i=0;i<N;i++) {
        scanf("%lf", &storage[i]);
    }
    for(int i=0;i<N;i++) {
        scanf("%lf", &total_price[i]);
    }
    qsort(storage,total_price,0,N-1);
    int k=0;
    double price=0;
    //for(int i=0;i<0;i++)
    //    printf("%lf %lf\n", storage[i], total_price[i]);
    while(D>0) {
        D-=storage[k];
        if(D<0) {
            D+=storage[k];
            price += (double)D/storage[k]*total_price[k];
            break;
        } else {
            price += total_price[k];
        }
        k++;
    }
    printf("%.2f", price);
    return 0;
}
void qsort(double* storage, double* total_price, int head,int tail) {
    if(head < tail) {
        int i=head,j=tail, x = storage[head],y=total_price[head];
        double z = total_price[head]/storage[head];
        while(i<j) {
            while(i<j&&(total_price[j]/storage[j])<=z)   j--;
            if(i<j) {
                storage[i] = storage[j];
                total_price[i] = total_price[j];
                i++;
            }
            while(i<j&&(total_price[i]/storage[i])>z)   i++;
            if(i<j) {
                storage[j] = storage[i];
                total_price[j] = total_price[i];
                j--;
            }
        }
        storage[i] = x;
        total_price[i] = y;
        qsort(storage,total_price,head,i-1);
        qsort(storage, total_price,i+1,tail);
    }
}
