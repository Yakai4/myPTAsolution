#include<stdio.h>
int main()
{   int a,i,j,line=1,sum,total; 
  char b;
scanf("%d %c",&a,&b);
total=a;
sum=2*line*line-1;
while(total>=sum){
    line=line+2;
    sum=sum+2*line;
}
sum=sum-2*line;
line=line-2;
//printf("%d\n",line);
int temp=line;
int space;
for(i=1;i<=line;i++){
   if(i<=line/2+1){
   	for(space=1;space<i;space++){
   		printf(" ");
	   }
   	for(j=1;j<=temp;j++){
	    printf("%c",b);
   }
   temp=temp-2;
   printf("\n");
}else{
	for(space=1;space<=line-i;space++){
		printf(" ");
	}
	temp=temp+2;
	for(j=1;j<=temp+2;j++){
		printf("%c",b);
	}
	  printf("\n");
}
}
printf("%d",total-sum);
    return 0;
}