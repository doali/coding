#include "Form.cpp"
#include "Square.cpp"
#include "Triangle.cpp"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#define FREE_POINTER(X)                                                        \
  if (X) {                                                                     \
    delete X;                                                                  \
    X = NULL;                                                                  \
  }

#define SENTENCE_DESTRUCTOR                                                    \
  "Calling destructors (reverse order compared to constructors)"

void print_form(const Form &);
void info(const std::string &);

int main(int argc, char **) {
  Square square(1, "square", 4);
  print_form(square);

  Triangle triangle(2, "triangle", 2, 4);
  print_form(triangle);

  Form *p_f = new Triangle(3, "triangle", 2, 6);
  print_form(*p_f);

  FREE_POINTER(p_f);

  // const std::string &msg = SENTENCE_DESTRUCTOR;
  info(SENTENCE_DESTRUCTOR);

  return EXIT_SUCCESS;
}

void print_form(const Form &form) {
  std::cout << "Form:" << form;
  std::cout << "Surface:" << form.surface() << std::endl;
  std::cout << std::endl;
}

void info(const std::string &info) {
  std::cout << "----" << std::endl;
  std::cout << "Info:" << std::endl;
  std::cout << "\t-" << info << std::endl;
  std::cout << "---" << std::endl;
}
