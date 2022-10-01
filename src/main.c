#include <stdio.h>

// char lex()
int main(int argc, char const *argv[])
{
	printf("enter code:\n");
	char ch;
	fp = fopen("./input/test.dc", "r");
	while{
		ch = fgetc(fp);
		if (ch == EOF){break;}
		printf("%c", ch);
	}
	char input[4096];
	gets(input);

	return 0;
}