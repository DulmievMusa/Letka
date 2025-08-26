#include <stdio.h>
#include <math.h>
#include <stdbool.h>
// #define NDEBUG // TODO: it's better to use this with an option, -DNDEBUG
#include <assert.h>
#include "funcs.h"
#include "tests.h"

#define FG_BG_ANSI "\033[41;97m"
#define TEST_FALED_ANSI "\033[44;97m"
#define RESET_ANSI "\033[0m"

struct TestData {
    double a,b,c; // TODO: spaces
    int n;
    double x1, x2;
};

const struct TestData tests[] = {{.a=1, .b=-8, .c=-9, .n=2, .x1=-1, .x2=9},
                                 {.a=0, .b=0, .c=0, .n=-1, .x1=0, .x2=0},
                                 {.a=9, .b=1, .c=10, .n=0, .x1=0, .x2=0},
                                 {.a=1, .b=-8, .c=-9, .n=1, .x1=0, .x2=0},
                                 {.a=0, .b=0, .c=0, .n=-1, .x1=0, .x2=0},
                                 {.a=1, .b=-8, .c=-9, .n=2, .x1=-1, .x2=-1}};


int RunTests() {
    TestGeneralSolve(); // TODO: so RunTests and TestGeneralSolve are essentially the same?
    return 1;
}


bool TestGeneralSolve() {

    // TODO: extract this from function, make "static const TestData tests[] = ..." 
    // TODO: also try to align it better so that tests are readable by a human being
    

    // NOTE: You can make a macro ARRAY_SIZE(array)
    const int count_of_tests = sizeof(tests) / sizeof(tests[0]); 

    for (int i=0; i < count_of_tests; i++) { // TODO: too little spacing after "="
        
        OneTestQuadEq(tests[i], i + 1);
        
    }
    

    return true; // TODO: why would you return true if this function never returns false? Make it void
}


int IncorrectNumberOfRootsPrint(int true_count, int false_count, int number_of_test) {
    // TODO: it's better to write it in a more structure way
    // E.g.: "Expected: 2 roots, got 1"
    if (false_count == 2 || false_count == 1) {
        printf("Program thinks that equation have %d roots\n", false_count);
    } else if (false_count == 0) {
        printf("Program thinks that equation doesn't have any roots\n");
    } else if (false_count == -1) {
        printf("Program thinks that equation have infinite roots\n");
    }
    // TODO: never use more than three newlines in a row

    if (true_count == 2 || true_count == 1) {
        printf("But it must have %d roots\n", true_count);
    } else if (true_count == 0) {
        printf("But it must have no roots\n");
    } else if (true_count == -1) {
        printf("But it must have infinite roots\n");
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
    
    SortRootsRising(&supposed_x1, &supposed_x2); // NOTE: Ascending
    SortRootsRising(&true_x1, &true_x2); // NOTE: this could be an assert?
    if (!IsItThisNumber(supposed_x1, true_x1) || !IsItThisNumber(supposed_x2, true_x2)) {
        printf(TEST_FALED_ANSI "Test number %d faled" RESET_ANSI "\n", count); // TODO: fix indentation
        printf("Coefficients: a=%lg , b=%lg, c=%lg\n", a, b, c);
        printf("Program found %d root(s)\n", supposed_count_of_roots);
                }                                    
                
    switch (supposed_count_of_roots)
            {
            case 2: // TODO: this copy-pasting can be solved with an array
                
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


int OneTestQuadEq(struct TestData test, int count) {
    double supposed_x1 = 0, supposed_x2 = 0;
    int supposed_count_of_roots = 0;

    int true_count_of_roots = test.n;
    double true_x1 = test.x1, true_x2 = test.x2;
    supposed_count_of_roots = GeneralCaseSolve(test.a, test.b, test.c, &supposed_x1, &supposed_x2);

    if (supposed_count_of_roots != true_count_of_roots) { // Если количество корней найдено неверно
        printf(TEST_FALED_ANSI "Test number %d faled" RESET_ANSI "\n" , count);
        printf("coefficients: a=%lg , b=%lg, c=%lg\n", test.a, test.b, test.c);
        IncorrectNumberOfRootsPrint(true_count_of_roots, supposed_count_of_roots, count);
    } else { // Если количество корней найдено верно
        if (!IsItThisNumber(true_count_of_roots, 0) && !IsItThisNumber(true_count_of_roots, -1)){
            CorrectNumberOfRootsPrint(supposed_count_of_roots,
                                            test.a, test.b, test.c, supposed_x1, supposed_x2,
                                        true_x1, true_x2, count); // TODO: indentation
        }
        
    }
}