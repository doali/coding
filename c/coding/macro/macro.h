#ifndef _MACRO_H // include guards : permet de n'inclure
#define _MACRO_H // qu'une seule fois ce fichier

#define MAX_BUFF 1024 // définition d'une constante

#define FREE(P)                                                                \
  do {                                                                         \
    free(P);                                                                   \
    P = NULL;                                                                  \
  } while (0)

#endif
