/*
 * =====================================================================================
 *
 *       Filename:  fpoint.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/18/23 06:48:44
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

int sum(int x, int y) {
	return x+y;
}

int subtract(int x, int y){
	return x-y;
}

int main() {
	int (*fn_name) (int, int);
	fn_name = subtract;
	int a = 5;
	int b = 6;
	int c = fn_name(a,b);
	printf("%d\n", c);
	return 0;
}
