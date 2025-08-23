#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

const double ACCURACY = 1e-4;
const int INFINITE_ROOTS = -1;

// int a[] = {7, 8, 9};
// a[][3] = {{1, 2, 3}, {3,4,5}}

// a[1][2]
bool sort_roots_rising(double* x1, double* x2);
bool test_general_solve();
double calculate_discriminant(double a, double b, double c);
bool is_it_this_number(double first, double second);
double abs(double n);
int general_case_solve(double a, double b, double c, double* x1, double* x2);
int linear_equation_solve(double b, double c, double* x1, double* x2);
int quadratic_equation_solve(double a, double b, double c, double* x1, double* x2);
int correct_input_a_number(double* a, char symbol);
int input_coefficients(double* a, double* b, double* c);
int print_roots(int n, double x1, double x2);
int incorrect_number_of_roots_print(int true_count, int false_count, int number_of_test);

int main() {
    test_general_solve();
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


// Считает дискриминант
double calculate_discriminant(double a, double b, double c) {
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    return b*b - 4*a*c;
}

// Проверяет совпадает ли первое число со вторым
bool is_it_this_number(double first, double second) {

    assert(isfinite(first));
    assert(isfinite(second));

    if (first * second < 0) {
        return false;
    }
    double diff = abs(first - second);
    if (diff >= ACCURACY) {
        return false;
    } else {
        return true;
    }
}

// Модуль числа
double abs(double n) {

    assert(isfinite(n));

    if (n < 0) {
        n = -n;
    }
    return n;
}

// Решает квадратное уравнение в общем случае
int general_case_solve(double a, double b, double c, double* x1, double* x2) {
    
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2); 

    if (is_it_this_number(a, 0)) { //Если a == 0
        return linear_equation_solve(b, c, x1, x2);
    } else { // Если a != 0
        return quadratic_equation_solve(a, b, c, x1, x2);
    } 

}

// Решает линейное уравнение вида bx + c = 0
int linear_equation_solve(double b, double c, double* x1, double* x2) {

    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2); 

    if (!is_it_this_number(b, 0)) { // Если b != 0
            *x1 = -c / b;
            *x2 = NAN;
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

    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2); 

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

bool test_general_solve() {
    double x1 = 0, x2 = 0, a = 0, b = 0, c = 0, check_result = 0;
    int supposed_count_of_roots = 0, count = 1;
    bool flag = false;
    double tests[][4] = {{1, -8, -9, 2}, {0, 0, 0, -1}, {9, 1, 10, 0},
                         {1, -8, -9, 1}, {0, 0, 0, 0}, {9, 1, 10, 1}};
    const int count_of_tests = sizeof(tests) / sizeof(tests[0]); 

    for (int i=0; i < count_of_tests; i++) {
        flag = false;
        a = tests[i][0]; b = tests[i][1]; c = tests[i][2];
        int true_count_of_roots = tests[i][3];
        supposed_count_of_roots = general_case_solve(a, b, c, &x1, &x2);
        if (supposed_count_of_roots != true_count_of_roots) { // Если количество корней найдено неверно
            incorrect_number_of_roots_print(true_count_of_roots, supposed_count_of_roots, count);
        } else { // Если количество корней найдено верно
            switch (supposed_count_of_roots)
            {
            case 2:
                check_result = a*(x1*x1) + b*x1 + c;
                if (!is_it_this_number(check_result, 0)) {
                    printf("Test number %d faled\n", count);
                    printf("First root doesn't fit\n");
                    flag = true;
                }
                check_result = a*(x2*x2) + b*x2 + c;
                if (!is_it_this_number(check_result, 0)) {
                    if (!flag){
                        printf("Test number %d faled\n", count);
                    }
                    printf("%s Second root doesn't fit\n", "aaa");
                }
                break;
            case 1:
                check_result = a*(x1*x1) + b*x1 + c;
                if (!is_it_this_number(check_result, 0)) {
                    printf("Test number %d faled\n", count);
                    printf("Root doesn't fit\n");
                }
                break;
            }
        }
        count++;
        
    }
    

    return true;
}

int incorrect_number_of_roots_print(int true_count, int false_count, int number_of_test) {
    printf("Test number %d faled\n", number_of_test);
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

