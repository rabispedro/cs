#include<stdlib.h>
#include<stdio.h>
#include"./library/Ponto.h"

//	Compiling: gcc main.c ./src/Ponto.c -lm
int main(){
	Ponto* p1 = pto_cria(0, 0);
	Ponto* p2 = pto_cria(3, 4);

	float x1,x2,y1,y2;

	pto_acessa(p1, &x1, &y1);
	pto_acessa(p2, &x2, &y2);

	printf("Ponto 1: (%.2f, %.2f)\n",x1,y1);
	printf("Ponto 2: (%.2f, %.2f)\n",x2,y2);
	printf("Distancia: %.2f\n",pto_distancia(p1, p2));

	pto_libera(p1);
	pto_libera(p2);
	return 0;
}