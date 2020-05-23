#include <stdio.h>

#define LINE_BREAK printf("\n");
#define LINE_BREAK_INNER printf("\n\t");

typedef void (*p_f)(void);

void do_1(void);                                     // declaration
void do_2(void) { printf("call to:%s|", __func__); } // declaration + definition

void (*f_1(void))(void) {
  printf("call to:%s|", __func__);
  printf("return :%p|", do_1);
  return do_1;
} // function named f_1 returning a function pointer
  // void(*)(void)

void (*f_2(void (*g)(void)))(void) {
  printf("call to:%s|", __func__);
  printf("return :%p|", g);
  return g;
} // function named f_2 returning a function pointer
  // void(*)(void)
  // which parameter is a function pointer

p_f f_3(void) {
  printf("call to:%s|", __func__);
  printf("return :%p|", do_1);
  return do_1;
} // returns a function pointer

p_f f_4(p_f g) {
  printf("call to:%s|", __func__);
  printf("return :%p|", g);
  return g;
} // function returning a function pointer
  // what's more, its argument is a function pointer

int main(int argc, char **argv) {

  f_1()(); /*
            * f_1() <= returns a <function pointer>
            * f_1()() <= <function pointer>() i.e call the function pointer
            */

  LINE_BREAK
  f_2(do_2)();

  p_f pf = NULL;

  LINE_BREAK
  pf = f_3();
  pf();

  LINE_BREAK
  pf = f_4(do_2);
  pf();

  LINE_BREAK
  return 0;
}

void do_1(void) {
  printf("call to:%s|", __func__);
  return;
}
