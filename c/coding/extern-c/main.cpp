#include "A.hpp"
#include "B.hpp"

// -----------------------------------------------------------------------------
/*
 * extern "C" {
 * [...]
 * }
 *
 * INDIQUE AU COMPILATEUR g++
 * - de considérer tout le contenu du header ctool.h
 *   comme du code C
 * - permet de réaliser une compilation séparée du code C
 *   $ gcc -c ctool.h => ctool.o
 *   $ ar -q libctool.a ctool.o => libctool.a
 * - la resolution des symboles définis dans libctool.a et
 *   exploités dans main.cpp se fera lors de l'édition des liens
 *   i.e.
 *   $ g++ -o main.exe main.o A.o B.o libctool.a
 */
#ifdef __cplusplus
extern "C" {
#endif
#include "ctool.h"
#ifdef __cplusplus
}
#endif
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <vector>

int main(int argc, char **argv) {
  // --- C++
  A a_0(10);
  A a_1(11);
  B b_0(20);
  B b_1(21);

  std::vector<A *> v = {&a_0, &a_1, &b_0, &b_1};

  std::vector<A *>::iterator it;
  for (it = v.begin(); it != v.end(); ++it) {
    (*it)->do_something();
  }

  // --- C
  struct s s_b = {e_0, "s_b", tell_a};
  struct s s_a = {e_1, "s_a", tell_b};

  struct s t[2] = {s_a, s_b};

  for (int i = 0; i < 2; ++i) {
    printf("%s\n", t[i].m_f());
  }

  return 0;
}
