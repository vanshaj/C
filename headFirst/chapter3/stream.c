#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char *file_name;
	int ch;
	while ((ch = getopt(argc, argv, "sf:")) != -1){
		switch(ch){
			case 's':
				file_name = "";
				break;
			case 'f':
				file_name = optarg;
				break;
			default:
				fprintf(stderr, "Please enter valid flag\n");
				return 0;
		}
	}
	argc -= optind;
	argv += optind;
	char buffer[200];
	fscanf(stdin, "%199[^\n]", buffer);
	int size = 0;
	char *counter;
	counter = buffer;
	while(*counter != '\0'){
		size++;
		counter++;
	}
	if (strlen(file_name) == 0){
		fprintf(stdout, "Length of the stream is %d\n", size);
	} else{
		FILE *out_file = fopen(file_name, "a");
		fprintf(out_file, "Length of the stream is %d\n", size);
		fclose(out_file);
	}
	return 0;
}
