/*
 * =====================================================================================
 *
 *       Filename:  scan.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/24/23 15:07:53
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>

int main(){
	puts("What is your name?");
	char name[20];
	scanf("%19s", name);
	printf("How are you %s\n", name);

	// Switch case
	char suit = 'C';
	switch(suit){
		case 'C':
			puts("C printed");
			break;
		case 'D':
			puts("D printed");
			break;
		case 'H':
			puts("H printed");
			break;
		default:
			puts("default");
	}
}
