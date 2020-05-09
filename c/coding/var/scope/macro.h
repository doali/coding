#ifndef _MACRO_H
#define _MACRO_H

#include <stdio.h>

#define PRINT_FUNC                                                             \
  printf("file:%s func:%s line:%d\n", __FILE__, __func__, __LINE__);

#define PRINT_NUMBER(X) printf("%d\n", X);

#endif // _MACRO_H
