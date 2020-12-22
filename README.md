<h1 align="center">MONTY INTERPRETER</h1>
<p align="center"><img src="http://montyscoconut.github.io/assets/media/coconut.png" alt="Girl in a jacket" width="200" height="200"></p>

**Monty** 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project was to create an interpreter for Monty ByteCodes files in C language.

<h2 align="center">SYNOPSIS</h2>

**Monty byte code files**

Files containing Monty byte codes usually have the `.m` extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:
```
user@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
user@ubuntu:~/monty$
```

<h2 align="center">HOW TO USE</h2>

**Clone**
```
git clone https://github.com/danielfep03/monty.git
```
**Compilation**
```
gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```
**Execution**
```
./monty monty_file.m
```
<h2 align="center">EXAMPLE</h2>

```
test@ubuntu:~/monty$ cat bytecodes/01.m 
push 1
push 2
push 3
pall
add
pall

est@ubuntu:~/monty$ ./monty bytecodes/01.m 
3
2
1
5
1
test@ubuntu:~/monty$
```


The bytecodes that can be interpreted by the program are the following:
|Opcode| Description |
|--|--|
| push | Pushes an element to the stack
| pall | Prints all the values on the stack, starting from the top of the stack |
| pint | Prints the value at the top of the stack, followed by a new line |
| pop | Removes the top element of the stack |
| swap | Swaps the top two elements of the stack |
| add | Adds the top two elements of the stack |
| nop | Doesn’t do anything |
| sub | Subtracts the top element of the stack from the second top element of the stack |
| div | Divides the second top element of the stack by the top element of the stack. |
| mul | Multiplies the second top element of the stack with the top element of the stack |
| mod | Computes the rest of the division of the second top element of the stack by the top element of the stack |
| pchar | Prints the char at the top of the stack, followed by a new line |
| pstr | Prints the string starting at the top of the stack, followed by a new line |
| rotl | Rotates the stack to the top |
| rotr | Rotates the stack to the bottom |
| stack | Sets the format of the data to a stack (LIFO). This is the default behavior of the program |
| queue | sets the format of the data to a queue (FIFO) |

<h2 align="center">AUTHOR</h2>

  **Daniel Amado**
<a href="https://twitter.com/DanielFep_am"><img border="0" alt="W3Schools" src="https://help.twitter.com/content/dam/help-twitter/brand/logo.png" width="30" height="30"></a>

