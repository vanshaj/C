/*
 * =====================================================================================
 *
 *       Filename:  structs.c
 *
 *    Description: Ggg 
 *
 *        Version:  1.0
 *        Created:  06/03/23 10:08:52
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

typedef struct fish{
	const char *name;
	const char *species;
	int teeth;
	int age;
}fish;

void printName(fish f){
	puts(f.name);
}

void increaseAge(fish *f) {
	(*f).age = (*f).age + 1;
	// f->age = f->age + 1;
}

void printSpecies(fish *f){
	puts((*f).species);
	puts(f->species);
}

int main(){
	fish snappy = {"Snappy", "Piranha",69,4};
	printName(snappy);
	fish gnawer = snappy;
	printName(gnawer);
	gnawer.name = "gnawer";
	printName(snappy);
	printName(gnawer);
	printf("Age of snappy is %d\n", snappy.age);
	increaseAge(&snappy);
	printf("Age of snappy is %d\n", snappy.age);
	printSpecies(&snappy);
	return 0;
}


