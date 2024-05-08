#include <stdlib.h>
#include <stdio.h>

enum colors {RED, GREEN, YELLOW};

typedef struct fish{
	const char *name;
	const char *species;
	int teeth;
	int age;
	enum colors color;
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
	fish snappy = {"Snappy", "Piranha",69,4, RED};
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

	printf("Address of snappy is %p\n", &snappy);
	printf("Address of snappy name is %p\n", &snappy.name);
	
	if (snappy.color == RED) {
		puts("Yes snappy is red");
		printf("%d\n", snappy.color);
	}
	return 0;
}


