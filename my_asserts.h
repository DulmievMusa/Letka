#define MyAssert(result) AssertOfMusa(result, __FILE__, __PRETTY_FUNCTION__, __LINE__)
int AssertOfMusa(int result, const char *file, const char *function, int line);
