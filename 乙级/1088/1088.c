#include <stdio.h>
#include <stdlib.h>
#pragma region 
enum PCG {
	Ping,Cong,Gai
};
int reverseOrd(int);
enum PCG cmp(double, double);
char ss[][5] = {"Ping", "Cong", "Gai"};

int main(void)
{
	int B[100], X=3, Y=7, M=0, maxA=-1;	scanf("%d %d %d", &M, &X, &Y);
	for(int A=10;A<100;A++)
		B[A] = reverseOrd(A);
	double t1, t2;
	for(int A=10;A<100;A++) {
		t1 = abs(A-B[A])/(1.0*X);
		t2 = B[A]/(1.0*Y);
		if (t1 == t2){
			//printf("%d %d\n",A ,B[A]);
			if(maxA < A)
				maxA = A;
		}
	}
	if (maxA == -1)
		printf("No Solution");
	else 
		printf("%d %s %s %s", maxA, &ss[cmp(maxA,M)][0], &ss[cmp(B[maxA],M)][0], &ss[cmp(B[maxA]/(1.0*Y),M)][0]);
	return 0;
}

int reverseOrd(int n) {
	return n/10 + 10*(n%10);
}

enum PCG cmp(double a, double M) {
	if(a == M)
		return Ping;
	if(a > M)
		return Cong;
	if(a < M)
		return Gai;
}