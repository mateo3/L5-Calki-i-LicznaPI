#include <stdio.h>
#include<unistd.h>
#include<time.h>
#include<math.h>
double Leibniz_PI(int n)
{
    double wynik = 0;
    
    int i;
    double temp = 0;
    for (i=1; i<=n; i++)
    {
        temp = powf(-1, i-1) / (2 * i - 1);
        wynik += temp 
    }
    return 4 * wynik;
}

int main()
{
    int ilosc_procesow;
    printf("Podaj ilosc procesow: ");
    scanf("%d", &ilosc_procesow);
    int i;
    for(i=0; i<ilosc_procesow; i++)
    {
        if(fork()==0)
        {	
	    double wynik
            srand(time(NULL) ^ getpid());
            int n = 100 + rand()%1000+1;
            wynik = Leibniz_PI(n);
            printf("Przyblizenie liczby Pi z wozru Leibniza = %f\n", wynik);
            exit(0);
        }
    }
return 0;
}