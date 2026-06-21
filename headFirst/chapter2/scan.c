#include <stdio.h>

int main(){
	puts("What is your name?");
	char name[4]; //array of characters
	// second argument in scanf is the address
	//scanf("%s", name); // incorrect
	//scanf("%3s", name); //correct
	// fgets(food, sizeof(food), stdin); 
	printf("len of name is %ld\n", sizeof(name));
	long int lenName = sizeof(name);
	fgets(name, lenName, stdin); // 4 including the sentinel character
	printf("My name is %s\n", name);
	
	name[0] = 'b';
	// Delete
	printf("value is %c\n", *name);
	printf("value is %c\n", *(name+1));

	char *count = "JKL"; // can't be updated
	printf("%c\n", *count);
	printf("%c\n", *(count+1));
	printf("%c\n", *(count+2));
	printf("%c\n", count[2]);
	count[1] = 'a'; // string can't be updated
	char updateAllow[] = "JKL"; // this can be updated
}
