#include "person.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  struct s_address add_1; // declaration
  add_1.number = NUMBER;  // member initialization
  add_1.street = STREET;
  add_1.postal_code = CODE;

  print_addr(&add_1);

  Address add_2;
  add_2.number = NUMBER;
  add_2.street = STREET;
  add_2.postal_code = CODE;

  LINE_BREAK
  print_addr(&add_2);

  // declaration + initialization
  struct s_person p_1 = {"Paul", "France", add_1, NULL};

  LINE_BREAK
  p_1.print_s_person = &print_person;

  LINE_BREAK
  p_1.print_s_person(&p_1); // struct in C are different from C++

  Person p_2;
  p_2.name = "Pierre";
  p_2.firstname = "France";
  p_2.address = add_1;

  LINE_BREAK
  p_2.print_s_person = &print_person; // initialization

  LINE_BREAK
  p_2.print_s_person(&p_2);

  // declaration + definition
  void print_geek(const Person *p) { printf("Geek: %s!!\n", p->name); }

  LINE_BREAK
  brianKernighan.person.print_s_person(&brianKernighan.person); // function call

  brianKernighan.person.print_s_person =
      &print_person; // function pointer, let us try this function
  brianKernighan.person.print_s_person =
      &print_geek; // function pointer, why not this another one

  LINE_BREAK
  brianKernighan.person.print_s_person(&brianKernighan.person); // function call

  LINE_BREAK
  print_hobby(&brianKernighan); // function call

  return EXIT_SUCCESS;
}
