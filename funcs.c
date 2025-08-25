#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define NDEBUG
#include <assert.h>
#include <stdlib.h>
#include "funcs.h"

const double ACCURACY = 1e-4;
const int INFINITE_ROOTS = -1;

// ANSI escape sequences
// C predefined macros
// __pretty_function__
// реализовать свой assert

// NDEBUG - значит что дебага НЕТ

//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Calculate discriminant
//!
//! @param [in] n number
//!
//! @return Calculated discriminant
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
double CalculateDiscriminant(double a, double b, double c) {
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

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

    assert(isfinite(first));
    assert(isfinite(second));

    if (first * second < 0) {
        return false;
    }
    double diff = Abs(first - second);
    if (diff >= ACCURACY) {
        return false;
    } else {
        return true;
    }
}

//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Returns the modulus of a number
//!
//! @param [in]  n number
//!
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
double Abs(double n) {

    assert(isfinite(n));

    if (n < 0) {
        n = -n;
    }
    return n;
}



//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Solves a square equation ax2 + bx + c = 0
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
    
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);
    *x1 = 0; // Удалить, если всё сломалось
    *x2 = 0; // Удалить, если всё сломалось 

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

    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    if (!IsItThisNumber(b, 0)) { // Если b != 0
            *x1 = Abs(-c / b);
            *x2 = NAN;
            return 1;
        } else { // Если b == 0
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

    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2); 

    double dis = 0;
    dis = CalculateDiscriminant(a, b, c);
    if (dis > 0) {
        double sqrt_dis = sqrt(dis);
        *x1 = (-b + sqrt_dis) / (2*a);
        *x2 = (-b - sqrt_dis) / (2*a);
        return 2;
    } else if (IsItThisNumber(dis, 0)) {
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
bool SortRootsRising(double* x1, double* x2) {
    if (*x2 == NAN) { // *
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


int MyAssert(int result) {
    if (result) {
        printf("\033[41;97mAssertion failed: file: %s, line %d\033[0m\n", __FILE__, __LINE__);
        return 1;
    }
    return 0;
}