#include <stdio.h>
#include <stdlib.h>
#include "macros.h"
#include "my_asserts.h"

void AssertOfMusa(int need_to_call_assert, const char *file, const char *function, int line) {
    if (!need_to_call_assert) {
        printf(FG_BG_ANSI "Assertion failed: " RESET_ANSI "\n");
        printf(FG_BG_ANSI "File: %s " RESET_ANSI "\n", file);
        printf(FG_BG_ANSI "Function: %s " RESET_ANSI "\n", function);
        printf(FG_BG_ANSI "Line: %d " RESET_ANSI "\n", line);
        printf("\n");
        abort();
    }
}