#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main(){
	char user[20];
	char cars[3];
	puts("What is your name?");
	scanf("%3s", user);
	printf("hello %s\n", user);
	puts("How many cars do you have?");
// This doesnot work need to be checked
	// scanf("%2s", cars);
	int count_cars = atoi(cars);
	printf("%s has %d cars\n", user, atoi(cars));
	printf("%c\n", user[0]);
	// user = {'B', 'e', 'n', 'j', 'a', 'm', 'i', 'n', '\0'} \0 is called sentinel character
	count_cars = count_cars + 1;
	printf("%d cars\n", count_cars);
	count_cars +=2;
	printf("%d cars\n", count_cars);
	count_cars++;
	printf("%d cars\n", count_cars);
	count_cars -=2;
	printf("%d cars\n", count_cars);
	bool matches;
	if ( count_cars > 2 && count_cars < 4){
		matches = 1;
		puts("And condition matches");
	} else {
		matches = 0;
		puts("No match");
	}
	if (!matches) {
		puts("No match");
	}
	else {
		puts("And condition matches");
	}
}

