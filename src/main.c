#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../utils/utils.c"

int main(int argc, char const *argv[])
{ 
	if (argc>3){
		printf("too many arguements\n");
		exit(1);
	} else if (argc<=1){
		printf("too few arguements\n");
		exit(1);
	}
	char ch;
	char contents[4096];
	FILE *fp;
	fp = fopen(argv[1], "r");
	if (fp == NULL){
		printf("file not found\n");
	}
	int i = 0;
	while (1)
	{
		ch = fgetc(fp);
		contents[i] = ch;
		i++;
		if (ch == EOF){
			break;
		}
	}
	int *opcodes = turn_to_op(contents);
	run(opcodes);

	return 0;
}
