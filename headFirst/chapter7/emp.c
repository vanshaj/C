#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
	const char *name;
	const char *dept;
	int age;
} emp;

int compare(const void *ele1, const void *ele2) {
	emp emp1 = *(emp*)ele1;
	emp emp2 = *(emp*)ele2;
	return emp1.age - emp2.age;
}

int compNames(const void *ele1, const void *ele2) {
	char *name1 = *(char**)ele1;
	char *name2 = *(char**)ele2;
	return strcmp(name1, name2);
}

int main(){
	emp emp1 = {"poor", "dev", 25};
	emp emp2 = {"toder", "qa", 20};
	emp emp3 = {"stream", "support", 30};
	emp arr[] = {emp1, emp2, emp3};
	for(int i=0; i<sizeof(arr)/sizeof(emp); i++){
		puts(arr[i].name);
	}
	puts("Sorting");
	qsort(arr, sizeof(arr)/sizeof(emp), sizeof(emp), compare);
	for(int i=0; i<sizeof(arr)/sizeof(emp); i++){
		puts(arr[i].name);
	}
	puts("Array of String");
	char *names[] = {"Ak", "Cd", "Bp"};
	qsort(names, 3, sizeof(char*), compNames);
	for(int i=0; i<3; i++){
		puts(names[i]);
	}
}
