#include<stdio.h>
int main(){
	char name[20];
	puts("Whats your name?"); // Prints the text
	scanf("%19s", name); // scans the input text from the stdin but only 19 characters
	printf("Dear %s, its nice to have you here\n", name); // output to stdout
	return 0;
}
