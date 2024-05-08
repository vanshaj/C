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
