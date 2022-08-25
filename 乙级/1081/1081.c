#include <stdio.h>
#define SIZE 'Z'-'A'+1+'9'-'0'+1+1
#define STRLEN 81
void judge(int[], int);
void clear(int[]);

int main(void) 
{
    int N;  scanf("%d", &N);
    int char_cnt[SIZE]={0}, legal;
    char str[STRLEN] = {};
    for(int i=0;i<N;i++) {
		getchar();
        scanf("%[^\n]", str);
        legal = 1;
        for(int j=0;str[j]!='\0';j++) {
            if( str[j]<='Z' && str[j]>='A' )
                char_cnt[str[j]-'A']++;
            else if( str[j]<='z' && str[j]>='a' )
                char_cnt[str[j]-'a']++;
            else if( str[j]<='9' && str[j]>='0' )
                char_cnt['Z'-'A'+1+str[j]-'0']++;
            else if(str[j] == '.')
                char_cnt[SIZE-1]++;
            else
                legal = 0;
        }
        judge(char_cnt,legal);
        clear(char_cnt);
    }
    
    return 0;
}

void judge(int ccnt[], int othch_legal) {
    int n=0, char_legal = 0, number_legal = 0;
    for(int i=0;i<SIZE;i++)
        n+=ccnt[i];
    for(int i=0;i<='Z'-'A';i++) {
        if(ccnt[i]>0){
            char_legal = 1;
            break;
        }
    }
    for(int i = 'Z'-'A'+1;i<'Z'-'A'+1+'9'-'0'+1;i++) {
        if(ccnt[i]>0) {
            number_legal = 1;
            break;
        }
    }
    if(n<6) {
        printf("Your password is tai duan le.\n");
    } else if(!othch_legal) {
        printf("Your password is tai luan le.\n");
    } else if(!number_legal && char_legal) {
        printf("Your password needs shu zi.\n");
    } else if(!char_legal && number_legal) {
        printf("Your password needs zi mu.\n");
    } else {
        printf("Your password is wan mei.\n");
    }
}

void clear(int ccnt[]) {
    for(int i=0;i<SIZE;i++)
        ccnt[i] = 0;
}