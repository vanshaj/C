/*
 * =====================================================================================
 *
 *       Filename:  change.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/06/23 06:49:57
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
	char jimmy[] = "alive";
	char *raider = jimmy;
	printf("Jimmy is %s, raider is %s\n", jimmy, raider);
	puts("--------------------------------------------");
	printf("Location of first element in Jimmy is %p, and raider is %p\n", jimmy, raider);
	jimmy[0] = 'd';
	printf("Location of second element in Jimmy is %p, and raider is %p\n", jimmy+1, raider+1);
	jimmy[1] = 'e';
	printf("Location of third element in Jimmy is %p, and raider is %p\n", jimmy+2, raider+2);
	jimmy[2] = 'a';
	printf("Location of fourth element in Jimmy is %p, and raider is %p\n", jimmy+3, raider+3);
	jimmy[3] = 'd';
	puts("--------------------------------------------");
	printf("Jimmy is %s, raider is %s\n", jimmy, raider);
}

