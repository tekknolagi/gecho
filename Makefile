all:
	gcc stack.c -o stack

clean:
	rm stack

manpage.1: manpage.sgml
	docbook-to-man $< > $@