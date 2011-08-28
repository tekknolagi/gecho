gecho is somewhat similar to FORTH. It will probably become less so as it grows.

# Install

/*
PRECURSOR

1. Install libgmp. Doesn't matter how, just do it properly.
*/

Not yet. GMP coming soon!

Three Options...

FIRST

1. `make CC=<compiler of choice>`
    * You can use whatever C compiler you want, defaults to `cc`
2. `sudo make install`.
    * Moves it to `/usr/bin/`.

SECOND

1. `sudo make go CC=<compiler of choice>`
    * Just makes and cleans up and moves it to `/usr/bin/` for you. Compiler defaults to `cc`.

THIRD

1. `sudo make do-all CC=<compiler of choice>`
    * Compiles and installs both interpreter and compiler. Compiler defaults to `cc`.

# Stack Theory

Think of a stack of books. It starts off empty.

`[ ]`

However, when you put (or `push`) a book (number) onto the stack, it gets added to the top.

`[ 12 ]`

Keep adding numbers, and it will soon look like this.

`[ 12, 4, 8, 3 ]`

Note that `3` is at the top of the stack, and `12` is at the bottom.

One can also take off (or `pop`) elements from the stack.

`[ 12, 4, 8 ]`

`> 3.00`

The number gets returned as a result of popping it.

Operands can pop numbers from the stack and interact with them. For example,

`.. 1 2 +`

would clear the stack, push `1`, then push `2`, then pop them both and add them. It will then push the result onto the stack. The stack now looks like this:

`[ 3 ]`

That's stack theory.

# The Interpreter

1. SHELL
    * just run `gecho` (or `./gecho`)

2. FILE READ
    * run `gecho <filename>` (or `./gecho <filename>`)
    * MUST have `END` at end of file!

3. FILE READ THEN SHELL
    * run `gecho <filename> --shell` (or `./gecho <filename> --shell`)
    * MUST have `END` at end of file!

4. COMPILE GECHO
    * run `gechoc <filename>`
    * run `<compiler of choice> <filename> -o <filename> -lm`
    * run `<filename>`

#### Whitespace does not matter!

# Commands

1. `+`
    * Pops two elements from the stack, adds them together, and pushes the result.
2. `++`
    * Pops all the elements from the stack and adds them together; pushes result.
3. `.`
    * Prints the top element in the stack.
4. `*`
    * Pops two elements from the stack, multiplies them, and pushes the result.
5. `..`
    * Pops all elements from the stack.
6. `show`
    * Pretty prints the stack.
7. `dup`
    * Pushes a copy of the top element of the stack.
8. `swap`
    * Pops two elements from the stack, and pushes back in each other's places.
9. `-`
    * Pops two elements from the stack, subtracts the upper from the lower, and pushes the result.
10. `jump`
    * Pops an element from the stack (a) and prints stack[a]
11. `range`
    * Pops two elements from the stack (a, b) and prints range(b, a); starts at b, increments by one until a, pushes the array onto the stack.
12. `<num>`
    * Pushes `<num>` to the stack.
13. `**`
    * Pops all the elements from the stack and multiplies them; pushes result.
14. `!<varnum>`
    * Pop element from stack; set `variables[<varnum>]` to popped value.
15. `&<varnum>`
    * Push `variables[<varnum>]` to the stack.
15. `wover`
    * a = pop(); b = pop(); push(b); push(a); push(b);
    * ( a1 a2 -- a1 a2 a1)
16. `drop` || `pop`
    * Pop top element from stack, show value.
17. `top`
    * Push the index of the top of the stack to the stack.
18. `outascii`
    * Pop top element of stack and print ASCII character that corresponds to decimal.
19. `allascii`
    * Pop all elements of stack and prints ASCII characters that correspond to decimal.
20. `/`
    * Pop top two elements from stack; divide lower element by upper element.
21. `@<mode>`
    * Toggles `<mode>`.
22. `mode`
    * Prints a list of all enabled modes.
23. `modes`
    * Prints all modes, complete with 'enabled' flag.
24. `tot`
    * For use with `@tracker`. Prints number of commands so far. Does not count as a command.
25. `reset`
    * Resets the command count. For use with `@tracker`. Does not count as a command.
26. `tan`
    * Pops one element from the stack (degrees!) computes `tan(x)`
27. `sin`
    * Pops one element from the stack and computes `sin(x)`
28. `cos`
    * Pops one element from the stack and computes `cos(x)`
29. `pow`
    * a = pop(); b = pop(); push(b^a);
30. `mod`
    * a = pop(); b = pop(); push(b%a);
31. `pi`
    * Pushes a good approximation of pi to the stack.
32. `read`
    * Reads user input. Only really useful with file reading/compiling. Pops one element from the stack and reads that number of numbers, and pushes them to the stack. 


# Examples

1. `1 2 3 + .` == `5`

2. `1 2 3 ++ .` == `6`

3. `1 2 3 * .` == `6`

4. `1 2 3 4 .. show` == `[ ]`

5. `1 2 dup show` == `[ 1, 2, 2 ]`

6. `1 2 - .` == `-1`

7. `0 10 range 3 jump` == `4`

8. `1 5 range ** .` == `120`
	** Factorial :)

9. `3 4 5 ++ a` == `None`
    ** Doesn't return anything; sets `a` to the sum of `3, 4, 5`

10. `1 1 dup wover + dup wover + dup wover + show` == `[ 1, 1, 2, 3, 5 ]`
    ** Fibonacci :)

11. `1 2 3 4 show drop show` == `[1, 2, 3, 4], [1, 2, 3]`

12. `1 2 3 top .` == `2`

13. `97 97 25 + range allascii` == `abc...z`

14. `97 98 99 outascii outascii outascii` == `cba`

15. `1 2 / .` == `0.5`

16. `@transparent` == shows stack after every command

17. `45 tan .` == `1.00`

18. `pi 2 * cos .` == `0.99` (truncated, not rounded)

19. `3 read` == reads 3 numbers and pops them to the stack

# Modes

1. `transparent`
    * Shows the stack after every command.
2. `default`
    * Regular interpreter settings.
3. `tracker`
    * After being enabled, counts the commands entered. Can be viewed with `tot`.
