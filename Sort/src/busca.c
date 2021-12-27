#include<stdio.h>
#include"./../library/busca.h"

//	Busca padrão em vetor não ordenado
int buscaLinear(int* vet, int N, int elem){
	int passos = 0;
	for(int i=0; i<N; i++){
		passos++;
		if(vet[i] == elem){
			printf("Passos: %d.\n",passos);
			return i;
		}
	}

	printf("Passos: %d.\n",passos);
	return -1;
}

//	Busca padrão em vetor ordenado
int buscaOrdenada(int* vet, int N, int elem){
	int passos = 0;
	for(int i=0; i<N; i++){
		passos++;
		if(vet[i] == elem){
			printf("Passos: %d.\n",passos);
			return i;
		}else if(vet[i] > elem){
			printf("Passos: %d.\n",passos);
			return -1;
		}
	}

	printf("Passos: %d.\n",passos);
	return -1;
}

//	Busca otimizada em vetor ordenado
int buscaBinaria(int* vet, int N, int elem){
	int passos = 0;
	int inicio, meio, fim;
	inicio = 0;
	fim = N-1;

	while(inicio <= fim){
		meio = (inicio + fim)/2;
		passos++;

		if(elem < vet[meio]){
			//	Busca na metade da esquerda
			fim = meio-1;
		}else if(elem > vet[meio]){
			//	Busca na metade da direita
			inicio = meio+1;
		}else{
			printf("Passos: %d.\n",passos);
			return meio;
		}
	}

	printf("Passos: %d.\n",passos);	
	return -1;
}