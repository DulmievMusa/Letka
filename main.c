#include <stdio.h>
#include <math.h>
#include <stdbool.h>

const double ACCURACY = 1e-4;
const int INFINITE_ROOTS = -1;

double calculate_discriminant(double a, double b, double c);
int is_it_this_number(double first, double second);
double abs(double n);
int general_case_solve(double a, double b, double c, double* x1, double* x2);
int linear_equation_solve(double b, double c, double* x1, double* x2);
int quadratic_equation_solve(double a, double b, double c, double* x1, double* x2);
int correct_input(double* a, char symbol); // TODO: better name?
int input_coefficients(double* a, double* b, double* c); // TODO: better name?
int print_result(int n, double x1, double x2); // TODO: better name?

int main() {
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    int n = 0, flag = 0;
    printf("test2\n"); // TODO: don't forget to remove test logs, also you could make a macro that removes them automatically when you build in release
    printf("This program solve quad. equation ax^2+bx+c=0\n");
    printf("Input coefficient a, coefficient b, coefficient c in different lines:\n");
    
    input_coefficients(&a, &b, &c);

    printf("You have entered: a: %lg, b: %lg c: %lg\n", a, b, c);

    n = general_case_solve(a, b, c, &x1, &x2); // Решение уравнения
    
    print_result(n, x1, x2);

    return 0;
}

// Ввод коэффициентов
int input_coefficients(double* a, double* b, double* c) {
    printf("a: ");
    correct_input(a, 'a');
    printf("b: ");
    correct_input(b, 'b');
    printf("c: ");
    correct_input(c, 'c');
    return 0;
}

//Проверка правильного ввода
int correct_input(double* a, char symbol) {
    while (scanf("%lg", a) == 0) { // NOTE: scanf("%lg%c", a, symbol)... symbol == '\n'?
        printf("You entered not a number. Try again\n");
        printf("%c: ", symbol);
        while (getchar() != '\n'); // TODO: extract, what about EOF?
    }
    if (getchar() != '\n') { // TODO: why do you require two newlines in a row?
        correct_input(a, symbol);
    }
    return 0;}

// Вывод результата
int print_result(int n, double x1, double x2) {
    if (n == 2) { // TODO: switch..case?
        printf("Equation have two roots:\nx1=%g\nx2=%g", x1, x2);
    } else if (n == 1) {
        printf("Equation have one root:\nx=%g", x1);
    } else if (n == 0) {
        printf("Equation have not roots");
    } else if (n == -1) {
        printf("Equation have infinite roots");
    }
}


// Считает дискриминант
double calculate_discriminant(double a, double b, double c) {
    return b*b - 4*a*c;
}

// Проверяет совпадает ли первое число со вторым
int is_it_this_number(double first, double second) { // TODO: bool? 
    if (first * second < 0) {
        return false;
    }
    double diff = abs(first - second); // TODO: you already ensured that numbers are the same sign, no need for extra abs
    if (diff >= ACCURACY) {
        return false;
    } else {
        return true;
    }
}

// Модуль числа
double abs(double n) {
    if (n < 0) {
        n = -n;
    }
    return n;
}

// Решает квадратное уравнение в общем случае
int general_case_solve(double a, double b, double c, double* x1, double* x2) {

    /* TODO: finish this
    
    assert (std::isfinite(a));
    assert (std::isfinite(b));
    assert (std::isfinite(c));

    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);*/

    if (is_it_this_number(a, 0)) { //Если a == 0
        return linear_equation_solve(b, c, x1, x2);
    } else { // Если a != 0
        return quadratic_equation_solve(a, b, c, x1, x2);
    } 

}

// Решает линейное уравнение вида bx + c = 0
int linear_equation_solve(double b, double c, double* x1, double* x2) {
    if (!is_it_this_number(b, 0)) { // Если b != 0
            *x1 = *x2 = -c / b; // TODO: why do you set both? // TODO: read about how floating point number work (see IEEE754), then set your second root to NAN
            return 1;
        } else { // Если b == 0
            if (!is_it_this_number(c, 0)) { // Если с != 0
                return 0;
            } else { // Если c == 0
                return INFINITE_ROOTS; // Бесконечное количество корней
            }
        }
}

// Решает квадратное уравнение вида ax^2 + bx + c = 0
int quadratic_equation_solve(double a, double b, double c, double* x1, double* x2) {
    double dis = 0;
    dis = calculate_discriminant(a, b, c);
    if (dis > 0) {
        double sqrt_dis = sqrt(dis);
        *x1 = (-b + sqrt_dis) / (2*a);
        *x2 = (-b - sqrt_dis) / (2*a);
        return 2;
    } else if (is_it_this_number(dis, 0)) {
        *x1 = *x2 = -b / (2*a);
        return 1;
    } else {
        return 0;
    }
}

