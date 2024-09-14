#include <stdio.h>
#include <stdlib.h>

typedef struct emp{
  char name[7];
} emp;

int main(int argc, char *argv[]){
  int count = 3;
  void *ptr = calloc(count, sizeof(struct emp));
  emp *c = (emp*) ptr;
  emp *e = (emp*) ptr;
  for(int i=0; i<count; i++){
    printf("name\n");
    fgets(e->name, 7, stdin);
    e++;
  }
  for(int i=0; i<count; i++){
    printf("Details you added , name = %s\n", c->name);
    c++;
  }
  return 0;
}
