
all:
	ld -b binary -r archive.tar -o archive.o
	ld  -b binary -r script.sh -o script.o
	g++ out.cpp -c
	g++ *.o -o exe

clean:
	rm *.o exec *.live.* exe || true

.PHONY: all

