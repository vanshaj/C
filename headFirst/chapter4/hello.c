#include <stdlib.h>
#include <stdio.h>
#include "totaller.h"
#include "encrypt.h"

int main(){
	int x = 2;
	int y = 3;
	printf("Sum is %f\n", add_with_tax(x,y));
	char message[] = "hello how are you";
	encrypt(message);
	puts(message);
	return 0;
}

float add_with_tax(int x, int y){
	float z;
	z = (float)x + (float)y;
	return z;
}
