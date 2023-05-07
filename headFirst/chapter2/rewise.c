/*
 * =====================================================================================
 *
 *       Filename:  rewise.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/06/23 06:34:56
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
	char arr2[][20] = {
		"Name 1",
		"Name 2",
		"Name 3",
	};
	/*
	 * char *name[] = {"DOg", "Cat", "Lion"};
	 */
	printf("%c\n",**arr2);
	printf("%c\n", *(*arr2 + 5));
	printf("%c\n", *(*(arr2+2)+5));
	for(int i = 0;i<3; i++){
		char *pointer;
		pointer = *(arr2+i);
		printf("%c\n", *(pointer+5));
	}
	char arr[] = "Poor"; // stack
	puts(arr);

	char *last = "Coders"; // constant memory block
	puts(last);
	arr[0] = 'T';
	puts(arr); // Toor
	puts("What is your name?");
	char name[10];
	fgets(name, 9, stdin);
	printf("Your name is %s\n", name);
}

