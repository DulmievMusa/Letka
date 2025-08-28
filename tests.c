#include <stdio.h>
#include <math.h>
#include <stdbool.h>
// #define NDEBUG // it's better to use this with an option, -DNDEBUG
#include <assert.h>
#include "tests.h"
#include "macros.h"
#include "my_asserts.h"
#include "calculate_functions.h"
#include "string_functions.h"


struct TestData {
    double a, b, c;
    int count_of_roots;
    double x1, x2;
};
 



int RunTests() {
    TestQuadraticEquation(); // TODO: so RunTests and TestQuadraticEquation are essentially the same?
    return 1;
}


void TestQuadraticEquation() {
    int i = 0;
    FILE *tests_file;
    struct TestData one_test;
    tests_file = fopen("QuadrumEquationTestData.txt", "r");
    while (fscanf(tests_file, "%lg %lg %lg %d %lg %lg",
            &(one_test.a), &(one_test.b), &(one_test.c),
            &(one_test.count_of_roots),
            &(one_test.x1), &(one_test.x2)) != EOF) {

            OneTestQuadraticEquation(one_test, ++i);
    }

}

/* void TestQuadraticEquation() {
    const int count_of_tests = ARRAY_SIZE(tests);

    for (int i = 0; i < count_of_tests; i++) {
        OneTestQuadraticEquation(tests[i], i + 1);
    } 
} */


void IncorrectNumberOfRootsPrint(int true_count, int false_count) {
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


void CorrectNumberOfRootsPrint(int supposed_count_of_roots,
                                    double a, double b, double c,
                                    double calculated_by_funcrion_x1, double calculated_by_funcrion_x2,
                                    double true_x1, double true_x2,
                                    int number_of_test) {
    
    SortAscending(&calculated_by_funcrion_x1, &calculated_by_funcrion_x2); 
    SortAscending(&true_x1, &true_x2); // NOTE: this could be an assert?

    if (!CheckTwoNumbersMatch(calculated_by_funcrion_x1, true_x1) || !CheckTwoNumbersMatch(calculated_by_funcrion_x2, true_x2)) {
        printf(TEST_FALED_ANSI "Test number %d faled" RESET_ANSI "\n", number_of_test);
        printf("Coefficients: a=%lg , b=%lg, c=%lg\n", a, b, c);
        printf("Program found %d root(s)\n", supposed_count_of_roots);
    }            
                
    double supposed_roots[] = {calculated_by_funcrion_x1, calculated_by_funcrion_x2};
    double true_roots[] = {true_x1, true_x2};
    for (int i = 0; i < supposed_count_of_roots; i++) {
        if (!CheckTwoNumbersMatch(supposed_roots[i], true_roots[i])) {
            printf("x%d doesn't fit. Expected: %lg, got: %lg\n", i + 1, true_roots[i], supposed_roots[i]);
        }
    };
    printf("\n");
}


void OneTestQuadraticEquation(struct TestData test, int test_number) {
    double supposed_x1 = 0, supposed_x2 = 0;
    int supposed_count_of_roots = GeneralCaseSolve(test.a, test.b, test.c, &supposed_x1, &supposed_x2);

    if (supposed_count_of_roots != test.count_of_roots) { // Если количество корней найдено неверно
        printf(TEST_FALED_ANSI "Test number %d faled" RESET_ANSI "\n" , test_number);
        printf("coefficients: a=%lg , b=%lg, c=%lg\n", test.a, test.b, test.c);
        IncorrectNumberOfRootsPrint(test.count_of_roots, supposed_count_of_roots);
    } else if (!CheckTwoNumbersMatch(test.count_of_roots, 0) && !CheckTwoNumbersMatch(test.count_of_roots, -1)) { // Если количество корней найдено верно
            CorrectNumberOfRootsPrint(supposed_count_of_roots,
                                      test.a, test.b, test.c, supposed_x1, supposed_x2,
                                      test.x1, test.x2, test_number);
        
    }
}