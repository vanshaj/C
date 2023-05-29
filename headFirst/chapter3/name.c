/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/13/23 02:59:34
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
	char fname[100];
	char lname[100];
	scanf("%19s %19s", fname, lname);
	fprintf(stdout, "My name is %s %s\n", fname, lname); 
}
