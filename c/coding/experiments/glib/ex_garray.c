// --------------------------------------------------------------------------------
// https://developer.gnome.org/glib/stable/glib-Pointer-Arrays.html#g-ptr-array-foreach
// --------------------------------------------------------------------------------

#include <glib.h>
#include <stdio.h>

void my_func(gpointer, gpointer);

typedef struct {
  GPtrArray *field_array;
  __uint8_t *field_count;
} s_user_data;

int main()
{
  GPtrArray *gparray;

  gchar *string1 = "one", *string2 = "two", *string3 = "three";

  gparray = g_ptr_array_new ();

  g_ptr_array_add (gparray, (gpointer) string1);
  g_ptr_array_add (gparray, (gpointer) string2);
  g_ptr_array_add (gparray, (gpointer) string3);


  __uint8_t count = 0;

  s_user_data s_u_data= {
    gparray,
    &count  
  };

  //g_ptr_array_foreach(gparray, my_func, (gpointer)&count);
  g_ptr_array_foreach(gparray, my_func, &s_u_data);

  g_ptr_array_free (gparray, TRUE);

  return 0;
}

void my_func(gpointer data, gpointer user_data)
{	  
  if (g_ptr_array_index(((s_user_data*)user_data)->field_array, 0) == (gchar*)data)
  {
    printf("GPtrArray content :\n");
  }
  //__uint8_t *count = (__uint8_t*)user_data;
  __uint8_t *count = (__uint8_t*)((s_user_data*)user_data)->field_count;
  (*(count))++;
  //*count = *count + 1;
  printf("%u - %s\n", *count, (gchar*)data);
}
