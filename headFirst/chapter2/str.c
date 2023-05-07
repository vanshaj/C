/*
 * =====================================================================================
 *
 *       Filename:  str.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/06/23 07:01:09
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
#include <string.h>

void jukebox(){
	puts("Enter track you want to search?");
	char exp[80];
	fgets(exp, 6, stdin);
	char records[][80] = {
		"track is poor",
		"track is coders",
		"track is stream"
	};
	for(int i=0;i<3;i++){
		if(strstr(records[i], exp)){
			printf("Found string is %s\n", records[i]);
			return;
		}	
	}
	puts("not found");

}

int main(){
	jukebox();
	char name[] = "Hello";
	char records[][80] = {
		"track 1",
		"track 2",
		"track 3"
	};
	/*
	char *records[80] = {
		"track 1",
		"track 2",
		"track 3"
	}; 
	*/
	puts(name);
	printf("%c\n", *name);
	puts(*records);
	/*  
	 *  records will give us the address of first row
	 *  *records will give us the address of first element in first row
	 *  *records+6 will give us the address of 7th element in the first row
	 */
	printf("%c\n", *(*records+6)); 
	printf("%c\n", records[0][6]);
	/*
	 * records will give us the address of first row
	 * records+1 will give us the address of second row
	 * *(records+1) will give us the address of first element in second row
	 * *(records+1) + 6 will give us the address of 7th element in second row
	 * *(*(records+1) + 6) will give us the value of the 7th ele in second row
	 */
	printf("%c\n", *(*(records+1)+6));
	printf("%c\n", records[1][6]);
}
