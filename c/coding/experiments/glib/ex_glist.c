// --------------------------------------------------------------------------------
// https://developer.ibm.com/tutorials/l-glib/
// --------------------------------------------------------------------------------

#include <stdio.h>
#include <glib.h>

typedef int(*pf)(int);
typedef int(*ppf)(pf, int);

int main(int argc, char** argv) {
     GList* list = NULL;

     list = g_list_append(list, "Hello world!");
     list = g_list_prepend(list, "titi_1");
     list = g_list_prepend(list, "titi_2");
     list = g_list_prepend(list, "titi_3");
     list = g_list_prepend(list, "titi_4");

     int f(int a) {
          return a;
     }

     int ff(pf p, int a) {
          return p(a);
     }

     printf("%d\n", ff(f, 3));

     struct s {
          int val;
          const char* name;
     } inst_struct = {10, "id_0"};

     list = g_list_prepend(list, &inst_struct);

     int v = ((struct s*)(g_list_first(list)->data))->val;
     const char* id = ((struct s*)(g_list_first(list)->data))->name;
     
     printf("%d | %s\n", v, id);

     return 0;
}
