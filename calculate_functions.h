

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
bool CheckTwoNumbersMatch(double first_number, double second_number);

//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Return the modulus of a number
//!
//! @param [out] first  first number
//! @param [out] second  second number
//!
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
double Abs(double n);

//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Analytically solve a square equation ax2 + bx + c = 0.
//! If a != 0, it solves a quadratic equation(calls QuadraticEquationSolve function),
//! otherwise it solves a linear equation (calls LinearEquationSolve function).
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
//!         returns INFINITE_ROOTS (-1).
//!         If one of the arguments is NAN or INF, then MyAssert is called and the program terminates.
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
int GeneralCaseSolve(double a, double b, double c, double* x1, double* x2);

//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Analitically solve a square equation bx + c = 0. It takes into account b == 0
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
//!         returns INFINITE_ROOTS (-1).
//!         If one of the arguments is NAN or INF, then MyAssert is called and the program terminates.
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
int LinearEquationSolve(double b, double c, double* x1, double* x2);

//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Analytically solves a square equation ax^2 + bx + c = 0. The coefficient a must not be equal to zero
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
//!         returns INFINITE_ROOTS (-1).
//!         If one of the arguments is NAN or INF, then MyAssert is called and the program terminates.
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
int QuadraticEquationSolve(double a, double b, double c, double* x1, double* x2);


//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Sort two numbers in ascending order. The first becomes smaller than the second.
//!
//! @param [out] x1  Pointer to the 1st root
//! @param [out] x2  Pointer to the 2nd root
//!
//! @return If sorting occurred, returns true, otherwise false
//!
//! @note if any of the arguments is NAN or INF, then MyAssert is called and the program terminates.
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
bool SortAscending(double* x1, double* x2);