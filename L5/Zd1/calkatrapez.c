#include <stdio.h>
#include<unistd.h>
#include<time.h>
float func(float x)
{
    return 4*x-6*x+5;
}
float calka_trapez(float a, float b, int n)
{
    float wynik= 0;
    float h = (b-a)/n;
    int i;
    for(i=1;i<=n-1;i++)
    {
        wynik += func(a+i*h);
    }
    wynik += (func(a)+func(b))/2;
    wynik *= h;
    return wynik;
}

int main()
{
    printf("Podaj ilosc procesow:\n");
    int ilosc_procesow;
    scanf("%d",&ilosc_procesow);
    int i;
    for(i=0;i<ilosc_procesow;i++)
    {
        if(fork()==0)
        {
            srand(time(NULL) ^ (getpid()));
            int a = rand()%100 ;
            int b = a + 1 + rand()%100 ;
            int n = 100 + rand()%100 ;
            float wynik = calka_trapez(a, b, n);
	    printf("Calka na przedziale (%d, %d) wynosi %f\n", a, b, wynik)
	    exit(0);
        }
    }
	return 0;
}