/*
 * =====================================================================================
 *
 *       Filename:  hello.c
 *
 *    Description: 
 *
 *        Version:  1.0
 *        Created:  04/24/23 15:02:27
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
	puts("C Rocks");
	int card_count = 10;
	if (card_count > 10) {
		puts("count is greater than 10");
	}
	else {
		puts("count is less than or equal to 10");
	}
	int count = 0;
	while (count <10){
		puts("Count is increasing");
		count = count + 1;
	}
	return 0;
}
