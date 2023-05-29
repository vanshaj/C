/*
 * =====================================================================================
 *
 *       Filename:  hello.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/29/23 17:16:20
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include "totaller.h"

int main(){
	int x = 2;
	int y = 3;
	printf("Sum is %f", add_with_tax(x,y));
	return 0;
}

float add_with_tax(int x, int y){
	float z;
	z = (float)x + (float)y;
	return z;
}
