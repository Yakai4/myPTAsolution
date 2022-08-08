#include <stdio.h>

int main(void)
{
    char M[11] = {'1','0','X','9','8','7','6','5','4','3','2'};
    int coe[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    int N;  scanf("%d", &N);
    char id[N][19];
    for(int i=0;i<N;i++)
        scanf("%s", &id[i][0]);
    int sum=0, flag =1;
    for(int j=0, tf=1; j<N; j++) {
        sum=0;tf=1;
        for(int i=0;i<17;i++) {
            if(id[j][i]<='9' && id[j][i] >='0')
                sum += (id[j][i] - '0') * coe[i];
            else {
				tf=0;
                printf("%s\n", &id[j][0]);
                flag = 0;
                break;
            }
        }
        if(tf && M[sum % 11] != id[j][17]){
            flag = 0;
            printf("%s\n", &id[j][0]);
        }
    }
    if(flag)    
        printf("All passed");
    return 0;
}