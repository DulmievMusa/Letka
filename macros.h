#define MyAssert(result) AssertOfMusa(result, __FILE__, __PRETTY_FUNCTION__, __LINE__)
#define FG_BG_ANSI "\033[41;97m"
#define RESET_ANSI "\033[0m"
#define TEST_FALED_ANSI "\033[44;97m"
#define ARRAY_SIZE(array) sizeof(tests) / sizeof(tests[0])