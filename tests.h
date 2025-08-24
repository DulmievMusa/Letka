#ifndef TEST_H
#define TEST_H

int run_tests(); 
int correct_number_of_roots_print(int supposed_count_of_roots,
                                    double a, double b, double c,
                                    double supposed_x1, double supposed_x2,
                                    double true_x1, double true_x2,
                                    int count);
int incorrect_number_of_roots_print(int true_count, int false_count, int number_of_test);
bool test_general_solve();

#endif