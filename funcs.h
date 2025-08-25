// TODO: header guards, read about them in K&R
//     B2.h
//   /     \
// A.h     C.h
//   \     /
//     B1.h

// TODO: funcs.h is not a good name, separate functions in more files if necessary and name them appropriately, accrodingly to their function, not semantics

double CalculateDiscriminant(double a, double b, double c);
bool IsItThisNumber(double first, double second);
double Abs(double n);
int GeneralCaseSolve(double a, double b, double c, double* x1, double* x2);
int LinearEquationSolve(double b, double c, double* x1, double* x2);
int QuadraticEquationSolve(double a, double b, double c, double* x1, double* x2);
bool SortRootsRising(double* x1, double* x2);
int AssertOfMusa(int result, const char *file, const char *function, int line);
