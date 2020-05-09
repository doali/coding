#include "func_f.h"

extern int global;   // Program scope
extern int global_1; // Program scope

// Definition of api_f declared in func_f.h
void api_f(void) { // Block scope
  PRINT_FUNC
  PRINT_NUMBER(global)
  PRINT_NUMBER(global_1)
}
