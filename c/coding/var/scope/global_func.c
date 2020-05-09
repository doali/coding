#include "macro.h"

// Program scope
void global_func_f(void) { // Block scope
  PRINT_FUNC
}

// extern void useless_extern_f(); // NO !! do not use extern HERE
// since defintion below
// declaration and definition in the same file...
void useless_extern_f() {
  // definition
  PRINT_FUNC
}
