#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char **argv) {
  LOG(char *p_a = "a";, p_a);
  LOG(const char *p_b = "b";, p_b);
  LOG(char *const p_c = "c";, p_c);
  LOG(const char *const p_d = "d";, p_d);
  LOG(char *restrict r_p_a = "r";, r_p_a);
  LOG(const char *restrict r_p_b = "s";, r_p_b);
  LOG(char *const restrict r_p_c = "t";, r_p_c);
  LOG(const char *const restrict r_p_d = "u";, r_p_d);

  return EXIT_SUCCESS;
}
