#include "encrypt.h"

void encrypt(char *message){
	while(*message != '\0'){
		*message = *message ^ 31;
		message++;
	}
}
