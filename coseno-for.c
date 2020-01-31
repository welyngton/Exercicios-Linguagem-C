#include <stdio.h>

//define o numero de loops da serie que resolve o cosseno de x
// quanto maior for o valor de PRECISAO, mais preciso sera o valor do cosseno de x.
#define PRECISAO 14

double calcCOS (int n, double x) {

	int i, sinal;
   double f, cosx, potx;

	potx = 1.0;	//x^0
	f = 1.0;   //0!
	sinal = 1;     //sinal = 1 ou -1

	//valor para x=0 -> 1
	cosx = sinal * potx / f;	//metodo de calculo do cosseno por serie numerica

	for (i = 1; i < n; i++) {
		potx *= x * x;				//x^2, x^4, x^6 ...
		f *= 4 * i * i - 2 * i; //2!, 4!, 6!... 
		sinal *= -1;						//sinal multiplicador
		cosx += sinal * potx / f;	//metodo de calculo do cosseno
	}

  return(cosx);
}

int main (int argc, char *argv[]) {

	int n = PRECISAO;
	double result, x, cosx, potx;

	printf ("Angulo (rad): ");
	scanf ("%lf", &x);

	result = calcCOS(n,x);

	printf ("Cosseno de %lg rad = %lg\n", x, result);

	return 0;
}
