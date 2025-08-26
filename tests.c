#include <stdio.h>
#include <math.h>
#include <stdbool.h>
// #define NDEBUG // it's better to use this with an option, -DNDEBUG
#include <assert.h>
#include "funcs.h"
#include "tests.h"
#include "macros.h"
#include "my_asserts.h"


struct TestData {
    double a, b, c;
    int count_of_roots;
    double x1, x2;
};
 

//TODO: align
const struct TestData tests[] = {{.a=1, .b=-8, .c=-9, .count_of_roots=2, .x1=-1, .x2=9},
                                 {.a=0, .b=0, .c=0, .count_of_roots=-1, .x1=0, .x2=0},
                                 {.a=9, .b=1, .c=10, .count_of_roots=0, .x1=0, .x2=0},
                                 {.a=1, .b=-8, .c=-9, .count_of_roots=1, .x1=0, .x2=0},
                                 {.a=1, .b=-8, .c=-9, .count_of_roots=2, .x1=34, .x2=3555},
                                 {.a=1, .b=-8, .c=-9, .count_of_roots=-1, .x1=9, .x2=-1}};


int RunTests() {
    TestGeneralSolve(); // TODO: so RunTests and TestGeneralSolve are essentially the same?
    return 1;
}


void TestGeneralSolve() {
    const int count_of_tests = ARRAY_SIZE(tests);

    for (int i = 0; i < count_of_tests; i++) {
        OneTestQuadEq(tests[i], i + 1);
    } 
}


int IncorrectNumberOfRootsPrint(int true_count, int false_count, int number_of_test,
                                    struct TestData test) {
    if (true_count != -1) {
        printf("Expected: %d roots, ", true_count);
    } else if (true_count == -1) {
        printf("Expected: root - every number, ");
    } 
    if (false_count != -1) {
        printf("got: %d roots\n", false_count);
    }
    else if (false_count == -1) {
        printf("got: root - every number\n");
    }

    printf("\n");
}


// NOTE: answering your question about returning strings

// strncpy is a function to make STRing CoPY from string.h

// it's easy to implement such function yourself:
// void my_strncpy(char *destination, int n, const char *source) {
//     int i = 0;
//     for (; i < (n - 1); ++ i)
//         destination[i] = source[i]; // *(source + i) == source[i]
//
//     destination[i] = '\0';
// }

// void return_my_string(char *buffer, int n) {
//     strncpy(buffer, n, "hello!\n");
// }

// const int BUFFER_SIZE = 1024;
// char buffer[1024] = {};
// return_my_string(&buffer, BUFFER_SIZE);
// printf("%s", buffer); // prints hello!\n


int CorrectNumberOfRootsPrint(int supposed_count_of_roots,
                                    double a, double b, double c,
                                    double supposed_x1, double supposed_x2,
                                    double true_x1, double true_x2,
                                    int count) {
    
    SortRootsAscending(&supposed_x1, &supposed_x2); 
    SortRootsAscending(&true_x1, &true_x2); // NOTE: this could be an assert?

    if (!IsItThisNumber(supposed_x1, true_x1) || !IsItThisNumber(supposed_x2, true_x2)) {
        printf(TEST_FALED_ANSI "Test number %d faled" RESET_ANSI "\n", count);
        printf("Coefficients: a=%lg , b=%lg, c=%lg\n", a, b, c);
        printf("Program found %d root(s)\n", supposed_count_of_roots);
    }            
                
    double supposed_roots[] = {supposed_x1, supposed_x2};
    double true_roots[] = {true_x1, true_x2};
    for (int i = 0; i < supposed_count_of_roots; i++) {
        if (!IsItThisNumber(supposed_roots[i], true_roots[i])) {
            printf("x%d doesn't fit. Expected: %lg, got: %lg\n", i + 1, true_roots[i], supposed_roots[i]);
        }
    };
    printf("\n");
}


int OneTestQuadEq(struct TestData test, int test_number) {
    double supposed_x1 = 0, supposed_x2 = 0;
    int supposed_count_of_roots = GeneralCaseSolve(test.a, test.b, test.c, &supposed_x1, &supposed_x2);

    if (supposed_count_of_roots != test.count_of_roots) { // Если количество корней найдено неверно
        printf(TEST_FALED_ANSI "Test number %d faled" RESET_ANSI "\n" , test_number);
        printf("coefficients: a=%lg , b=%lg, c=%lg\n", test.a, test.b, test.c);
        IncorrectNumberOfRootsPrint(test.count_of_roots, supposed_count_of_roots, test_number, test);
    } else if (!IsItThisNumber(test.count_of_roots, 0) && !IsItThisNumber(test.count_of_roots, -1)) { // Если количество корней найдено верно
            CorrectNumberOfRootsPrint(supposed_count_of_roots,
                                      test.a, test.b, test.c, supposed_x1, supposed_x2,
                                      test.x1, test.x2, test_number);
        
    }
}