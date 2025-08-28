#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include "macros.h"
#include "my_asserts.h"
#include "consts.h"
#include "string_functions.h"


int ClearBuffer() {
    char ch = getchar();
    while (ch != '\n' && ch != EOF){
        ch = getchar();}
}


bool CompareTwoStrings(char* first_st, const char* second_st) {
    int first_size = FindStringLength(first_st);
    int second_size = FindStringLength(second_st);
    if (first_size != second_size) {
        return false;
    }
    for (int i = 0; i < second_size; i++) {
        if (first_st[i] != second_st[i]) {
            return false;
        }
    }
    return true;
}


int FindStringLength(const char* string) {
    int index = 0;
    while (string[index] != '\0') {
        index++;
    }
    return index;
}