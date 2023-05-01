#include <stdio.h>
void printStr(char msg[]){
	printf("Message is %s\n", msg);
	printf("the message is stored at %p\n", msg);
	char *first = msg;
	char *second = msg + 1;
	printf("the char value at first is %c\n", *msg);
	printf("the char value at second is %c\n", *second);
	printf("the char value at third is %c\n", *(first + 2));
	printf("the char value at fourth is %c\n", msg[3]);
	// *(msg +1) msg[1] [1]msg
	printf("the string from first to end is '%s'\n", first);
	printf("the string from second to end is '%s'\n", second);
	char currentVal = *msg;
	puts("----------character pointer memory iteration start-------------");
	while(currentVal != '\0') {
		currentVal = *msg;
		printf("%c\n", currentVal); // prints the character value
		printf("%p\n", msg); // prints the address
		msg = msg + 1; // increments the address
	}
	puts("----------character pointer memory iteration end-------------");
}

void printInt(int msg[], int size){
	puts("----------int pointer memory iteration start-------------");
	for(int i = 0; i<size; i++){
		int currentVal = *msg;
		printf("%d\n", currentVal);
		printf("%p\n", msg);
		msg = msg +1;
	}
	puts("----------int pointer memory iteration end-------------");
}

void printContent(char *msg, int offset){ // (char msg[], int offset) are equal
	puts(msg+offset);
}

int main(){
	int sizeOfInt = sizeof(int);
	printf("%d\n", sizeOfInt);
	int sizeOfTur = sizeof("Turtles!");
	printf("%d\n", sizeOfTur);
	char msg[] = "hello";
	printStr(msg);
	printf("%ld\n", sizeof(msg));
	char name[] = "My name is Captain";
	printContent(name, 11);
	int list[] = {1,2,3,4,5};
	int size = sizeof(list)/sizeof(list[1]);
	printInt(list, size);
	return 0;
}
