all:
	$(CC) src/gecho.c -o gecho
clean:
	-rm -f gecho *~
install:
	mv gecho /usr/bin/
	make clean
go:
	make clean
	make
	sudo make install
asm:
	$(CC) src/gecho.c -o gecho.s -S
	$(CC) gecho.s -o gecho
go-asm:
	sudo make asm CC=$(CC)
	sudo make install
	sudo make clean
	rm -rf *.s
