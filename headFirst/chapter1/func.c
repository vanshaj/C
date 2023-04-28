/*
 * =====================================================================================
 *
 *       Filename:  func.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/24/23 15:36:53
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
// Declaration of stdio.h must be before stdlib.h
#include <stdio.h>
#include <stdlib.h>

int z = 3; // will get stored in the globals section of the memory
int larger(int x, int y){
	if (x>y){
		return x;
	} 
	return y;
}

int main(){
	int max; // will get stored on the stack
	max = larger(100, 101);
	printf("max value is %d\n ", max);
	return 0;
}

