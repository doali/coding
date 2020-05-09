/*
 * https://en.cppreference.com/w/c/language/enum
 */

#include <stdio.h>
#include <stdlib.h>

enum color {
  BLACK = 0,
  BROWN,
  RED,
  ORANGE,
  YELLOW,
  GREEN,
  BLUE,
  VIOLET,
  GREY,
  WHITE
} r_color,
    var_enum_color;
// ATTENTION : r_color_var, var_enum_color sont des variables du type
// enum color et non des alias vers le type enum color !!

const char *color_to_str(enum color);

void r_color_var() {
  // r_color c = BLACK; // lvalue est une VARIABLE et non un alias vers enum
  // color !!
  r_color = VIOLET;
  var_enum_color = GREEN;
  printf("%s => %d\n", color_to_str(r_color), r_color);
  printf("%s => %d\n", color_to_str(var_enum_color), var_enum_color);
}

const char *color_to_str(enum color e_color) {
  static const char *conv[] = {"BLACK", "BROWN", "RED",    "ORANGE", "YELLOW",
                               "GREEN", "BLUE",  "VIOLET", "GREY",   "WHITE"};
  return conv[e_color];
}

int color_to_int(enum color first, enum color second) {
  char code[2] = {'\0'};

  sprintf(&code[0], "%d",
          first); // itoa ne fonctionne pas... :-( => spintf(...)
  sprintf(&code[1], "%d", second);

  return atoi(code);
}

int compute_r(enum color first, enum color second, enum color third) {
  printf("%d|%s\n", first, color_to_str(first));
  printf("%d|%s\n", second, color_to_str(second));
  printf("%d|%s\n", third, color_to_str(third));

  int res = color_to_int(first, second);
  printf("R|%d * 10^%d Ohm\n", res, third);

  return res;
}

int main(void) {
  compute_r(BLUE, GREEN, YELLOW);
  r_color_var();
  enum color e_color = YELLOW;
  printf("%s => %d\n", color_to_str(e_color), e_color);
}
