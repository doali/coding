#include "macro.h"

static int static_global; // Global variable only in THIS file (due to static
                          // key word)
                          // File scope
static int static_global_1 = 1; // Global variable only in THIS file (due to
                                // static key word)
                                // File scope

void use_static_global(void) {
  PRINT_FUNC
  PRINT_NUMBER(static_global)
  PRINT_NUMBER(static_global_1)
}
