#include <stdio.h>
#include<math.h>

//https://www.urionlinejudge.com.br/judge/pt/problems/view/1021

int main(void) {

int aux, tent, c100, c50, c20, c10, c5, c2, m100, m50, m25, m10, m5, m1;
	double valor, val;
	scanf("%lf",&valor);
	
	val = valor*100;
	tent = (int)val;
  
	
	c100 = tent/10000;
	aux = tent % 10000;
	c50 = aux / 5000;
	aux = aux % 5000;
	c20 = aux / 2000;
	aux = aux % 2000;
	c10 = aux / 1000;
	aux = aux % 1000;
	c5 = aux / 500;
	aux = aux % 500;
	c2 = aux / 200;
	aux = aux % 200;
	

	m100 = aux / 100;
	aux =
  aux % 100;
	m50 = aux / 50;
	aux = aux % 50;
	m25 = aux / 25;
	aux = aux % 25;
	m10 = aux / 10;
	aux = aux % 10;
	m5 = aux / 5;
	aux = aux % 5;
	m1 = aux;
	
	printf ("NOTAS:\n");
	printf ("%d nota(s) de R$ 100.00\n", c100);
	printf ("%d nota(s) de R$ 50.00\n", c50);
	printf ("%d nota(s) de R$ 20.00\n", c20);
	printf ("%d nota(s) de R$ 10.00\n", c10);
	printf ("%d nota(s) de R$ 5.00\n", c5);
	printf ("%d nota(s) de R$ 2.00\n", c2);
	printf ("MOEDAS:\n");
	printf ("%d moeda(s) de R$ 1.00\n", m100);
    printf ("%d moeda(s) de R$ 0.50\n", m50);
	printf ("%d moeda(s) de R$ 0.25\n", m25);
	printf ("%d moeda(s) de R$ 0.10\n", m10);
	printf ("%d moeda(s) de R$ 0.05\n", m5);
	printf ("%d moeda(s) de R$ 0.01\n", m1);
	
	return 0;
}
