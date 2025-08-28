#ifndef FUNCS_H
#define FUNCS_H

// TODO: header guards, read about them in K&R
//     B2.h
//   /     \
// A.h     C.h
//   \     /
//     B1.h

// TODO: funcs.h is not a good name, separate functions in more files if necessary and name them appropriately, accrodingly to their function, not semantics


//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Calculate discriminant
//!
//! @param [out] a  coefficient a
//! @param [out] b  coefficient b
//! @param [out] c  coefficient c
//!
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
double CalculateDiscriminant(double a, double b, double c);

//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Checks whether two numbers are the same, taking into account the calculation error
//!
//! @param [in]  first first number
//! @param [in]  second second number
//!
//! @return if two numbers match true, else false
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
bool IsItThisNumber(double first, double second);

//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! returns the modulus of a number
//!
//! @param [out] first  first number
//! @param [out] second  second number
//!
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
double Abs(double n);
int GeneralCaseSolve(double a, double b, double c, double* x1, double* x2);
int LinearEquationSolve(double b, double c, double* x1, double* x2);
int QuadraticEquationSolve(double a, double b, double c, double* x1, double* x2);
bool SortAscending(double* x1, double* x2);
int AssertOfMusa(int result, const char *file, const char *function, int line);
int ClearBuffer();
bool CompareTwoStrings(char* first_st, const char* second_st);
int FindStringLength(const char* string);
void Greeting(double* a, double *b, double *c, double* x1, double* x2);
void Meow();

#endif
