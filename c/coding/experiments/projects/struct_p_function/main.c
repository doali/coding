#ifndef _MAIN
#define _MAIN

#include "character.h"
#include <stdlib.h>
#include <string.h>

#include <stdio.h>

extern s_character *create(int, const char *);
extern void delete (s_character *);
extern void print(s_character *);
extern void println(s_character *);

typedef void (*f_action)(s_character *);

void handle(s_character **players, const int sz_players, f_action action) {
  for (int i_player = 0; i_player < sz_players; ++i_player) {
    action(players[i_player]);
  }
}

s_character **create_players(const int sz_players, s_character **const players,
                             const char **const pseudo_players) {
  for (int i_player = 0; i_player < sz_players; ++i_player) {
    players[i_player] = create(i_player, pseudo_players[i_player]);
  }

  return players;
}

int main(int nargs, char **argsv) {
  const int NB_PLAYERS = 4;
  const char *pseudo_players[] = {"player_0", "player_1", "player_2",
                                  "player_3"};
  s_character *players[NB_PLAYERS];

  // Creation des joueurs
  create_players(NB_PLAYERS, players, pseudo_players);

  // Action
  handle(players, NB_PLAYERS, println);

  // Liberation
  handle(players, NB_PLAYERS, delete);

  return EXIT_SUCCESS;
}

#endif
