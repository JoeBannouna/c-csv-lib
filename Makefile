all: main.o csvfile.o vector.o
	gcc -Wall vector.o csvfile.o main.o -o output && ./output

clean:
	rm *.o output