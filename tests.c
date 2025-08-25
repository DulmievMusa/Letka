#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define NDEBUG
#include <assert.h>
#include "funcs.h"
#include "tests.h"

struct test {
    double a,b,c;
    int n;
    double x1, x2;
};


int RunTests() {
    TestGeneralSolve();
    return 1;
}


bool TestGeneralSolve() {

    double supposed_x1 = 0, supposed_x2 = 0, a = 0, b = 0, c = 0, check_result = 0;
    int supposed_count_of_roots = 0, count = 1;
    struct test tests[] = {{1, -8, -9, 2, -1, 9}, {0, 0, 0, -1, 0, 0}, {9, 1, 10, 0, 0, 0},
                         {1, -8, -9, 1, 0, 0}, {0, 0, 0, 0, 0, 0}, {9, 1, 10, 1, 0, 0}};
    const int count_of_tests = sizeof(tests) / sizeof(tests[0]); 

    for (int i=0; i < count_of_tests; i++) {
        
        a = tests[i].a; b = tests[i].b; c = tests[i].c;
        int true_count_of_roots = tests[i].n;
        double true_x1 = tests[i].x1, true_x2 = tests[i].x2;
        supposed_count_of_roots = GeneralCaseSolve(a, b, c, &supposed_x1, &supposed_x2);

        if (supposed_count_of_roots != true_count_of_roots) { // Если количество корней найдено неверно
            printf("Test number %d faled\n", count);
            printf("coefficients: a=%lg , b=%lg, c=%lg\n", a, b, c);
            IncorrectNumberOfRootsPrint(true_count_of_roots, supposed_count_of_roots, count);
        } else { // Если количество корней найдено верно
            if (!IsItThisNumber(true_count_of_roots, 0) && !IsItThisNumber(true_count_of_roots, -1)){
                CorrectNumberOfRootsPrint(supposed_count_of_roots,
                                             a, b, c, supposed_x1, supposed_x2,
                                            true_x1, true_x2, count);
            }
            
        }
        count++;
        
    }
    

    return true;
}


int IncorrectNumberOfRootsPrint(int true_count, int false_count, int number_of_test) {
    if (false_count == 2 || false_count == 1) {
        printf("Program thinks that equation have %d roots\n", false_count);
    } else if (false_count == 0) {
        printf("Program thinks that equation doesn't have any roots\n");
    } else if (false_count == -1) {
        printf("Program thinks that equation have infinite roots\n");
    }
    
    

    if (true_count == 2 || true_count == 1) {
        printf("But it must have %d roots\n", true_count);
    } else if (true_count == 0) {
        printf("But it must have no roots\n");
    } else if (true_count == -1) {
        printf("But it must have infinite roots\n");
    }


    printf("\n");
}

int CorrectNumberOfRootsPrint(int supposed_count_of_roots,
                                    double a, double b, double c,
                                    double supposed_x1, double supposed_x2,
                                    double true_x1, double true_x2,
                                    int count) {
    
    SortRootsRising(&supposed_x1, &supposed_x2);
    SortRootsRising(&true_x1, &true_x2);
    if (!IsItThisNumber(supposed_x1, true_x1) || !IsItThisNumber(supposed_x2, true_x2)) {
                    printf("Test number %d faled\n", count);
                    printf("Coefficients: a=%lg , b=%lg, c=%lg\n", a, b, c);
                    printf("Program found %d root(s)\n", supposed_count_of_roots);
                }                                    
                
    switch (supposed_count_of_roots)
            {
            case 2:
                
                if (!IsItThisNumber(supposed_x1, true_x1)) {
                    printf("First root doesn't fit. True value: %lg. Received value: %lg\n", true_x1, supposed_x1);
                }
                if (!IsItThisNumber(supposed_x2, true_x2)) {
                    printf("Second root doesn't fit. True value: %lg. Received value: %lg\n", true_x2, supposed_x2);
                }
                break;
            case 1:

                if (!IsItThisNumber(supposed_x1, true_x1)) {
                    printf("Root doesn't fit. True value: %lg. Received value: %lg\n", true_x1, supposed_x1);
                }
                break;
            }
        printf("\n");
}
