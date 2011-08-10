all:
	$(COMPILER) src/stack.c -o stack

clean:
	-rm stack *~

install:
	mv stack /usr/bin/