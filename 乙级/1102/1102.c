#include <stdio.h>
#include <stdlib.h>
struct entry {
    int price;
    int sale;
    char id[9];
};

int main(void)
{
    int N, maxSale=0, maxProfit=0;
    scanf("%d",&N);
    struct entry* data = malloc(N*sizeof(struct entry));
    scanf("%s %d %d",data[0].id, &data[0].price, &data[0].sale);
    for(int i=1;i<N;i++){
        scanf("%s %d %d",data[i].id, &data[i].price, &data[i].sale);
        if(data[i].sale > data[maxSale].sale)
            maxSale = i;
        if(data[i].sale*data[i].price > data[maxProfit].sale*data[maxProfit].price)
            maxProfit = i;
    }
    printf("champion1 is %s %d\n", data[maxSale].id, data[maxSale].sale);
    printf("champion2 is %s %d\n", data[maxProfit].id, data[maxProfit].sale*data[maxProfit].price);
}