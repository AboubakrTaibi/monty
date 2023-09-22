# hello
<style>
H1{color:Blue !important;}
H2{color:DarkOrange !important;}
p{color:Black !important;}
</style>

<style>H1{color:Blue;}</style>
<style>H2{color:DarkOrange;}</style>
<style>p{color:Black;}</style>

# Monty: Stacks and Queues - LIFO, FIFO


## Introduction
Monty is a minimalistic programming language that operates on a stack or queue of integers. It reads Monty bytecode files, interprets the commands, and executes them accordingly. The primary goal of this project is to provide a clear and concise implementation of Stacks and Queues, helping users grasp their functionality and use cases.

## Getting Started

#### Clone the Monty repository :
$ git clone https://github.com/nisselhbb/monty.git

#### Compile the Monty interpreter:
+$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty

#### Run Monty with a Monty bytecode file:
+$ ./monty monty_bytecode.m


#### Example: Simple Stack Operations
- push 1
- push 2
- push 3
- pall
- pop
- pall
- pint
- swap
- add
- div
- mul
- mod
- sub
- stack
- queue

## License

This project is licensed under the GNU General Public License (GPL)