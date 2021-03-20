#include "character.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

s_character *create(int id, const char *pseudo) {
  s_character *s_c = malloc(sizeof(s_character));

  if (s_c == NULL) {
    return NULL;
  }

  s_c->id = id;

  size_t sz_pseudo = strlen(pseudo);

  strncpy(s_c->pseudo, pseudo, sz_pseudo);
  if (sz_pseudo >= SZ_PSEUDO) {
    s_c->pseudo[SZ_PSEUDO - 1] = '\0';
  }

  return s_c;
}

void delete (s_character *s_c) { free(s_c); }

void print(const s_character *character) {
  printf("id:%2u, pseudo:%s", character->id, character->pseudo);
}

void println(const s_character *character) {
  print(character);
  printf("\n");
}
