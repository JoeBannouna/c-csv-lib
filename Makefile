all: main.o src/csvfile.o src/vector.o src/utils.o
	gcc -Wall $^ -o output && ./output

clean:
	rm src/*.o *.o output -f