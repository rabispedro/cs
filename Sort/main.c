#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#include"./library/busca.h"
#include"./library/ordenacao.h"

void show(int* vet, int N);

//	Compiling: gcc main.c ./src/busca.c ./src/ordenacao.c -lm
int main(){
	int N=18;
	int vet1[N], vet2[N], vet3[N], vet4[N],vet5[N],vet6[N];

	srand(time(NULL));
	for(int i=0; i<N; i++){
		vet1[i] = rand() % 32;
		vet2[i] = rand() % 64;
		vet3[i] = rand() % 128;
		vet4[i] = vet1[i];
		vet5[i] = vet2[i];
		vet6[i] = vet3[i];
	}

	printf("VETORES ORIGINAIS\n");
	show(vet1, N);
	show(vet2, N);
	show(vet3, N);

	printf("\nBusca Linear\n");
	printf("Valor: %d, encontrado no indice %d.\n",N,buscaLinear(vet1, N, N));
	printf("Valor: %d, encontrado no indice %d.\n",N,buscaLinear(vet2, N, N));
	printf("Valor: %d, encontrado no indice %d.\n",N,buscaLinear(vet3, N, N));

	printf("\nORDENACAO\n");
	printf("\nBubble Sort\n");
	bubbleSort(vet4, N);
	printf("Antes:\n");
	show(vet1, N);
	printf("Depois:\n");
	show(vet4, N);

	printf("\nInsertion Sort\n");
	bubbleSort(vet5, N);
	printf("Antes:\n");
	show(vet2, N);
	printf("Depois:\n");
	show(vet5, N);

	printf("\nSelection Sort\n");
	bubbleSort(vet6, N);
	printf("Antes:\n");
	show(vet3, N);
	printf("Depois:\n");
	show(vet6, N);


	printf("\nBUSCA ORDENADA\n");
	printf("Valor: %d, encontrado no indice %d.\n",N,buscaOrdenada(vet4, N, N));
	printf("Valor: %d, encontrado no indice %d.\n",N,buscaOrdenada(vet5, N, N));
	printf("Valor: %d, encontrado no indice %d.\n",N,buscaOrdenada(vet6, N, N));

	printf("\nBUSCA BINARIA\n");
	printf("Valor: %d, encontrado no indice %d.\n",N,buscaBinaria(vet4, N, N));
	printf("Valor: %d, encontrado no indice %d.\n",N,buscaBinaria(vet5, N, N));
	printf("Valor: %d, encontrado no indice %d.\n",N,buscaBinaria(vet6, N, N));

	return 0;
}

void show(int* vet, int N){
	printf("VET: ");
	for(int i=0; i<N; i++){
		printf("[%d] ",vet[i]);
	}
	printf("\n");
}