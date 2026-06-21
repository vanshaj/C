#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int reverse(char *s){
	size_t lenS = strlen(s);
	for(int i =lenS-1; i>=0; i--){
		printf("%c", *(s+i));	
	}
	puts("");
	return 0;
}

int main(){
	char s[] = "poor_coders_stream";
	reverse(s);
}
