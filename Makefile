all: main.o csvfile.o
	gcc -Wall csvfile.o main.o -o output && ./output

clean:
	rm *.o output