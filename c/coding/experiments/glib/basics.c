// --------------------------------------------------------------------------------
// https://developer.ibm.com/tutorials/l-glib/
// https://developer.gnome.org/glib/stable/glib-Doubly-Linked-Lists.html#g-list-foreach
// https://gitlab.gnome.org/GNOME/glib/-/blob/master/glib/glist.c
// --------------------------------------------------------------------------------

#include <glib.h>
#include <stdio.h>

int main(int argc, char **argv) {
  GList *list = NULL;

  list = g_list_append(list, "Hello world!");
  char *str = g_list_first(list)->data;

  printf("The first item is '%s'\n", str);

  return 0;
}
