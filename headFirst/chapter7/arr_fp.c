#include <stdio.h>
#include <string.h>

typedef struct response{
  char *body;
  int status_code;
}response;

int status_code(response r){
  printf("%d\n", r.status_code);
  return r.status_code;
}
int bad_code(response r){
  printf("%d\n", 400);
  return 400;
}


int main(){
    response r = {"my body", 200};
    int (*replies[]) (response) = {status_code, bad_code};
    puts("Which status code you want?");
    char code[10];
    //fgets(code, 10, stdin); it will include \n too in the string
	  fscanf(stdin, "%9[^\n]", code);
    if (strcmp(code, "bad") == 0){
      replies[1](r);
    }
    else {
      replies[0](r);
    }
}
