Compilation_Flags_W = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

main.exe : main.o calculate_functions.o string_functions.o tests.o my_asserts.o 
		g++ $^ ${Compilation_Flags_W} -o main.exe

run: main.exe
	.\main.exe

%.o: %.c
	g++ ${Compilation_Flags_W} -c $< -o $@

clean:
	rm main.exe *.o

main.o: main.h consts.h calculate_functions.h string_functions.h