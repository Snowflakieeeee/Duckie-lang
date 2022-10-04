# Duckie lang
 A mostly esoteric programming language created in C (for extra suffereing for the developer), formerly in python<br>


A programming language i thought of over breakfast, turns out a similar programming language exists called `chicken`<br>
anyways, mine has a similar theme, but with quacks<br>
The program goes as follows:-
only command ==> "quack" commands/strings other than this should not be compiled (intended)<br>
the number of quacks per line will correspond to a particular op code :-<br>
SI --> stack pointer (always pointing on the next cell on stack)<br>
1 --> add `(SI-1 + SI-2 = SI) SI++`<br>
2 --> sub `(SI-1 - SI-2 = SI) SI++`<br>
3 --> mul `(SI-1 * SI-2 = SI) SI++`<br>
4 --> div `(SI-1 / SI-2 = SI) SI++`<br>
5 --> push to stack (next line is input for alphabet no. 0-26)<br>
6 --> goto (next line for input line no.)<br>
7 --> pop and print int on top of the stack (as is)<br>
8 --> pop character and print character on top of the stack (convert ascii to char) // <32 ==> newline :: >127 ==> whitespace<br>
9 --> take one char input and pushes onto stack (push ascii value)<br>
10+ --> pushes literal number n-10 to stack (as is)<br>

now, given that we have quacks per line, I think the first known bug makes sense, but I am working on fixing it.

x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x

**known bugs**<br>
---> Newline produces one quack resulting in op code 1, resulting in addition of values when not needed currently advised to sticking with code without  unncessary newlines<br>

**future plans**<br>
---> As this is a hobby project made for fun (also in a language I didnt know much of either) I wouldnt bet on its updates, say, 6 months later.<br>
---> Althought I have a few ideas, I intend to add few other characters (say, bear, that growls) that can be invited, in programming terms, a package/module/crate/etc.<br>
---> Because this is written in C, I am a bit reluctant to add too much support for things like graphics, but who knows, I will suffer anyways<br>

**hello world example**<br>
```
quack quack quack quack quack 
quack quack quack quack quack quack quack quack quack quack quack quack quack quack quack 
quack quack quack quack quack 
quack quack quack quack quack quack quack quack quack quack quack quack 
quack quack quack quack quack 
quack quack quack quack quack quack quack quack quack quack quack quack 
quack quack quack quack quack 
quack quack quack quack quack 
quack quack quack quack quack 
quack quack quack quack quack quack quack quack 
quack quack quack quack quack quack quack quack 
quack quack quack quack quack quack quack quack 
quack quack quack quack quack quack quack quack 
quack quack quack quack quack quack quack quack 
quack quack quack quack quack quack quack quack 
quack quack quack quack quack 
quack quack quack quack 
quack quack quack quack quack 
quack quack quack quack quack quack quack quack quack quack quack quack 
quack quack quack quack quack 
quack quack quack quack quack quack quack quack quack quack quack quack quack quack quack quack quack quack 
quack quack quack quack quack 
quack quack quack quack quack quack quack quack quack quack quack quack quack quack quack 
quack quack quack quack quack 
quack quack quack quack quack quack quack quack quack quack quack quack quack quack quack quack quack quack quack quack quack quack quack 
quack quack quack quack quack quack quack quack 
quack quack quack quack quack quack quack quack 
quack quack quack quack quack quack quack quack 
quack quack quack quack quack quack quack quack 
quack quack quack quack quack quack quack quack 
quack quack quack quack quack quack quack quack quack quack quack quack quack quack quack quack quack quack quack quack 
quack quack quack quack quack quack quack quack 
```
yep, happy quacking. 



**feedback appreciated -Snowflake#3636**
