#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include "tests.h"
#include "funcs.h"
#include "macros.h"



const double ACCURACY = 1e-4;
const int INFINITE_ROOTS = -1;

int CorrectInputNumber(double* a, char symbol);
int InputCoefficients(double* a, double* b, double* c);
int PrintRoots(int n, double x1, double x2);

// TODO: separate tests into separate file with separate main
int main() {
    RunTests();
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    int n = 0;
    printf("This program solve quad. equation ax^2+bx+c=0\n");
    printf("Input coefficient a, coefficient b, coefficient c in different lines:\n");
    
    InputCoefficients(&a, &b, &c);

    printf("You have entered: a: %lg, b: %lg c: %lg\n", a, b, c);

    n = GeneralCaseSolve(a, b, c, &x1, &x2); // Решение уравнения // TODO: bring declarations closer to uses, in this case it's better to declare it right here
    
    PrintRoots(n, x1, x2);

    return 0;
}

// TODO: Docs are usually written in imperative

//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Enters values ​​from the keyboard into variables a, b, c
//!
//! @param [out] a  coefficient a
//! @param [out] b  coefficient b
//! @param [out] c  coefficient c
//!
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
int InputCoefficients(double* a, double* b, double* c) {
    
    MyAssert(a != NULL);
    MyAssert(b != NULL);
    MyAssert(c != NULL);
    MyAssert(a != b && b != c && a != c);

    char array_of_symbols[] = {'a', 'b', 'c'};
    double* array_of_variables[] = {a, b, c};
    for (int i = 0; i < 3; i++) {
        printf("%c: ", array_of_symbols[i]);
        CorrectInputNumber(array_of_variables[i], array_of_symbols[i]);        
    }
    return 0;
}

//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Enters value ​​from a keyboard into variables and asks again if user entered something other than a number
//!
//! @param [out] a  one coefficient
//!
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
int CorrectInputNumber(double* a, char symbol) { // TODO: better name? InputNumberEnsuringCorrectness (or just InputNumber)

    MyAssert(a != NULL);
    int flag = scanf("%lg", a);
    while (flag == 0 || (flag == 1 && (getchar() != '\n'))) {
        printf("You entered not a number. Try again\n");
        printf("%c: ", symbol);
        ClearBuffer();
        flag = scanf("%lg", a);
        
    }
    return 0;
}

//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Outputs the roots of the equation to the console
//!
//! @param [in] n count of roots  
//! @param [in] x1 first root
//! @param [in] x2 second root 
//!
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
int PrintRoots(int n, double x1, double x2) {
    
    MyAssert(isfinite(x1));

    double roots[] = {x1, x2};

    if (n > -1) {
        printf("Equation has %d root(s): \n", n);
        for (int i = 0; i < n; ++ i) {
            printf("x%d = %lg\n", i + 1, roots[i]);
        }
    }
    else {
        printf("Every number is a root");}
}