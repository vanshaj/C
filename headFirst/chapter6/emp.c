/*
 * =====================================================================================
 *
 *       Filename:  emp.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/10/23 14:06:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

typedef struct linkedlist{
	int item;
	struct linkedlist *next;
} linkedlist;

linkedlist create(int value){
	linkedlist l1 = {value, NULL};
	printf("%p\n", &l1);
	return l1;
}

linkedlist *createP(int value){
	linkedlist *l1 = malloc(sizeof(linkedlist));
	l1->item = value;
	l1->next = NULL;
	return l1;
}

void destroy(linkedlist *l){
	free(l);
}

void display(linkedlist *head) {
	while(head != NULL){
		printf("%d\n", head->item);
		head = head->next;
	}
}

int main(){
	linkedlist l1 = create(1);
	printf("%p\n", &l1);
	linkedlist l2 = create(2);
	printf("%p\n", &l2);
	l1.next = &l2;
	linkedlist *l3 = createP(3);
	l2.next = l3;
	linkedlist *l4 = createP(4);
	l3->next = l4;
	display(&l1);
	destroy(l3);
	destroy(l4);
}
