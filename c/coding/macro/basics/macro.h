#ifndef _MACRO_H // include guards : permet de n'inclure
#define _MACRO_H // qu'une seule fois ce fichier

// https://stackoverflow.com/questions/1067226/c-multi-line-macro-do-while0-vs-scope-block

/**
 * \file macro.h
 * \brief MACRO
 */
#include <stdio.h>

#define LINE_BREAK(NB_C)                                                       \
  do {                                                                         \
    for (int i = 0; i < NB_C; ++i) {                                           \
      printf("%c", '-');                                                       \
    }                                                                          \
    printf("\n");                                                              \
  } while (0)

#define LINE_BREAK_80 LINE_BREAK(80)

#ifdef INFO
#define PRINT_INFO                                                             \
  do {                                                                         \
    LINE_BREAK_80;                                                             \
    printf("%s:", __FILE__);                                                   \
    printf("%d, ", __LINE__);                                                  \
    printf("%s, ", __TIME__);                                                  \
    printf("%s\n", __DATE__);                                                  \
    LINE_BREAK_80;                                                             \
  } while (0)
#endif

#define MAX_BUFF 1024 // définition d'une constante

#define FREE(P)                                                                \
  do {                                                                         \
    free(P);                                                                   \
    P = NULL;                                                                  \
  } while (0)

#endif
