#ifndef TEST_H
#define TEST_H

int RunTests(); 
int CorrectNumberOfRootsPrint(int supposed_count_of_roots,
                                    double a, double b, double c,
                                    double supposed_x1, double supposed_x2,
                                    double true_x1, double true_x2,
                                    int count);
int IncorrectNumberOfRootsPrint(int true_count, int false_count, int number_of_test);
bool TestGeneralSolve();
int OneTestQuadEq(struct TestData test, int count);

#endif