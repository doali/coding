#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG(INSTRUCTION, Z)                                                    \
  do {                                                                         \
    printf(#INSTRUCTION "\n");                                                 \
    INSTRUCTION /*                                                             \
                 * IMPORTANT                                                   \
                 * - ne pas mettre de ;                                        \
                 * - car dans LOG(<instruction>, <pointeur>)                   \
                 *   - on a ajoute le ; dans <instruction>                     \
                 */                                                            \
        printf("%c\n", *Z);                                                    \
  } while (0)

void p_format(int width, const char *str);
void note(void);

int main(int argc, char **argv) {
  LOG(char *p_a = "a";, p_a);
  LOG(const char *p_b = "b";, p_b);
  LOG(char *const p_c = "c";, p_c);
  LOG(const char *const p_d = "d";, p_d);
  LOG(char *restrict r_p_a = "r";, r_p_a);
  LOG(const char *restrict r_p_b = "s";, r_p_b);
  LOG(char *const restrict r_p_c = "t";, r_p_c);
  LOG(const char *const restrict r_p_d = "u";, r_p_d);

  note();

  return EXIT_SUCCESS;
}

void p_format(int width, const char *str) {
  if (!(width > 0))
    return;

  if (!str)
    return;

  size_t n_width = strlen(str) / width;
  size_t modulo = strlen(str) % width;

  while (n_width > 0) {
    printf("%4lu| ", n_width);
    printf("%.*s|\n", width, str);
    str += width;
    --n_width;
  }

  if (modulo) {
    printf("%4lu|", n_width);
    printf("%.*s|\n", (int)modulo, str + (n_width * width));
  }

  return;
}

void note(void) {
  printf("----------------------------------------\n");
  printf("Mot clef:restrict\n\n");

  p_format(70, "When we use restrict with a pointer ptr, it tells the compiler "
               "that ptr "
               "is the only way to access the object pointed by it and "
               "compiler doesn't "
               "need to add any additional checks.");

  printf("----------------------------------------\n");
  printf("%s\n", "https://www.geeksforgeeks.org/restrict-keyword-c/");
  printf("%s\n", "https://fr.wikipedia.org/wiki/Restrict");
  printf("----------------------------------------\n");

  return;
}
