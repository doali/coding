#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FREE(X)                                                                \
  do {                                                                         \
    if (X != NULL) {                                                           \
      free(X);                                                                 \
      X = NULL;                                                                \
    }                                                                          \
  } while (0)

static const unsigned int G_ARR_SZ = 10;
static int G_ARR[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

static void
print_int(int const p_element)
{
  printf("%d ", p_element);
}

static void*
handle_arr(void* const p_arr,
           size_t const p_size_element,
           unsigned int const p_size_arr,
           void (*p_pf)(void*))
{
  for (unsigned int l_ite = 0; l_ite < p_size_arr; ++l_ite) {
    void* l_element = p_arr + (l_ite * p_size_element);
    p_pf(*(void**)l_element);
  }

  return p_arr;
}

static void
print_arr(void* const p_arr,
          size_t const p_size_element,
          unsigned int const p_size_arr,
          void (*p_pf)(void*))
{
  (void)handle_arr(
    p_arr, p_size_element, p_size_arr, (void (*)(void*))print_int);
  printf("\n");
}

static bool
heaven(int const p_element)
{
  return p_element % 2 == 0;
}

static unsigned int
filter_arr(void* const p_dest,
           void* const p_src,
           size_t const p_size_element,
           unsigned int const p_size_arr,
           bool (*p_pf)(void*))
{
  unsigned int l_cursor = 0;

  for (unsigned int l_ite = 0; l_ite < p_size_arr; ++l_ite) {
    void* l_element = p_src + (l_ite * p_size_element);
    bool l_predicat = p_pf(*(void**)(l_element));
    if (l_predicat) {
      memcpy(p_dest + (l_cursor * p_size_element), l_element, p_size_element);
      ++l_cursor;
    }
  }

  return l_cursor;
}

int
main(int argc, char** arg)
{
  print_arr(G_ARR, sizeof(int), G_ARR_SZ, (void (*)(void*))print_int);

  int* l_dest = malloc(sizeof(int) * G_ARR_SZ);
  unsigned int l_dest_size =
    filter_arr(l_dest, G_ARR, sizeof(int), G_ARR_SZ, (bool (*)(void*))heaven);
  print_arr(l_dest, sizeof(int), l_dest_size, (void (*)(void*))print_int);

  FREE(l_dest);

  return 0;
}
