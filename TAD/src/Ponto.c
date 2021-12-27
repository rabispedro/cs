#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"./../library/Ponto.h"

//	Definição do tipo de dados
struct ponto{
	float x,y;
};

//	Cria um ponto
Ponto* pto_cria(float x, float y){
	Ponto* p = (Ponto*) malloc(sizeof(Ponto));

	if(p != NULL){
		p->x = x;
		p->y = y;
	}
	return p;
}

//	Libera a memória alocada para um ponto
void pto_libera(Ponto* p){
	free(p);
	return;
}

//	Acessa os valores "x" e "y" de um ponto
void pto_acessa(Ponto* p, float* x, float* y){
	*x = p->x;
	*y = p->y;
	return;
}

//	Atribui os valores "x" e "y" a um ponto
void pto_atribui(Ponto* p, float x, float y){
	p->x = x;
	p->y = y;
	return;
}

//	Calcula a distância entre dois pontos
float pto_distancia(Ponto* p1, Ponto* p2){
	float distX = (p1->x - p2->x);
	float distY = (p1->y - p2->y);
	return sqrt(((distX*distX) + (distY*distY)));
}