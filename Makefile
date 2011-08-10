all:
	$(CC) src/stack.c -o stack

clean:
	-rm -f stack *~

install:
	mv stack /usr/bin/