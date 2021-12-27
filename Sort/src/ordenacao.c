#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"./../library/ordenacao.h"

//	O(n^2)
void bubbleSort(int* vet, int N){
	int passos = 1;
	int continua, fim = N;

	do{
		continua = 0;
		for(int i=0; i<fim-1; i++){
			if(vet[i] > vet[i+1]){
				int aux = vet[i];
				vet[i] = vet[i+1];
				vet[i+1] = aux;
				continua = i;
			}
			passos++;
		}
		fim--;
	
	}while(continua != 0);

	printf("Passos: %d.\n",passos);
}

//	O(n^2)
void insertionSort(int* vet, int N){
	int i,j,passos = 0;
	for(i=0; i<N; i++){
		int aux = vet[i];
		for(j=i; (j>0) && (aux < vet[j-1]); j--){
			passos++;
			vet[j] = vet[j-1];
		}
		vet[j] = aux;
	}

	printf("Passos: %d.\n",passos);
}

//	O(n^2)
void selectionSort(int* vet, int N){
	int passos = 0;
	for(int i=0; i<N-1; i++){
		int menor = i;
		for(int j=(i+1); j<N; j++){
			passos++;
			if(vet[j] < vet[menor]){
				menor = j;
			}
			if(i != menor){
				int troca = vet[i];
				vet[i] = vet[menor];
				vet[menor] = troca;
			}
		}
	}
	
	printf("Passos: %d.\n",passos);
}

//	O(n log n)
void mergeSort(int* vet, int inicio, int fim){
	int passos = 0;
	if(inicio < fim){
		passos++;
		int meio = floor((inicio+fim)/2);
		mergeSort(vet, inicio, meio);
		mergeSort(vet, meio+1, fim);
		merge(vet, inicio, meio, fim);
	}
	
	printf("Passos: %d.\n",passos);
}

void merge(int* vet, int inicio, int meio, int fim){
	int subPassos = 0;

	int fim1 = 0;
	int fim2 = 0;
	int p1 = inicio;
	int p2 = meio+1;
	int tamanho = (fim-inicio)+1;
	int *temp = (int*)malloc(tamanho*sizeof(int));

	if(temp != NULL){
		for(int i=0; i<tamanho; i++){
			if(!fim1 && !fim2){
				//	Combinar ordenado
				if(vet[p1] < vet[p2]){
					temp[i] = vet[p1++];
				}else{
					temp[i] = vet[p2++];
				}

				//	Verifica se vetor acabou
				if(p1 > meio){
					fim1 = 1;
				}
				if(p2 > fim){
					fim2 = 1;
				}

			}else{
				//	Copia o que sobrar
				if(!fim1){
					temp[i] = vet[p1++];
				}else{
					temp[i] = vet[p2++];
				}
			}
		}

		for(int j=0, k=inicio; j<tamanho ;j++, k++){
			//	Copiar do auxiliar para o original
			vet[k] = temp[j];
		}

		free(temp);
	}

	free(temp);
	printf("SUB-Passos: %d.\n",subPassos);
}