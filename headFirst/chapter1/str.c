#include<stdio.h>

int main(){
	char s[] = "hello";
	char a[] = {'h','e','l','l','o','\0'};  // \0 is sentinel character that is used to understand the end of character array
	printf("len of string %s is %lu\n", s, sizeof(s)); 
	printf("len of string %s is %lu\n", a, sizeof(a)); // sizeof returns long unsigned value
	return 0;
}
