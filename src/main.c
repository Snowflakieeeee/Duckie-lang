#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../utils/utils.c"

int main()
{ 
	char ch;
	char contents[4096];
	FILE *fp;
	fp = fopen("../input/test.dc", "r");
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
	lex(contents);

	return 0;
}
