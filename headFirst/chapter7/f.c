#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int doubleF(int x, int y){
	int z = y*x;
	return z;

}

int one_name(char *value){
	if (strstr(value, "Rohit") == NULL) {
		return 0;
	} 
	return 1;
}

int two_names(char *value)  {
	char *name1 = "Sachin";
	char *name2 = "Dhoni";
	if (strstr(value, name1) == NULL || strstr(value, name2) == NULL){
		return 0;
	}
	return 1;
}

void find(int len, char **arr, int (*fn_name)(char *)){
	for(int i=0; i<len; i++){
		if (fn_name(arr[i]) == 1) {
			puts(arr[i]);
			return;
		}	}
	puts("Not found");
}

int main(){
	int x = doubleF(4, 4);
	int (*p_doubleF)(int, int);
	p_doubleF = doubleF;
	int y = p_doubleF(x, x);
	printf("%d\n", x);
	printf("%d\n", y);

	int ARR_LEN = 3;
	char *arr[] = {
		"Virat, Rohit, Shami",
		"Dhoni, Sachin, Uthapa",
		"Gambhir, Shubman, KL Rahul"
	};
	find(ARR_LEN, arr, two_names);
	return 0;
}
