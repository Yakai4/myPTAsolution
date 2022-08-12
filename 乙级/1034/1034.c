#include <stdio.h>
#include <stdlib.h>

typedef struct rationalNum {
    long a;
    long b;
} ration, *R;

void formatPrint(ration);
R rAdd(ration, ration);
R rSub(ration, ration);
R rMul(ration, ration);
R rDiv(ration, ration);
long gcd(long, long);
long labs(long);
void answer(char,R,R);

int main(void)
{
    struct rationalNum x,y;
    scanf("%ld/%ld %ld/%ld", &x.a, &x.b,&y.a,&y.b);
	answer('+',&x,&y);
	answer('-',&x,&y);
	answer('*',&x,&y);
	answer('/',&x,&y);
    return 0;
}

void formatPrint(ration x) {
	if(x.b != 0) {
		long g = labs(gcd(x.a, x.b));
		x.a/=g;	x.b/=g;
        int sign = 1;
        if(x.a<0){
            x.a*=-1;
            sign *= -1;
        }
        if(x.b<0) {
            x.b*=-1;
            sign*=-1;
        }
		if(sign == -1)
			printf("(-");
		if(x.b == 1)
			printf("%ld",x.a);
		else if(x.a < x.b)
			printf("%ld/%ld", x.a, x.b);
		else if(x.a > x.b)
			printf("%ld %ld/%ld", x.a / x.b, x.a%x.b, x.b);
		if(sign == -1)
			printf(")");
	} else 
		printf("Inf");
}

R rAdd(ration x, ration y) {
    R t = (ration*) malloc(sizeof(ration));
	t->a = x.a*y.b + x.b*y.a;
	t->b = x.b*y.b;
	return t;
}

R rSub(ration x ,ration y) {
	R t = (ration*) malloc(sizeof(ration));
	t->a = x.a*y.b - x.b*y.a;
	t->b = x.b*y.b;
	return t;
}

R rMul(ration x, ration y) {
	R t = (ration*) malloc(sizeof(ration));
	t->a = x.a*y.a;
	t->b = x.b*y.b;
	return t;
}

R rDiv(ration x, ration y) {
	R t = (ration*) malloc(sizeof(ration));
	t->a = x.a*y.b;
	t->b = x.b*y.a;
	return t;
}

long gcd(long x, long y) {
	if(y)
		return gcd(y, x%y);
	else
		return x;
}

long labs(long x){
	return x>0? x:-x;
}

void answer(char ch, R x, R y) {	
	R res;
	formatPrint(*x);
	printf(" %c ",ch);
	formatPrint(*y);
	printf(" = ");
	if(ch=='+')
		res = rAdd(*x,*y);
	else if(ch=='-')
		res = rSub(*x,*y);
	else if(ch=='*')
		res = rMul(*x,*y);	
	else if(ch=='/')
		res = rDiv(*x,*y);		
    formatPrint(*res);
	printf("\n");
	free(res);
}