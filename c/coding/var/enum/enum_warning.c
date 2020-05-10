/*
 * https://en.cppreference.com/w/c/language/enum
 */

#include <stdio.h>
#include <stdlib.h>

// -----------------------------------------------------------------------------
// Here we use typedef !!
// - we define aliases !! <= IMPORTANT
// -----------------------------------------------------------------------------
typedef enum Direction {
  UP,
  DOWN,
  LEFT,
  RIGHT
} alias_direction,    /* alias_direction is an ALIAS */
    *pAliasDirection; /* alias_direction is an ALIAS */

enum Label {
  LABEL_10 = 10,
  LABEL_11,
} e_label,   /* e_label is a VARIABLE !! */
    *pLabel; /* here, no doubt that pLabel is a VARIABLE */

int main(void) {
  // ---------------------------------------------------------------------------
  // e_label lab_10 = LABEL_10; // expression can not be assigned !! e_label is
  // a variable
  e_label = LABEL_10; // assignement of variable : OK
  pLabel = &e_label;  // OK

  printf("%d\n", e_label);
  printf("%d\n", *pLabel);

  // ---------------------------------------------------------------------------
  alias_direction dir_down = DOWN; // declaration : OK
  pAliasDirection pDirUp =
      &dir_down; // declaration : OK (pDirUp is type : enum Direction*)

  printf("%d\n", dir_down);
  printf("%d\n", *pDirUp);
}
