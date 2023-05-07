#include <stdlib.h>
#include <stdio.h>
int main(){
	float lon;
	float lat;
	char info[80];
	int started = 0;
	printf("data: [\n");
	while(scanf("%f,%f,%79s[^\n]", &lon, &lat, info) == 3){ // <
		if (started){
			printf(",\n");
		}		
		else {
			started = 1;
		}
		if (lat < -90 || lat > 90) {
			fprintf(stderr, "Invalid latiture %f\n", lat); // 2>
			return 2;
		}
		if (lon < -180 || lon > 180) {
			fprintf(stderr, "Invalid longitude %f\n", lon);
			return 2;
		}
		fprintf(stdout, "{longitude: %f, latitude: %f, info: '%s'}",lon, lat, info); // >
	}
	puts("\n]");
	return 0;
}
// command to execute ./gpj < testdata.csv 
// ./gpj < testdata.csv > output.json
// if we want to redirect stderr we can use 2>
// ./gpj < testdata.csv 2> err.log
