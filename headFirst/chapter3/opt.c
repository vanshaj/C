/*
 * =====================================================================================
 *
 *       Filename:  opt.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/14/23 06:04:28
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	int option;
	char line[200];
	char *filename = NULL;
	while((option = getopt(argc, argv, "sf:")) != -1){
		switch(option){
			case 's':
				break;
			case 'f':
				filename = optarg;
				break;
			default:
				puts("enter valid flag");

		}
	}
	printf("Arguments count %d\n", argc);
	for(int i=0; i<argc; i++){
		puts(argv[i]);
	}
	argc -= optind;
	argv += optind;
	printf("Arguments count %d\n", argc);
	for(int i=0; i<argc; i++){
		puts(argv[i]);
	}

	FILE *in_file;
	if (!(in_file = fopen("in.txt", "r"))) {
		fprintf(stderr, "Can't open file\n");
		return 1;
	}
	fscanf(in_file, "%199[^\n]", line);
	int len = 0;
	char *first = line;
	while(*first != '\0'){
		first = first+1;
		len++;
	}
	if (filename != NULL) {
		FILE *out_file = fopen(filename, "w");
		puts("printing on file");
		fprintf(out_file, "Len of input text is %d\n", len);
		fclose(out_file);
	}
	else {
		puts("printin on stdout");
		fprintf(stdout, "Len of input text is %d\n", len);
	}
	fclose(in_file);
}
