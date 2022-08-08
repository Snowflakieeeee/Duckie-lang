#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lex(char *content)
{
	char ch;

	for (int i = 0; i<= strlen(content); i++)
	{
		if (content[i] == ' ')
		{
			printf("a space.\n");
		}
	}
}

int main()
{
	char ch;
	char contents[4096];
	FILE *fp;
	fp = fopen("./input/test.dc", "r");
	int i = 0;
	while (1)
	{
		ch = fgetc(fp);
		contents[i] = ch;
		printf("%c", ch);
		i++;
		if (ch == EOF){
			break;
		}
	}
	
	// printf("%s", contents);

	return 0;
}