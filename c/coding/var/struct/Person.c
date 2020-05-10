#include "Person.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  struct s_address add_1;
  add_1.number = NUMBER;
  add_1.street = STREET;
  add_1.postal_code = CODE;
  print_addr(&add_1);

  Address add_2;
  add_2.number = NUMBER;
  add_2.street = STREET;
  add_2.postal_code = CODE;
  print_addr(&add_2);

  struct s_person p_1 = {"Paul", "France", add_1, NULL};
  p_1.print_s_person = &print_person;
  p_1.print_s_person(&p_1); // struct in C are different from C++

  Person p_2;
  p_2.name = "Pierre";
  p_2.firstname = "France";
  p_2.address = add_1;
  p_2.print_s_person = &print_person;
  p_2.print_s_person(&p_2);

  brianKernighan.person.print_s_person = &print_person;
  brianKernighan.person.print_s_person(&brianKernighan.person);

  print_hobby(&brianKernighan);

  return EXIT_SUCCESS;
}
