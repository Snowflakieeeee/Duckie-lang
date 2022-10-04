# Duckie lang
 A mostly esoteric programming language created in C (for extra suffereing for the developer), formerly in python

only command ==> "quack" commands/strings other than this should not be compiled (intended)
SI --> stack pointer (always pointing on the next cell on stack)
1 --> add `(SI-1 + SI-2 = SI) SI++`
2 --> sub `(SI-1 - SI-2 = SI) SI++`
3 --> mul `(SI-1 * SI-2 = SI) SI++`
4 --> div `(SI-1 / SI-2 = SI) SI++`
5 --> push to stack (next line is input for alphabet no. 0-26)
6 --> goto (next line for input line no.)
7 --> pop and print int on top of the stack (as is)
8 --> pop character and print character on top of the stack (convert ascii to char) // <32 ==> newline :: >127 ==> whitespace
9 --> take one char input and pushes onto stack (push ascii value)
10+ --> pushes literal number n-10 to stack (as is)


x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x

a proper quackity docs yet to be written, get ready for the suffering c:
