#include "func_f.h"
#include "global_h.h"
#include "macro.h"
#include <stdio.h>

extern int global;   // extern : necessary even if global
extern int global_1; // extern : necessary even if global

// extern void global_func_f(void);
void global_func_f(void);
// extern void use_static_global(void);
void use_static_global(void);
void useless_extern_f();

// extern int static_global;
/* forbidden !! since static is FILE scope
 * only works in file where static_global were declared
 * static_global is a global variable but only in ITS file
 */
// extern int static_global_1; // Same explanation as above

int main(void) { // Block scope
  PRINT_FUNC

  { // Block scope
    printf("inside block scope\n");
  }

  // Global variables (and static global variables)
  PRINT_NUMBER(global)
  PRINT_NUMBER(global_1)
  PRINT_NUMBER(global_h)
  PRINT_NUMBER(global_h_1)
  // PRINT_NUMBER(static_global) // Forbidden (static_global : file scope)
  // PRINT_NUMBER(static_global_1) // Same as above

  // extern functions
  global_func_f();
  use_static_global();
  useless_extern_f();

  // Functons using headers
  api_f();
}
