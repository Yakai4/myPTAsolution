#include <stdio.h>
#include <stdlib.h>
#define CURRENT_YEAR 2014
#define CURRENT_MONTH 9
#define CURRENT_DAY 6
#define OLD 0
#define YOUNG 1
struct people {
    int year;
    int month;
    int day;
    int name_position;
} ;
void initial(struct people*, int);
//void print(struct people*, char*); test
int main(void)
{
    int N;scanf("%d", &N);int ans = N;
    struct people oldest,youngest;
	initial(&oldest,OLD);initial(&youngest,YOUNG);
	char* name_table = (char*) malloc(6*N*sizeof(char)); 

    for(int i=0,year=0,month=0,day=0;i<N;i++) {
        scanf("%s %d/%d/%d", &name_table[6*i], &year, &month, &day);
        if (year > CURRENT_YEAR || (year == CURRENT_YEAR && month > CURRENT_MONTH) || (year == CURRENT_YEAR && month == CURRENT_MONTH && day > CURRENT_DAY))
            ans--;
        else if (year < CURRENT_YEAR-200 || (year == CURRENT_YEAR-200 && month < CURRENT_MONTH) || (year == CURRENT_YEAR-200 && month == CURRENT_MONTH && day < CURRENT_DAY))
            ans--;
        else { 
			if (oldest.year > year || (oldest.year == year && oldest.month > month) || (oldest.year == year && oldest.month == month && oldest.day > day)) {
				oldest.year = year; oldest.month =month;oldest.day = day;
				oldest.name_position = i;
			}
			if(youngest.year < year || (youngest.year == year && youngest.month < month) || (youngest.year == year && youngest.month == month && youngest.day < day)) {
				youngest.year = year; youngest.month =month;youngest.day = day;
				youngest.name_position = i;
			}
		}
    }
	//print(&oldest,name_table);
	//print(&youngest,name_table);
	if (ans == 0)
		printf("0");
	else
		printf("%d %s %s", ans, &name_table[6*oldest.name_position], &name_table[6*youngest.name_position]);
	free(name_table);
	return 0;
}

void initial(struct people* p, int state) {
	if(state == YOUNG) {
	p->day=CURRENT_DAY-1;
	p->month=CURRENT_MONTH;
	p->year=CURRENT_YEAR-200;
	p->name_position=0;
	} else if(state == OLD) {
	p->day=CURRENT_DAY+1;
	p->month=CURRENT_MONTH;
	p->year=CURRENT_YEAR;
	p->name_position=0;
	}
}
/** test
void print(struct people* p, char* name_table){
	printf("%s %d/%d/%d\n", &name_table[6*p->name_position],p->year,p->month,p->day);
}*/