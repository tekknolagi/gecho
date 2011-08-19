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
	gcc src/gecho.c -o gecho.s -S
	gcc gecho.s -o gecho
install-asm:
	mv gecho /usr/bin/
go-asm:
	sudo make asm
	sudo make install-asm
	sudo make clean
	rm -rf *.s
