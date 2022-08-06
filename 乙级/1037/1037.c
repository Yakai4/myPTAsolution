#include <stdio.h>
struct money {
    int Galleon;
    int Sickle;
    int Knut;
};

int main(void)
{
    struct money P,A;
    scanf("%d.%d.%d %d.%d.%d", &P.Galleon, &P.Sickle, &P.Knut, &A.Galleon, &A.Sickle, &A.Knut);
    int Knut = (A.Galleon*17 + A.Sickle)*29 + A.Knut - ((P.Galleon*17 + P.Sickle)*29 + P.Knut);
	if(Knut<0)	{
		printf("-");
		Knut = -Knut;
	}
    int Sickle=0, Galleon=0;
    while(Knut>=29) {
        Knut -=29;
        Sickle++;
        if(Sickle>=17){
            Sickle -= 17;
            Galleon++;
        }
    }
    printf("%d.%d.%d\n", Galleon, Sickle, Knut);
    return 0;
    
}