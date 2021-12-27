#include<stdlib.h>
#include<stdio.h>

void somaVoid(int const a, int const b, int* c);
int somaInt(int const a, int const b);

int main(){
	int a,b,c;

	a=10;
	b=35;
	somaVoid(a,b,&c);

	printf("Soma Int: %d + %d = %d\n",a,b,somaInt(a,b));
	printf("Soma Void: %d + %d = %d\n",a,b,c);

	a=95;
	b=27;
	somaVoid(a,b,&c);

	printf("Soma Int: %d + %d = %d\n",a,b,somaInt(a,b));
	printf("Soma Void: %d + %d = %d\n",a,b,c);

	return 0;
}

void somaVoid(int const a, int const b, int* c){
	*c = a+b;
	return;
}


int somaInt(int const a, int const b){
	return a+b;
}