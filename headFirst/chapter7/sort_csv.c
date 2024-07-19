#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
  char* filename = "test_data.csv";
  FILE* file = fopen(filename, "r");
  char value[256];
  int i = 0;
  while(fgets(value, 256, file) != NULL) {
    if (i==0){
      i++;
      continue;
    }
    else{
      sscanf(value, "%[^,],%d,%[^,\n]", employees[i-1].name, &employees[i-1].age, employees[i-1].dept);
      i++;
    }
  }
  puts("Normal print");
  for (int k=0; k<sizeof(employees)/sizeof(emp); k++){
    puts(employees[k].name);
  }
  puts("Sort by age");
  qsort(employees, sizeof(employees)/sizeof(emp), sizeof(emp), compareAge);
  for (int k=0; k<sizeof(employees)/sizeof(emp); k++){
    puts(employees[k].name);
  }
  puts("Sort by name");
  qsort(employees, sizeof(employees)/sizeof(emp), sizeof(emp), compareNames);
  for (int k=0; k<sizeof(employees)/sizeof(emp); k++){
    puts(employees[k].name);
  }
  fclose(file);
}
