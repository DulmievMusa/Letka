#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define NDEBUG
#include <assert.h>
#include <stdlib.h>
#include "tests.h"
#include "funcs.h"


const double ACCURACY = 1e-4;
const int INFINITE_ROOTS = -1;

int CorrectInputNumber(double* a, char symbol);
int InputCoefficients(double* a, double* b, double* c);
int PrintRoots(int n, double x1, double x2);


int main() {
    RunTests();
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    int n = 0, flag = 0;
    printf("This program solve quad. equation ax^2+bx+c=0\n");
    printf("Input coefficient a, coefficient b, coefficient c in different lines:\n");
    
    InputCoefficients(&a, &b, &c);

    printf("You have entered: a: %lg, b: %lg c: %lg\n", a, b, c);

    n = GeneralCaseSolve(a, b, c, &x1, &x2); // Решение уравнения
    
    PrintRoots(n, x1, x2);

    return 0;
}

//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Enters values ​​from the keyboard into variables a, b, c
//!
//! @param [out] a  coefficient a
//! @param [out] b  coefficient b
//! @param [out] c  coefficient c
//!
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
int InputCoefficients(double* a, double* b, double* c) {
    
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);

    assert(a != b && b != c && a != c);

    printf("a: ");
    CorrectInputNumber(a, 'a');
    printf("b: ");
    CorrectInputNumber(b, 'b');
    printf("c: ");
    CorrectInputNumber(c, 'c');
    return 0;
}

//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Enters value ​​from the keyboard into variables and asks again if the user entered something other than a number
//!
//! @param [out] a  one coefficient
//!
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
int CorrectInputNumber(double* a, char symbol) {

    assert(a != NULL);

    int ch;
    while (scanf("%lg", a) == 0) { // NOTE: scanf("%lg%c", a, symbol)... symbol == '\n'?
        printf("You entered not a number. Try again\n");
        printf("%c: ", symbol);
        ch = getchar();
        while (ch != '\n' && ch != EOF)
            ch = getchar();
    }
    ch = getchar();
    if (ch != '\n' &&  ch != EOF) { // TODO: why do you require two newlines in a row?
        CorrectInputNumber(a, symbol);
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
    
    assert(isfinite(x1));
    assert(isfinite(x2));

    switch (n) {
        case 2: 
            printf("Equation have two roots:\nx1=%g\nx2=%g", x1, x2);
            break;
        case 1:
            printf("Equation have one root:\nx=%g", x1);
            break;
        case 0:
            printf("Equation have no roots");
            break;
        case -1:
            printf("Equation have infinite roots");
            break;
    }
}