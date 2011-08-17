This stack-based language is very similar to FORTH.

# Install

1. `make CC=<compiler of choice>`
    * You can use whatever C compiler you want, defaults to `cc`
2. `sudo make install`
    * Moves it to `/usr/bin/`

# Stack Theory

Think of a stack of books. It starts of empty.

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

`1 2 +`

would push `1`, then push `2`, then pop them both and add them. It will then push the result onto the stack. The stack now looks like this:

`[ 3 ]`

That's stack theory.

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


14. `<varname>`
    * REMOVED FOR NOW. DO NOT USE.
    * Pop element from stack; set `<varname>` to popped value.


15. `wover`
    * a = pop(); b = pop(); push(b); push(a); push(b);
    * ( a1 a2 -- a1 a2 a1)
16. `drop`
    * Pop top element from stack, show value.
17. `top`
    * Push the index of the top of the stack to the stack.
18. `outascii`
    * Pop top element of stack and print ASCII character that corresponds to decimal.
19. `allascii`
    * Pop all elements of stack and prints ASCII characters that correspond to decimal.
20. `/`
    * Pop top two elements from stack; divide lower element by upper element.
21. `@`
    * Ah, we have modes now. Modes are announced with `@`. `@<mode>` toggles `<mode>`.


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

# Modes

1. `transparent`
    * Shows the stack after every command.
2. `default`
    * Regular interpreter settings.
3. `separate`
    * Separates the commands with a dashed (`-`) line. Recommended for use with `transparent`.