#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct island{
	char *name;
	char *opens;
	char *closes;
	struct island *next_island;
}island;

void display(island *head){
	while(head != NULL) {
		puts(head->name);
		head = head->next_island;
	}
}
island *create(char *name){
	island *p = malloc(sizeof(island));
	p->name = strdup(name);
	p->opens = "10";
	p->closes = "23";
	p->next_island = NULL;
	return p;
}
void destroy(island *p){
	free(p->name);
	free(p);
}
int main(){
	island shutter = {"shutter", "9", "21", NULL};
	island isla = {"isla", "10", "22", &shutter};
	island amity = {"amity", "10", "22", &isla};
	char name[80];
	fgets(name, 80, stdin);
	island *last2 = create(name);
	shutter.next_island = last2;
	fgets(name, 80, stdin);
	island *last = create(name);
	last2->next_island = last;
	display(&amity);
	destroy(last2);
	destroy(last);
	//puts(amity.name);
	//puts(amity.next_island->name);
	//puts(isla.next_island->name);
	return 0;
}
