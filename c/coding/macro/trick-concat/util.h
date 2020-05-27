#ifndef _UTIL_H
#define _UTIL_H

#define INFO_ADDR_VAL(X) printf("|%14p|%14p|\n", &X, X);
#define INFO_ADDR_VAL_STR(X) printf("|%14p|%14p|%s\n", &X, X, X);
#define INFO_ADDR_VAL_INT(X) printf("|%14p|%14p|%d\n", &X, X, *X);

#define SHOW(a)                                                                \
  printf("%s:%d " #a "\n", __FILE__,                                           \
         __LINE__) // Interessant : les guillements !! et #a

#endif
