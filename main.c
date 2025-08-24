#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include "tests.h"
#include "funcs.h"

const double ACCURACY = 1e-4;
const int INFINITE_ROOTS = -1;

int correct_input_a_number(double* a, char symbol);
int input_coefficients(double* a, double* b, double* c);
int print_roots(int n, double x1, double x2);




int main() {
    run_tests();
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    int n = 0, flag = 0;
    printf("This program solve quad. equation ax^2+bx+c=0\n");
    printf("Input coefficient a, coefficient b, coefficient c in different lines:\n");
    
    input_coefficients(&a, &b, &c);

    printf("You have entered: a: %lg, b: %lg c: %lg\n", a, b, c);

    n = general_case_solve(a, b, c, &x1, &x2); // Решение уравнения
    
    print_roots(n, x1, x2);

    return 0;
}

// Ввод коэффициентов
int input_coefficients(double* a, double* b, double* c) {
    
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);

    assert(a != b && b != c && a != c);

    printf("a: ");
    correct_input_a_number(a, 'a');
    printf("b: ");
    correct_input_a_number(b, 'b');
    printf("c: ");
    correct_input_a_number(c, 'c');
    return 0;
}

//Проверка правильного ввода
int correct_input_a_number(double* a, char symbol) {

    assert(a != NULL);

    int ch;
    while (scanf("%lg", a) == 0) { // NOTE: scanf("%lg%c", a, symbol)... symbol == '\n'?
        printf("You entered not a number. Try again\n");
        printf("%c: ", symbol);
        ch = getchar();
        while (ch != '\n' && ch != EOF)
            ch = getchar();
    }
    ch = getchar();
    if (ch != '\n' &&  ch != EOF) { // TODO: why do you require two newlines in a row?
        correct_input_a_number(a, symbol);
    }
    return 0;
}

// Вывод результата
int print_roots(int n, double x1, double x2) {
    
    assert(isfinite(x1));
    assert(isfinite(x2));

    switch (n) {
        case 2: 
            printf("Equation have two roots:\nx1=%g\nx2=%g", x1, x2);
            break;
        case 1:
            printf("Equation have one root:\nx=%g", x1);
            break;
        case 0:
            printf("Equation have no roots");
            break;
        case -1:
            printf("Equation have infinite roots");
            break;
    }
}