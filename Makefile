


main.exe : main.o funcs.o tests.o my_asserts.o
		g++  -o main.exe main.o funcs.o tests.o my_asserts.o

main.o: main.c
	g++  -c main.c

funcs.o: funcs.c funcs.h
	g++ -c funcs.c -o funcs.o

tests.o: tests.c tests.h
	g++ -c tests.c -o tests.o

my_asserts.o: my_asserts.c my_asserts.h
	g++ -c my_asserts.c -o my_asserts.o

clean:
	rm main.exe *.o