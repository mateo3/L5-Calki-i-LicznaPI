#include <stdio.h>
#include <unistd.h>
#include <time.h>
int random(int min, int max)
{
	srand(getpid());
	return min + rand() % (( max + 1 ) - min);
}
double func(double x)
{	
	return 4 * x - 6 * x + 5;
}
double calka_Gaussa(int a, int b, double wagi1[], double wagi2[]){
	int n = 8;
	double wynik= 0;
	for(int i=0; i<n; i++){
		wynik += wagi1[i] * func(((b-a)/2)*wagi2[i] + ((b+a)/2));
	}
	return wynik*((b-a)/2);
}
int main(){	
	double wagi1[] ={0.3626837833783620, 0.3626837833783620,0.3137066458778873,0.3137066458778873,0.2223810344533745,0.2223810344533745,0.1012285362903763,0.1012285362903763};
	double wagi2[] = {-0.1834346424956498,0.1834346424956498,-0.5255324099163290,0.5255324099163290,-0.7966664774136267,0.7966664774136267,-0.9602898564975363,0.9602898564975363};
	int ilosc_procesow;
	printf("Ilosc procesow: ");
	scanf("%d", &ilosc_procesow);
	for(int i=0; i<ilosc_procesow; i++){
		if(fork() == 0){
			double wynik;
			int a = random(-20,0);
			int b = random(0,20);
			wynik = calka_Gaussa(a, b, wagi1, wagi2);
			printf("\nCalka na przedziale (%d, %d) wynosi %f", a,b,wynik);
			exit(0);
		}
	}
	return 0;
}