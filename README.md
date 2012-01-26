# gecho

WARNING: `float` is imprecise, and shortly I will be moving everything over to bignum. Large numbers will come out incorrect! (ex. 170 factorial)

gecho is somewhat similar to FORTH. It will probably become less so as it grows.

## Install

### IF ON A MAC

1. compile with `sudo make do-all CC=<compiler of choice> INAME=<what you want gecho to be called> CNAME=<what you want gechoc to be called>`
    * CC defaults to `cc` and INAME/CNAME default to `gecho` and `gechoc`, respectively

OR

1. `sudo make CC=<compiler of choice>`
    * Just compiles.

## Three Options...

### FIRST

1. `make CC=<compiler of choice>`
    * You can use whatever C compiler you want, defaults to `cc`
2. `sudo make install`.
    * Moves it to `/usr/bin/`.

### SECOND

1. `sudo make go CC=<compiler of choice>`
    * Just makes and cleans up and moves it to `/usr/bin/` for you. Compiler defaults to `cc`.

### THIRD

1. `sudo make do-all CC=<compiler of choice>`
    * Compiles and installs both interpreter and compiler. Compiler defaults to `cc`.

## Stack Theory

Think of a stack of books. It starts off empty.

`[ ]`

However, when you put (or `push`) a book (number) onto the stack, it gets added to the top.

`[ 12 ]`

Keep adding numbers, and it will soon look like this.

`[ 12, 4, 8, 3 ]`

Note that `3` is at the top of the stack, and `12` is at the bottom.

One can also take off (or `pop`) elements from the stack.

`[ 12, 4, 8 ]`

`3.00`

The number gets returned as a result of popping it.

Operands can pop numbers from the stack and interact with them. For example,

`dels 1 2 +`

would clear the stack, push `1`, then push `2`, then pop them both and add them. It will then push the result onto the stack. The stack now looks like this:

`[ 3 ]`

That's stack theory.

## The Interpreter

#### If on a Mac, just replace `gecho` with `gecho-mac` and `gechoc` with `gechoc-mac`

1. SHELL
    * just run `gecho` (or `./gecho`)

2. FILE READ
    * run `gecho -f <filename>` (or `./gecho -f <filename>`)

3. FILE READ THEN SHELL
    * run `gecho -sf <filename>` (or `./gecho -sf <filename>`)

4. COMPILE GECHO
    * run `gechoc <filename>`
    * run `<compiler of choice> <filename> -o <filename> -lm`
    * run `<filename>`

#### Whitespace does not matter!

## Commands

1. `+`
    * Pops two elements from the stack, adds them together, and pushes the result.
2. `++`
    * Pops all the elements from the stack and adds them together; pushes result.
3. `.`
    * Prints the top element in the stack.
4. `*`
    * Pops two elements from the stack, multiplies them, and pushes the result.
5. `dels`
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
19. `print`
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
32. `read`
    * Reads user input. Only really useful with file reading/compiling. Pops one element from the stack and reads that number of numbers, and pushes them to the stack. 
33. `<`
    * b = pop(); a = pop(); push(`a < b`);
34. `>`
    * `a > b`
35. `>=`
    * `a >= b`
36. `<=`
    * `a <= b`
37. `=`
    * `a == b`
38. `'<word>`
    * Push each character of `<word>` onto the stack.
39. `<>`
    * Push ' ' to the stack.
40. `and`
    * Push `a && b` to the stack.
41. `or`
    * Push `a || b` to the stack.
42. `nil`
    * Does absolutely nothing.
43. `next`
    * Moves to the next stack (out of 3). Starts at stack 0.
44. `back`
    * Moves one stack back (out of 3) in a cycle. If it goes past 0, it will cycle to stack 3.
45. `mv`
    * Moves the top element from the current stack to the next stack. To COPY, use `dup mv`.

## Modes

1. `transparent`
    * Shows the stack after every command.
2. `default`
    * Regular interpreter settings.
3. `tracker`
    * After being enabled, counts the commands entered. Can be viewed with `tot`.

## Constants

1. `#t` == `#true`
    * `1`
2. `#f` == `#false`
    * `0`
3. `#pi`
    * the value `pi`
4. `#e`
    * the value `e`
5. `#phi`
    * the value `phi`

## Command-line Flags

1. `-f`
    * Input file to compile/read. Must come after another flag. (e.g. `-fs` won't work but `-sf` will)
1. `-e`
    * Skip the version and "bye" message. If passing something to gecho, end it with "exit" so it doesn't evaluate endlessly.
2. `-v`
    * Just print the version information.
3. `-s`
    * Can enter shell mode after evaluating the file. Also suppresses the version and package name.


## Examples

1. `1 2 3 + .` == `5`

2. `1 2 3 ++ .` == `6`

3. `1 2 3 * .` == `6`

4. `1 2 3 4 dels show` == `[ ]`

5. `1 2 dup show` == `[ 1, 2, 2 ]`

6. `1 2 - .` == `-1`

7. `0 10 range 3 jump` == `4`

8. `1 5 range ** .` == `120`
    * Factorial :)

9. `3 4 5 ++ !1` == `None`
    * Doesn't return anything; sets `globals[1]` to the sum of `3, 4, 5`

10. `0 1 dup wover + dup wover + dup wover + show` == `[ 1, 1, 2, 3, 5 ]`
    * Fibonacci :)

11. `1 2 3 4 show drop show` == `[1, 2, 3, 4], [1, 2, 3]`

12. `1 2 3 top .` == `2`

15. `1 2 / .` == `0.5`

16. `@transparent` == shows stack after every command

17. `45 tan .` == `1.00`

18. `#pi 2 * cos .` == `0.99` (truncated, not rounded)

19. `3 read` == reads 3 numbers and pops them to the stack

20. `15 5 + 10 dup + = #t = .` == `((15+5) == (10+10)) == #t`?

21. `'Hello, <> 'world! print` == `Hello, world!`

22. `1 2 + show next 3 4 + show back mv + show` => Adds 1+2 on the first stack, shows it, adds 3+4 on the next stack, shows it, moves the top item on the first stack to the second stack, then adds 7 and 3 together to make 10.
