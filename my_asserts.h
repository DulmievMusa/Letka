#ifndef MY_ASSERTS_H
#define MY_ASSERTS_H

#define MyAssert(need_to_call_assert) AssertOfMusa(need_to_call_assert, __FILE__, __PRETTY_FUNCTION__, __LINE__)


//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Stops the program if the need_to_call_assert argument != 0
//!
//!
//! @param [in]  need_to_call_assert should the program be stopped
//! @param [in]  file   name of file where Assert was called
//! @param [in]  function   name of founction where Assert was called
//! @param [in]  line  number of file where Assert was called
//!
//!
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
void AssertOfMusa(int need_to_call_assert, const char *file, const char *function, int line);

#endif