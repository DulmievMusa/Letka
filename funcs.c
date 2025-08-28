// TODO: funcs.c is also not a good name

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include "funcs.h"
#include "macros.h"
#include "my_asserts.h"
#include "main.h"


const double ACCURACY = 1e-6;
const int INFINITE_ROOTS = -1;


//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Calculate discriminant // TODO: add more info, e.g. what values coefficients can have? Also, move docs to header file
//!
//! @param [in] n number
//!
//! @return Calculated discriminant
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
double CalculateDiscriminant(double a, double b, double c) {
    MyAssert(isfinite(a));
    MyAssert(isfinite(b));
    MyAssert(isfinite(c));

    return b*b - 4*a*c;
}

//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Checks whether two numbers are the same, taking into account the calculation error
//!
//! @param [in]  first first number
//! @param [in]  second second number
//!
//! @return if two numbers match true, else false
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
bool IsItThisNumber(double first, double second) {

    MyAssert(isfinite(first));
    MyAssert(isfinite(second));

    if (first * second < 0) {
        return false;
    }
    double diff = Abs(first - second);
    return diff < ACCURACY;
}


//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Returns the modulus of a number
//!
//! @param [in]  n number
//!
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
double Abs(double n) {

    MyAssert(isfinite(n));

    if (n < 0) {
        n = -n;
    }
    return n;
}



//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Solves a square equation ax2 + bx + c = 0
// TODO: more info, e.g.
// How it solves it? Analytically? Or with Newton's method? Or some other way?
// Is it fast?
// Does it require coefficients to have certain values? E.g. what happens if a is NAN or INF?
//!
//!
//! @param [in]  a   a‐coefficient
//! @param [in]  b   b‐coefficient
//! @param [in]  c   c‐coefficient
//! @param [out] x1  Pointer to the 1st root
//! @param [out] x2  Pointer to the 2nd root
//!
//! @return Number of roots
//!
//! @note   In case of infinite number of roots,
//!         returns INFINITE_ROOTS.
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
int GeneralCaseSolve(double a, double b, double c, double* x1, double* x2) {
    
    MyAssert(isfinite(a));
    MyAssert(isfinite(b));
    MyAssert(isfinite(c));

    MyAssert(x1 != NULL);
    MyAssert(x2 != NULL);
    MyAssert(x1 != x2);
    *x1 = 0; // HERE
    *x2 = 0; // HERE

    if (IsItThisNumber(a, 0)) { //Если a == 0
        return LinearEquationSolve(b, c, x1, x2);
    } else { // Если a != 0
        return QuadraticEquationSolve(a, b, c, x1, x2);
    } 

}


//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Solves a square equation bx + c = 0
//!
//!
//! @param [in]  b   b‐coefficient
//! @param [in]  c   c‐coefficient
//! @param [out] x1  Pointer to the 1st root
//! @param [out] x2  Pointer to the 2nd root
//!
//! @return Number of roots
//!
//! @note   In case of infinite number of roots,
//!         returns SS_INF_ROOTS.
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
int LinearEquationSolve(double b, double c, double* x1, double* x2) {

    MyAssert(isfinite(b));
    MyAssert(isfinite(c));

    MyAssert(x1 != NULL);
    MyAssert(x2 != NULL);
    MyAssert(x1 != x2);

    if (!IsItThisNumber(b, 0)) { // Если b != 0
        *x1 = Abs(-c / b); // TODO: indentation
        *x2 = NAN; // HERE
        return 1;
    } 
    else { // Если b == 0
        if (!IsItThisNumber(c, 0)) { // Если с != 0
            return 0;
        } else { // Если c == 0
            return INFINITE_ROOTS; // Бесконечное количество корней
        }
    }
}


//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Solves a square equation ax2 + bx + c = 0 when a != 0
//!
//!
//! @param [in]  a   a‐coefficient
//! @param [in]  b   b‐coefficient
//! @param [in]  c   c‐coefficient
//! @param [out] x1  Pointer to the 1st root
//! @param [out] x2  Pointer to the 2nd root
//!
//! @return Number of roots
//!
//! @note   In case of infinite number of roots,
//!         returns INFINITE_ROOTS.
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
int QuadraticEquationSolve(double a, double b, double c, double* x1, double* x2) {

    MyAssert(isfinite(a));
    MyAssert(isfinite(b));
    MyAssert(isfinite(c));

    MyAssert(x1 != NULL);
    MyAssert(x2 != NULL);
    MyAssert(x1 != x2); 

    double discriminant = CalculateDiscriminant(a, b, c);
    
    if (discriminant > 0) {
        double sqrt_dis = sqrt(discriminant);
        *x1 = (-b + sqrt_dis) / (2*a);
        *x2 = (-b - sqrt_dis) / (2*a);
        return 2;
    } else if (IsItThisNumber(discriminant, 0)) {
        *x1 = *x2 = -b / (2*a);
        return 1;
    } else {
        return 0;
    }
}


//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Sorts two roots in ascending order. The first becomes smaller than the second.
//!
//!
//! @param [out] x1  Pointer to the 1st root
//! @param [out] x2  Pointer to the 2nd root
//!
//! @return have the roots been sorted (true or false)
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
bool SortAscending(double* x1, double* x2) {
    if (*x2 == NAN) {
        return false;
    }
    double buffer = 0;
    if (*x1 > *x2) {
        buffer = *x2;
        *x2 = *x1;
        *x1 = buffer;
        return true;
    } else {
        return false;
    }
}

int ClearBuffer() {
    char ch = getchar();
    while (ch != '\n' && ch != EOF){
        ch = getchar();}
}


bool CompareTwoStrings(char* first_st, const char* second_st) {
    int first_size = FindStringLength(first_st);
    int second_size = FindStringLength(second_st);
    if (first_size != second_size) {
        return false;
    }
    for (int i = 0; i < second_size; i++) {
        if (first_st[i] != second_st[i]) {
            printf("\n%c %c\n", first_st[i], second_st[i]);
            return false;
        }
    }
    return true;
}


int FindStringLength(const char* string) {
    int index = 0;
    while (string[index] != '\0') {
        index++;
    }
    return index;
}


void Greeting(double* a, double *b, double *c, double* x1, double* x2) {
    printf("This program solve quad. equation ax^2+bx+c=0\n");
    printf("Input coefficient a, coefficient b, coefficient c in different lines:\n");
    
    InputCoefficients(a, b, c);

    printf("You have entered: a: %lg, b: %lg c: %lg\n", *a, *b, *c);
}

void Meow() {
    printf(TEST_FALED_ANSI "Meeeeeeeeeeeeooooooooow Meow Meow" RESET_ANSI "\n");
}