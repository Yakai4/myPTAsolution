#include <stdio.h>
#include <stdlib.h>

void c_print(int, int);
int isPrime(int);

int main()
{ 
    int L,K,i,j,p=0,flag=0;
    int sum=0; 
    char a[1000];
    scanf("%d %d\n",&L,&K);
    fgets(a,1000,stdin);

    for(i=0;i<=L-K;i++){
	    for(j=i;j<i+K;j++)
		    sum=10*sum+a[j]-48;
    if(isPrime(sum)) {
        flag=1;
        c_print(sum, K);
        break;
    }
	sum=0;
  }
    if(!flag)   printf("404");
    return 0;
}

void c_print(int num, int K) {
    int top=0, *stk;
    stk = malloc(K*sizeof(int));
    while(num>0 || K>0){
        stk[top++] = num%10;
        num/=10;
        K--;
    }
    while(top>0) {
        printf("%d", stk[--top]);
    }
    free(stk);
}

int isPrime(int a){
    if(a<2) return 0;
    for(int i=2;i*i<=a;i++)
	    if(a%i==0)  return 0;
    return 1;
}