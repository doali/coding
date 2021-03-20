#ifndef _CHARACTER
#define _CHARACTER

#define SZ_PSEUDO 20

struct character {
  int id;
  char pseudo[SZ_PSEUDO];
};

typedef struct character s_character;

#endif
