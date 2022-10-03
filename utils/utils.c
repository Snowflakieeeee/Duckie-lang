#include <stdio.h>
#include <math.h>
#include <string.h>

enum TokenType {
	PROGRAMSTART,
	QUACK,
	QUCK,
	END
};
enum Instruction {
	HLT,
	ADD,
	SUB,
	MUL,
	DIV,
	PUSHLIT,
	PRINTAL,
	PRINTASC,
	INPUT,
	PUSHNUM
};

struct Token{
	char literal[255];
	enum Instruction instruction;
	enum TokenType token_type;
	int linenum;
};

char format (char* content);

void clearbuf(char *buf){
	char **b = &buf;
	for (int i=0; i<=254; i++){
		*b = "";
		b++;
	}
}
char *lex(char *content)
{
	char lines = 0;
	for (int i = 0; i<= strlen(content); i++)
	{
		if (content[i] == '\n')
		{
			lines++;
		}
	}

	char ch;
	int len = strlen(content);
	char buf[255];
	char newstring[len + 1][255];
	int wordnum = 0;
	int currentbufpointer = 0;
	for (int i=0; i<= len; i++)
	{
		ch = content[i];
		if (ch == ' '){
			strcat(newstring[wordnum], buf);
			strncpy(buf, "", 255);
			wordnum++;
		}
		char* ch_ptr = &ch;
		strncat(buf, ch_ptr, 1);
		currentbufpointer++;
	}
	strncat(newstring[len+1], "EOF", 4);
	return newstring;
}
