#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

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
    
    char *lines[10000];
    int curr_line = 0;
    char *token;
    token = strtok(text, "\n");

    while (token != NULL)
    {
        lines[curr_line] = token;
        token = strtok(NULL, "\n");
        curr_line++;
    }


    int numofquacks = 0;
    int opcodes[10000];
    int lineno = 0;
    bool end = false;
    while (lineno < 10000){
        token = strtok(lines[lineno], " ");
        while (token != NULL){
            if (strcmp(token, "quack") == 0){
                numofquacks++;
            }
            token = strtok(NULL, " ");
        }
        opcodes[lineno] = numofquacks;
        printf("%d", opcodes[lineno]);
        numofquacks=0;
        lineno++;
    }
    // for (int i=0; i<10000; i++){
    //     printf("%d\n", opcodes[i]);
    // }
    return 0;
}