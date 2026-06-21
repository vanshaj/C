#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

typedef struct emp {
  char name[10];
  int age;
  char dept[10];
}emp;


int compareAge(const void *ele1, const void *ele2) {
  emp emp1 = *(emp*)ele1;
  emp emp2 = *(emp*)ele2;
  return emp1.age - emp2.age;
}

int compareNames(const void* ele1, const void* ele2) {
  emp emp1 = *(emp*)ele1;
  emp emp2 = *(emp*)ele2;
  char* name1 = emp1.name;
  char* name2 = emp2.name;
  return strcmp(name1, name2);
}

int main(){
  emp employees[3];
  char *filename = "test_data.csv";
  FILE *f = fopen(filename, "r");
  if (f == NULL) {
    printf("Unable to open file due to errror %s\n", strerror(errno));
    return 1;
  }
  char headers[3][10];
  int rc = fscanf(f, "%[^,],%[^,],%s", headers[0], headers[1], headers[2]);
  if (rc == -1) {
    printf("Unable to read from file due to error %s\n", strerror(errno));
    return 1;
  }
  printf("Headers: %s, %s, %s\n", headers[0], headers[1], headers[2]);
  fgetc(f);

  for (int i=0; i<3; i++){
    int c = fscanf(f, "%[^,],%d,%s", employees[i].name, &employees[i].age, employees[i].dept);
    if (c == -1) {
      printf("Unable to read from file due to error %s\n", strerror(errno));
      return 1;
    }
    fgetc(f);
  }
  for(int i=0; i<3; i++){
    printf("name: %s, age: %d, dept: %s\n", employees[i].name, employees[i].age, employees[i].dept);
  }
  fclose(f);
  puts("-------After sorting--------");
  qsort(&employees, sizeof(employees)/sizeof(struct emp), sizeof(struct emp), compareAge);
  for(int i=0; i<3; i++){
    printf("name: %s, age: %d, dept: %s\n", employees[i].name, employees[i].age, employees[i].dept);
  }
  return 0;
}
