from secrets import token_bytes
import sys, re
import time, shlex

def readfile(path):
    file = open(path)
    data = file.readlines()
    file.close()
    return data

def lexdata(data):
    words = []
    keywords = [
        "good morning duckie",
        "bye duckie",
        "listen",
        "say",
        "remember",
        "recipe",
        "write"
    ]
    tokens = []
    programstartsyntax = False
    for line in data:
        if data[0].strip() != "good morning duckie":
            print("duckie angry. duckie nu get greet.")
            sys.exit(1)
        elif data[len(data)-1].strip() != "bye duckie":
            print("DUCKIE NO GET BYE. DUCKIE MAD")
            time.sleep(3)
            print("*duckie tired.*")
            sys.exit(3)
        
            
        words.append(shlex.split(line, posix=False))
    programstartsyntax=True
        
    token_num = 0
    line_num = 0
    for line in words:
        if programstartsyntax:
            programstartsyntax=False
            continue
        
        for word in line:
            if word in keywords:
                if word == "listen":
                    tokens.append(["KEYWORD", word])
                    continue
                
                elif word == "write":
                    tokens.append(["SUB KEYWORD", word])
                    continue
                
                elif word == "say":
                    tokens.append(["KEYWORD", word])
                    continue
                    
                elif word == "remember":
                    if line[token_num + 3] == "as":
                        print("duckie did not understand something on line {} word {}".format(line_num, token_num))
                        sys.exit(12)
                    tokens.append(["KEYWORD", word])
                    continue
                    
                elif word == "recipe":
                    tokens.append(["KEYWORD", "recipe"])
                    continue
                    
            if re.match(r'\d+', word) and word:
                    tokens.append(["INTEGER", word])
                    continue
                    
            elif re.match(r'\D+', word):
                tokens.append(["IDENTIFIER", word])
                continue
                    
            token_num += 1
        tokens.append(["NL", "\n"])
        line_num += 1
        token_num = 0
        
    return tokens
            
def parsedata(tokens):
    ast = []
    token_num = 0
    line_num = 0
    
    for token in tokens:
        if token[0] == "NL":
            line_num += 1
        if token[0] == "KEYWORD":
            if token[1] == "remember":
                ast.append({"remember":[tokens[token_num+1][1], tokens[token_num+3][1]]})
            if token[1] == "say":
                arguments = []
                i = 1
                while True:
                    if tokens[token_num + i][0] == "NL":
                        break
                    else:
                        arguments.append(tokens[token_num+i][1])
                    i+=1
                ast.append({"say": arguments})
            if token[1] == "listen":
                if tokens[token_num+2][1] == "forget":
                    ast.append({"listen": ["forget"]})
                    
                elif tokens[token_num+2][1] == "write":
                    if tokens[token_num+3][1] != "on":
                        print("{}:line\nduckie:da waht.".format(line_num))
                        sys.exit(3)
                    ast.append({"listen": [tokens[token_num+2][1], tokens[token_num+4][1]]})
                    
                else:
                    print("{}:line\nduckie: listen and do waht.".format(line_num))
                    
        token_num += 1
        
    # print(ast)
    return ast

def interpret(ast):
    for node in ast:
        for k,v in node.items():
            if k == "say":
                print("duckie says: ") #contiue from here pls pls
            

data = readfile("input/test.dc")
tokens = lexdata(data)
ast = parsedata(tokens)
interpret(ast)

