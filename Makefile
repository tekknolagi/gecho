all:
	$(CC) src/gecho.c -o gecho -lm -Wall
clean:
	-rm -f gecho *~ gechoc
install:
	mv gecho /usr/bin/$(INAME)
	make clean
go:
	make clean
	make
	sudo make install INAME=$(INAME)
gechoc:
	$(CC) src/gechoc.c -o gechoc -lm -Wall
	rm -rf /usr/include/gecho/
	mkdir /usr/include/gecho/
	cp src/*.h /usr/include/gecho/
install-gechoc:
	mv gechoc /usr/bin/$(CNAME)
	make clean
do-all:
	sudo make go CC=$(CC) INAME=$(INAME)
	sudo make gechoc CC=$(CC)
	sudo make install-gechoc CNAME=$(CNAME)
mac-intel:
	make CC=$(CC)
	sudo make gechoc CC=$(CC)
	mv gecho precompiled/mac_intel/
	mv gechoc precompiled/mac_intel/
	make clean
