#include <stdio.h>
#include <string.h>
#define MAXSIZE 200

char table[13] = {'0','1','2','3','4','5','6','7','8','9','J','Q','K'};
int max(int, int);

int main(void)
{
	char A[MAXSIZE], B[MAXSIZE], ans[MAXSIZE];
    scanf("%s %s", A, B);
	int A_len = strlen(A), B_len = strlen(B);
    //while(B_len < 1);
	if(A_len > B_len) {
		for(int i=A_len, j = B_len;j>=0;i--) 
			B[i] = B[j--];
		for(int i=0;i<A_len-B_len;i++) 
			B[i] = '0';
	} else if(A_len < B_len) {
		for(int i=B_len, j = A_len; j>=0;i--) 
			A[i] = A[j--];
		for(int i=0;i<B_len-A_len;i++) 
			A[i] = '0';
	}
	//printf("%s %s\n", A, B);
    int len = max(A_len, B_len);
    for(int i=len-1;i>=0;i-=2) //odd
		ans[i] = table[(A[i]-'0' + B[i]-'0')%13];

    for(int i=len-2;i>=0;i-=2) {
        int t = B[i]-'0'-(A[i]-'0');
        if(t<0)
            t+=10;
        ans[i] = table[t];
    }
    ans[len] = '\0';//!!!
    printf("%s", ans);
    return 0;
}

int max(int a, int b) {
    return a>b? a:b;
}

/*#include <stdio.h>
#include <string.h>
int min(int, int);
int max(int, int);

char table[13] = {'0','1','2','3','4','5','6','7','8','9','J','Q','K'};
int main(void)
{
	char A[101], B[101], ans[101];
    scanf("%s %s", A, B);
	int A_len = strlen(A), B_len = strlen(B);
	if(A_len > B_len) {
		for(int i=A_len, j = B_len;j>=0;i--) 
			B[i] = B[j--];
		for(int i=0;i<A_len-B_len;i++) 
			B[i] = '0';
	} else if(A_len < B_len) {
		for(int i=B_len, j = A_len;i>=0 && j>=0;i--) 
			A[i] = A[j--];
		for(int i=0;i<B_len-A_len;i++) 
			A[i] = '0';
	}
	//printf("%s %s\n", A, B);
    int len = max(A_len, B_len);
    for(int i=len-1;i>=0;i-=2) //odd
		ans[i] = table[(A[i]-'0' + B[i]-'0')%13];

    for(int i=len-2;i>=0;i-=2) {
        int t = B[i]-'0'-(A[i]-'0');
        if(t<0)
            t+=10;
        ans[i] = table[t];
    }
    printf("%s\n", ans);
    return 0;
}

int max(int a, int b) {
    return a>b? a:b;
}
int min(int a, int b) {
    return a<b? a:b;
}

/*

#include <stdio.h>
#include <string.h>
#define MAXSIZE 101

char table[13] = {'0','1','2','3','4','5','6','7','8','9','J','Q','K'};
int max(int, int);

int main(void)
{
	char A[MAXSIZE], B[MAXSIZE], ans[MAXSIZE];
    scanf("%s %s", A, B);
	int A_len = strlen(A), B_len = strlen(B);
	while(B_len < 1);
	if(A_len > B_len) {
		for(int i=A_len, j = B_len;j>=0;i--) 
			B[i] = B[j--];
		for(int i=0;i<A_len-B_len;i++) 
			B[i] = '0';
	} else if(A_len < B_len) {
		for(int i=B_len, j = A_len; j>=0;i--) 
			A[i] = A[j--];
		for(int i=0;i<B_len-A_len;i++) 
			A[i] = '0';
	}
	//printf("%s %s\n", A, B);
    int len = max(A_len, B_len);
    for(int i=len-1;i>=0;i-=2) //odd
		ans[i] = table[(A[i]-'0' + B[i]-'0')%13];

    for(int i=len-2;i>=0;i-=2) {
        int t = B[i]-'0'-(A[i]-'0');
        if(t<0)
            t+=10;
        ans[i] = table[t];
    }
    printf("%s", ans);
    return 0;
}

int max(int a, int b) {
    return a>b? a:b;
}
*/