#include "glob_and_static_base.c"
#include <stdio.h>

int GLB_A = 10;
static int ST_GLB_A = 20;

extern int get_st_glb_a() {
  printf("BASE:%d\n", GLB_BASE);
  return ST_GLB_A;
}
void set_st_glb_a(int k) {
  printf("BASE:%d\n", ST_GLB_BASE);
  ST_GLB_A = k;
}

int get_st_glb_base() { return ST_GLB_BASE; }
