#include <stdio.h>
#include <stdlib.h>

#define BREAK_LINE printf("\n");

struct Base;
struct BaseAnonymousInner;

void printBase(const struct Base *base);
void printBaseAnonymousInner(const struct BaseAnonymousInner *base_inner);

// ---------------------------------------------------------------------------
struct Base {
  int fieldBase;
  struct Inner {
    int fieldInner;
  } varInner; // varInner is a VARIABLE (or MEMBER) of type struct Inner

  struct AnotherInner {
    int fieldInner;
  } varAnotherInner; // varAnotherInner is a VARIABLE (or MEMBER) of type
                     // struct AnotherInner
};

// ---------------------------------------------------------------------------
struct BaseAnonymousInner {
  int fieldBase;
  struct { // ANONYMOUS structure
    int fieldInner;
  } /* varAccessInner */;
  /*
   * WARNING !!
   * if varAccessInner is written
   * then to access fieldInner member
   * we have to add varAccessInner
   * => <instance_BaseAnonymousInner>.varAccessInner.fieldInner
   */
};

int main(int argc, char **argv) {

  struct Base s_base;
  s_base.fieldBase = 1;
  s_base.varInner.fieldInner = 2;
  s_base.varAnotherInner.fieldInner = 3;

  printBase(&s_base);

  struct BaseAnonymousInner s_base_a;
  s_base_a.fieldBase = 1;
  s_base_a.fieldInner = 2; // if varAccessInner is not written then
                           // we can access fieldInner directly

  /* if varAccessInner is written
   * then we have to use it to access fieldInner
   */
  // s_base_a.varAccessInner.fieldInner = 2;

  BREAK_LINE
  printBaseAnonymousInner(&s_base_a);

  return 0;
}

void printBase(const struct Base *base) {
  printf("%d\n", base->fieldBase);
  printf("  -%d\n", base->varInner.fieldInner);
  printf("  -%d\n", base->varAnotherInner.fieldInner);
}

void printBaseAnonymousInner(const struct BaseAnonymousInner *base_inner) {
  printf("%d\n", base_inner->fieldBase);
  printf("  -%d\n", base_inner->fieldInner);
  /* if varAccessInner is present in struct definition
   * then we have to use it to access fieldInner
   */
  // printf("  -%d\n", base_inner->varAccessInner.fieldInner);
}
