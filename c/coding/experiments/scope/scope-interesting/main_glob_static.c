#include <stdio.h>

int GLB_M = 1;           // global variable, scope : all files
static int ST_GLB_M = 2; // global variable, scope : this file

extern int GLB_A;          // definition elsewhere
extern int get_st_glb_a(); // definition elsewhere
void set_st_glb_a(int k);  // definition elsewhere
extern int GLB_BASE;       // definition elsewhere
int get_st_glb_base();     // definition elsewhere

int main(int argc, char **argv) {
  printf("%d\n", GLB_M);
  printf("%d\n", ST_GLB_M);
  printf("%d\n", GLB_A);
  printf("%d\n", get_st_glb_a());

  printf("%d\n", ++GLB_M);
  printf("%d\n", ++ST_GLB_M);
  printf("%d\n", ++GLB_A);
  set_st_glb_a(23);
  printf("%d\n", get_st_glb_a());

  printf("%d\n", GLB_BASE);
  printf("%d\n", get_st_glb_base());

  return 0;
}
