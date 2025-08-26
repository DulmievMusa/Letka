#ifndef TEST_H
#define TEST_H

// NOTE: Documentation is written in header files

int RunTests(); 
int CorrectNumberOfRootsPrint(int supposed_count_of_roots, // TODO: verb usually goes first in names, try to come up with a better name
                                    double a, double b, double c, // TODO: indentation?
                                    double supposed_x1, double supposed_x2,
                                    double true_x1, double true_x2,
                                    int count);
int IncorrectNumberOfRootsPrint(int true_count, int false_count, int number_of_test, struct TestData test); // TODO: better name
void TestGeneralSolve(); // TODO: better name
int OneTestQuadEq(struct TestData test, int test_number);

#endif