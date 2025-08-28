main.exe : main.o calculate_functions.o string_functions.o tests.o my_asserts.o 
		g++  -o main.exe main.o tests.o my_asserts.o calculate_functions.o string_functions.o

main.o: main.c calculate_functions.h string_functions.h tests.h macros.h consts.h
	g++  -c main.c

calculate_functions.o: calculate_functions.c calculate_functions.h macros.h consts.h
	g++ -c calculate_functions.c -o calculate_functions.o

string_functions.o: string_functions.c string_functions.h macros.h consts.h
	g++ -c string_functions.c -o string_functions.o

tests.o: tests.c tests.h macros.h consts.h
	g++ -c tests.c -o tests.o

my_asserts.o: my_asserts.c my_asserts.h macros.h consts.h
	g++ -c my_asserts.c -o my_asserts.o

clean:
	rm main.exe *.o