#include <stdio.h>
#include <math.h>
#include <string.h>

int* turn_to_op(char *content){
	char ch;
	static int opcodes[150];
	int len = strlen(content);
	char buf[255];
	int  curbuflen = 0;
	int linenum = 0;
	int numofquacks = 1;
	int codenum = 0;
	for (int i=0; i<len; i++)
	{
		ch = content[i];
		int cmp = strcmp(buf, " quack");
		if (cmp == 0 && ch == ' '){
			numofquacks++;
			strncpy(buf, "", 254);
			curbuflen = 0;
		}
		else if (cmp != 0 && ch == ' '){
			strncpy(buf, "", 254);
			curbuflen = 0;
		}
		else if (ch == '\n'){
			linenum++;
			opcodes[codenum] = numofquacks;
			codenum++;
			numofquacks = 1;
		}
		buf[curbuflen] = content[i];
		curbuflen++;

	}
	return opcodes;
}
void run(int *opcodes){
	fflush(stdout);
	int stack[150];
	int stacktop = 0;
	int currentop = 0;
	stack[0] = 0;
	int ignorenextline = 0;
	for (int i = 0; i< 150; i++){
		if (ignorenextline == 1){
			ignorenextline = 0;
			currentop++;
			continue;
		}
		else if (opcodes[i] == 1){
				stack[stacktop] = stack[stacktop-1] + stack[stacktop-2];
		} else if (opcodes[i] == 2){
				stack[stacktop] = stack[stacktop-1] - stack[stacktop-2];
		} else if (opcodes[i] == 3){
				stack[stacktop] = stack[stacktop-1] * stack[stacktop-2];
		} else if (opcodes[i] == 4){
				stack[stacktop] = stack[stacktop-1] / stack[stacktop-2];
		} else if (opcodes[i] == 5){
				stack[stacktop] = opcodes[currentop+1] + 96;
				ignorenextline = 1;
				stacktop++;
		} else if (opcodes[i] == 6){
				i = opcodes[currentop+1];
				currentop = opcodes[currentop+1];
				ignorenextline=1;
		} else if (opcodes[i] == 7){
				printf("%d\n", stack[stacktop]);
				stack[stacktop] = 0;
		} else if (opcodes[i] == 8){
				if (stack[stacktop-1] > 127){
					printf("unable to print, greater than ascii max value (>127)\n");
					exit(2);
				} 
				else if (stack[stacktop-1] == 32){
					printf(" ");
					continue;
				} else if (stack[stacktop-1] < 32){
					printf("\n");
					continue;
				}
				printf("%c", stack[stacktop-1]);
				stack[stacktop-1] = 0;
				stacktop--;
		} else if (opcodes[i] == 9){
				char tmp;
				scanf("%c", &tmp);
				stack[stacktop] = (int)tmp;
				stacktop++;
		} else if (opcodes[i] > 10){
				stack[stacktop] = opcodes[currentop] - 10;
				printf("pushing int to stack %d\n", stack[stacktop]);
				stacktop++;
		}
		
		currentop++;
	}
}
