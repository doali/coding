#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <string.h>

// -----------------------------------------------------------------------------
// Utilisation
// -----------------------------------------------------------------------------
//% ./write-args fichiersortie "premier arg" "deuxième arg" "troisème arg"
//% cat outputfile
//premier arg
//deuxième arg
//troisième arg
// -----------------------------------------------------------------------------

int main (int argc, char* argv[])
{
  int fd;
  struct iovec* vec;
  struct iovec* vec_next;
  int i;

  /* Nous aurons besoin d'un "tampon" contenant un caractère de nouvelle ligne.
  Nous utilisons une variable char normale pour cela. */
  char newline = '\n';

  /* Le premier argument est le nom du fichier de sortie. */
  char* filename = argv[1];

  /* Ignore les deux premiers éléments de la liste d'arguments. L'élément
  à l'indice 0 est le nom du programme et celui à l'indice 1 est
  le nom du fichier de sortie. */
  argc -= 2;
  argv += 2;

  /* Alloue un tableau d'éléments iovec. Nous aurons besoin de deux élements pour
  chaque argument, un pour le texte proprement dit et un pour
  la nouvelle ligne. */
  vec = (struct iovec*) malloc (2 * argc * sizeof (struct iovec));

  /* Boucle sur la liste d'arguments afin de construire les éléments iovec. */
  vec_next = vec;
  for (i = 0; i < argc; ++i) {
    /* Le premier élément est le texte de l'argument. */
    vec_next->iov_base = argv[i];
    vec_next->iov_len = strlen (argv[i]);
    ++vec_next;
    /* Le second élement est un caractère de nouvelle ligne. Il est possible
    de faire pointer plusieurs éléments du tableau de struct iovec vers
    la même région mémoire. */
    vec_next->iov_base = &newline;
    vec_next->iov_len = 1;
    ++vec_next;
  }
  
  /* Écrit les arguments dans le fichier. */
  fd = open (filename, O_WRONLY | O_CREAT);
  writev (fd, vec, 2 * argc);
  close (fd);
  free (vec);

  return 0;
}
