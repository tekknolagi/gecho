all:
	$(CC) src/gecho.c -o gecho
clean:
	-rm -f gecho *~ gechoc
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
gechoc:
	$(CC) src/gechoc.c -o gechoc
	-mkdir /usr/include/gecho/
	cp src/*.h /usr/include/gecho/
install-gechoc:
	mv gechoc /usr/bin/
	make clean
do-all:
	sudo make go
	sudo make gechoc
	sudo make install-gechoc
