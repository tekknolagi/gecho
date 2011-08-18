all:
	$(CC) src/gecho.c -o gecho

clean:
	-rm -f gecho *~

install:
	mv gecho /usr/bin/
	make clean

go:
	make
	sudo make install
