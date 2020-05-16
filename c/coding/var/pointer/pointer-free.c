#include <stdio.h>
#include <stdlib.h>

#define FREE(X)                                                                \
  if (X != NULL) {                                                             \
    printf("Must be free => <%p>\n", X);                                       \
    free(X);                                                                   \
    X = NULL;                                                                  \
  } else {                                                                     \
    printf("Nothing to do with => <%p>\n", X);                                 \
  }

int main(int argc, char **argv) {
  int i_stack = 10;
  printf("<%p>\n", &i_stack);
  printf("\t[%d]\n", i_stack);

  int *i_heap = (int *)malloc(sizeof(int));
  *i_heap = 20;
  printf("<%p|%p>\n", &i_heap, i_heap);
  printf("\t[%d]\n", *i_heap);

  FREE(i_heap) // OK

  free(&i_stack); // JOKE...
  /*
   * ------------------------------------------------
   * $ ./stack
   * ------------------------------------------------
   * stack.c: In function ‘main’:
   *stack.c:25:3: warning: attempt to free a non-heap object ‘i_stack’
   *[-Wfree-nonheap-object] free(&i_stack);
   *   ^~~~~~~~~~~~~~
   *<0x7fff30f89b7c>
   *	[10]
   *<0x7fff30f89b80|0x561e741b6670>
   *	[20]
   *Must be free => <0x561e741b6670>
   *munmap_chunk(): invalid pointer
   *Aborted (core dumped)
   * ------------------------------------------------
   */

  free(malloc(sizeof(int))); // OK...

  return 0;
}
