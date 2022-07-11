#include <stdio.h>
#include <string.h>

typedef struct
{
        char id[9];
        int merit,talent;
} stu;
int total(stu* a)
{
	return a->merit+a->talent;
}
void swap(stu** O, int i, int j)
{
        stu* temp=O[i];
        O[i]=O[j];
        O[j]=temp;
}
void sort(stu** STU, int head, int tail)//bubble sort exceeds time limitaion.
{
	for(int i=head;i<tail;++i)
	{
		for(int j=i+1;j<tail;++j)
		{
			int totalA = STU[i]->merit+STU[i]->talent;
			int totalB = STU[j]->merit+STU[j]->talent;
			if(totalA < totalB)
				swap(STU,i,j);
			else if(totalA == totalB)
			{
				if(STU[i]->merit < STU[j]->merit)
					swap(STU,i,j);
				else if(STU[i]->merit == STU[j]->merit)
				{
					if(STU[i]->id < STU[j]->id)	
					swap(STU,i,j);	
				}
			}
				
		}		 
	}
}
//int epoch=0;
void qsort(stu* STU[], int head, int tail)//quick sort is faster
{
	if(head < tail)
	{
		int i = head, j = tail;
		stu* x = STU[head];
		while(i < j)
		{
			while(i < j && total(STU[j]) <= total(x))	
			{
        //printf("epoch:%d STU[%d]->id:%s > x->id:%s=%d\tstrcmp:%d \n",epoch,j,STU[j]->id,x->id,STU[j]->id > x->id,strcmp(STU[j]->id,x->id));
				//epoch++;
				if(total(STU[j]) == total(x) && STU[j]->merit > x->merit)	break;
				else if(total(STU[j]) == total(x) && STU[j]->merit == x->merit && strcmp(STU[j]->id, x->id) < 0) break;
				j--;
			}
			if(i < j)	STU[i++] = STU[j];

			while(i < j && total(STU[i]) >= total(x)) 	
			{
				if(total(STU[i]) == total(x) && STU[i]->merit < x->merit)	break;
				else if(total(STU[i]) == total(x) && STU[i]->merit == x->merit && strcmp(STU[i]->id, x->id) > 0) break;
				i++;
			}
			if(i < j)	STU[j--] = STU[i];

		}
		STU[i] = x;
		qsort(STU,head,i-1);
		qsort(STU,i+1,tail);
	}
}

stu group[100000];//not 10000!
stu* ord[100000];//not 10000!
int main(void)
{
        int N,L,H;
        scanf("%d %d %d",&N,&L,&H);
        int k=0;
        //printf("10000001<10000005: %d\n",strcmp("10000005","10000001"));//pit ahh. Quate: Comparison with string literal results in unspecified behaviour
        while(N--)
        {
                scanf("%s %d %d",group[k].id,&group[k].merit,&group[k].talent);
                if(group[k].merit<L || group[k].talent<L)
                {
                        continue;
                }//dont consider
                //ord[k]=&group[k];
                k++;
                //printf("now N is %d\n",N);
        }	
	
	int pA=0,pB=0,pC=0,pD=0;
	for(int i=0;i<k;++i) 
	{
		if(group[i].merit>=H && group[i].talent>=H )pB++;
		else if(group[i].talent<H && group[i].merit>=H)	pC++;
		else if(group[i].talent<H && group[i].merit<H && (group[i].merit >= group[i].talent))	pD++;
	}
	pC+=pB;
	pD+=pC;
	for(int i=0;i<k;++i)
	{
		if(group[i].merit>=H && group[i].talent>=H){
			ord[pA] = &group[i];
			pA++;
		} else if(group[i].talent<H && group[i].merit>=H){
			ord[pB] = &group[i];
			pB++;
		} else if(group[i].talent<H && group[i].merit<H && (group[i].merit >= group[i].talent)){
			ord[pC] = &group[i];
			pC++;
		} else {
			ord[pD] = &group[i];
			pD++;
		}
	}
	//qsort each calss
	qsort(ord,0,pA-1);
	qsort(ord,pA,pB-1);
	qsort(ord,pB,pC-1);
	qsort(ord,pC,pD-1);
	//print result
        printf("%d\n",pD);
        //printf("class 1:\n");
        for(int i=0;i<pA;i++)
        {
				printf("%s %d %d\n",ord[i]->id,ord[i]->merit,ord[i]->talent);
		}
		//printf("class 2:\n");
		for(int i=pA;i<pB;i++)
        {
				printf("%s %d %d\n",ord[i]->id,ord[i]->merit,ord[i]->talent);
		}
		//printf("class 3:\n");
		for(int i=pB;i<pC;i++)
        {
				printf("%s %d %d\n",ord[i]->id,ord[i]->merit,ord[i]->talent);
		}
		//printf("class 4:\n");
		for(int i=pC;i<pD;i++)
        {
				printf("%s %d %d\n",ord[i]->id,ord[i]->merit,ord[i]->talent);
		}
		//printf("%s > %s = %d",ord[0]->id, ord[1]->id, strcmp(ord[0]->id, ord[1]->id));
        return 0;
}
/*
5 60 80
10000005 80 80
10000004 80 80
10000003 80 80
10000002 80 80
10000001 80 80
*/
