#define MyAssert(result) AssertOfMusa(result, __FILE__, __PRETTY_FUNCTION__, __LINE__)


//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Stops the program if the result argument != 0
//!
//!
//! @param [in]  result   
//! @param [in]  file   c‐coefficient
//! @param [out] x1  Pointer to the 1st root
//! @param [out] x2  Pointer to the 2nd root
//!
//! @return Number of roots
//!
//! @note   In case of infinite number of roots,
//!         returns INFINITE_ROOTS (-1).
//!         If one of the arguments is NAN or INF, then MyAssert is called and the program terminates.
int AssertOfMusa(int need_to_call_assert, const char *file, const char *function, int line);
