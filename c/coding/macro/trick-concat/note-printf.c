#include <stdio.h>

#define LINE_BREAK printf("\n")

#define WRAPP(W) #W
// permet d'envelopper W de guillemets
// fonctionne
// - uniquement dans la définition de la macro
// - sur un PARAMETRE (pas de #MON_AUTRE_MACRO(A, B) <= marchera pas !!)

void notes(void) {
  printf(__func__);

  // LINE_BREAK;
  // printf(""); // OK mais warnings
  /*
   * gcc -c notes
   *
   * renvoie en sortie
   * ==================================
   * note-printf.c: In function ‘notes’:
   * note-printf.c:14:10: warning: zero-length gnu_printf format string
   * [-Wformat-zero-length] printf("");
   * ==================================
   * Cette instruction ne sert évidemment à rien et le compilateur nous
   * l'indique !
   */

  /*
  LINE_BREAK;
  printf(""
         ""
         ""); // OK mais warnings (compilateur indique que la chaine est
  vide)
         */

  LINE_BREAK;
  printf(""
         "\n"); // On peut ajouter des guillements les uns à la suite

  LINE_BREAK;
  printf(""
         "a"
         ""); // OK

  LINE_BREAK;
  printf(WRAPP(mot));

  LINE_BREAK;
  printf("WORD>" WRAPP(mot)); // Du coup, on peut utiliser
                              // l'opérateur # dans la définition des macros
                              // et le placer dans un printf :-)

  LINE_BREAK;
  printf("START>" WRAPP(mot) "<END\n");

  LINE_BREAK;
  printf("Look at the code\n");
}
