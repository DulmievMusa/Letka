#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include "macros.h"
#include "my_asserts.h"
#include "consts.h"
#include "string_functions.h"


void ClearBuffer() {
    int symbol = getchar();
    while (symbol != '\n' && symbol != EOF){
        symbol = getchar();
    }
}


bool CompareTwoStrings(char* first_string, const char* second_string) {

    MyAssert(first_string != NULL);
    MyAssert(second_string != NULL);
    MyAssert(first_string != second_string);

    int first_size = FindStringLength(first_string);
    int second_size = FindStringLength(second_string);
    if (first_size != second_size) {
        return false;
    }
    for (int i = 0; i < second_size; i++) {
        if (first_string[i] != second_string[i]) {
            return false;
        }
    }
    return true;
}


int FindStringLength(const char* string) {
    
    MyAssert(string != NULL);

    int index = 0;
    while (string[index] != '\0') {
        index++;
    }
    return index;
}