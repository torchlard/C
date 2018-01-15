all: run #clean
2darray: 2darray.o
	gcc 2darray.o -o 2darray
2darray.o: 2darray.c
	gcc -c 2darray.c -o 2darray.o
clean:
	rm -f 2darray.o
run: 2darray
	./2darray

# .PHONY: clean
.PHONY: all run
