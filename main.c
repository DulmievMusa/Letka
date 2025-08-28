#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include "tests.h"
#include "macros.h"
#include "my_asserts.h"
#include <string.h>
#include "main.h"
#include "consts.h"
#include "calculate_functions.h"
#include "string_functions.h"

// strlen strcpy strcat strcmp strchr strstr strdup


int main(int number_of_arguments, char *argument_values[]) {
    Meow();
    if (number_of_arguments > 1) {
        if (CompareTwoStrings(argument_values[1], "--test")) {
            RunTests();
        }
    }
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    Greeting(&a, &b, &c);

    int n_roots = GeneralCaseSolve(a, b, c, &x1, &x2); // Решение уравнения
    
    PrintRoots(n_roots, x1, x2);
    return 0;
}


void Greeting(double* a, double *b, double *c) {
    printf("This program solve quad. equation ax^2+bx+c=0\n");
    printf("Input coefficient a, coefficient b, coefficient c in different lines:\n");
    
    InputCoefficients(a, b, c);

    printf("You have entered: a: %lg, b: %lg c: %lg\n", *a, *b, *c);
}

void Meow() {
    printf(TEST_FALED_ANSI "Meeeeeeeeeeeeooooooooow Meow Meow" RESET_ANSI "\n");
}


int InputCoefficients(double* a, double* b, double* c) {
    
    MyAssert(a != NULL);
    MyAssert(b != NULL);
    MyAssert(c != NULL);
    MyAssert(a != b && b != c && a != c);

    char array_of_symbols[] = {'a', 'b', 'c'};
    double* array_of_variables[] = {a, b, c};
    for (int i = 0; i < 3; i++) {
        printf("%c: ", array_of_symbols[i]);
        InputNumber(array_of_variables[i], array_of_symbols[i]);        
    }
    return 0;
}


int InputNumber(double* a, char symbol) { // TODO: better name? InputNumberEnsuringCorrectness (or just InputNumber)

    MyAssert(a != NULL);
    int count = scanf("%lg", a);
    while (count == 0 || (count == 1 && (getchar() != '\n'))) {
        printf("You entered not a number. Try again\n");
        printf("%c: ", symbol);
        ClearBuffer();
        count = scanf("%lg", a);
    }
    return 0;
}


void PrintRoots(int n, double x1, double x2) {
    
    MyAssert(isfinite(x1));

    double roots[] = {x1, x2};

    if (n > -1) {
        printf("Equation has %d root(s): \n", n);
        for (int i = 0; i < n; ++ i) {
            printf("x%d = %lg\n", i + 1, roots[i]);
        }
    }
    else {
        printf("Every number is a root");
    }
}









