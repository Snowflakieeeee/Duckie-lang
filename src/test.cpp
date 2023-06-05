#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

int opcode_generator(string s, char del)
{
    stringstream ss(s);
    string word;
    int opcode = 0;
    while (!ss.eof()) {
        getline(ss, word, del);
        if (word == "quack"){
            opcode++;
        }
    }
    return opcode;
}

vector<string> tokenizer(string s, char del)
{
    stringstream ss(s);
    string word;
    vector<string> words;
    while (!ss.eof()) {
        getline(ss, word, del);
        words.push_back(word);
    }
    return words;
}

void run(vector<int> opcodes){
    int stack[150] = {0};
	int stacktop = 0;
	int currentop = 0;
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
                cout << "unable to print, greater than ascii max value (>127), line number" << i << "\n" << endl;
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
				stacktop++;
		}
		
		currentop++;
	}
}
int main(){
    
    FILE    *textfile;
    char    *text;
    long    numbytes;
     
    textfile = fopen("test.dkie", "r");
    if(textfile == NULL)
        return 1;
     
    fseek(textfile, 0L, SEEK_END);
    numbytes = ftell(textfile);
    fseek(textfile, 0L, SEEK_SET);  
 
    text = (char*)calloc(numbytes, sizeof(char));   
    if(text == NULL)
        return 1;
 
    fread(text, sizeof(char), numbytes, textfile);
    fclose(textfile);
    
    vector<string> lines = tokenizer(text, '\n');

    int numofquacks = 0;
    vector<int> opcodes;
    int lineno = 0;
    bool end = false;
    while (lineno < lines.size()){
        int opcode = opcode_generator(lines[lineno], ' ');
        opcodes.push_back(opcode);
        lineno++;
    }
    for (int i=0; i<opcodes.size(); i++){
        printf("%d\n", opcodes[i]);
    }
    run(opcodes);
    return 0;
}