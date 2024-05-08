#include <stdio.h>
#include <stdlib.h>

void go_south_east(int *lat, int *lon){
	puts("Going south east");
	printf("Address of lat is %p\n", lat);
	*lat = *lat -1;
	*lon = *lon +1;
	// Defining memory
	int y = 3;
	int *memy = &y;
	int valY = *memy;
	printf("Address of y is %p\n", memy);
	printf("Value of y is %d\n", valY);

}

int main(){
	int x = 4;
	printf("x is stored at %p\n", &x);

	int lat = 53;
	int lon = 33;
	printf("lat is now %d, lon is now %d\n", lat, lon);
	printf("Address of lat is %p\n", &lat);
	go_south_east(&lat, &lon);
	printf("lat is now %d, lon is now %d\n", lat, lon);
	return 0;
}



