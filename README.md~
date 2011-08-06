This stack-based language is very similar to FORTH.

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
    * Pops two elements from the stack, subtracts the second from the first, and pushes the result.
10. `jump`
    * Pops an element from the stack (a) and prints stack[a]
11. `range`
    * Pops two elements from the stack (a, b) and prints range(b, a); starts at b, increments by one until a, pushes the array onto the stack.
12. `<NUM>`
    * Pushes `<NUM>` to the stack.
13. `**`
    * Pops all the elements from the stack and multiplies them; pushes result.
14. `<varname>`
    * Pop element from stack; set variable to popped value.
15. `wover`
    * a = pop(); b = pop(); push(b); push(a); push(b);
    * ( a1 a2 -- a1 a2 a1)

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