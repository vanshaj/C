/*
 * =====================================================================================
 *
 *       Filename:  calc.c
 *
 *    Description: G 
 *
 *        Version:  1.0
 *        Created:  05/13/23 03:08:45
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

int main(){
	char max[200];
	scanf("%199[^\n]", max);
	char *first = max;
	int count = 0;
	while(*first != '\0'){
		count++;
		first = first+1;
	}
	printf("The length of input string is %d\n", count);
}
