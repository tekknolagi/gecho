all:
	$(CC) src/gecho.c -o gecho

clean:
	-rm -f gecho *~

install:
	mv gecho /usr/bin/
