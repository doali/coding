/*
 * ----------------------------------------------------------------------------
 * Time
 * https://linux.die.net/man/3/sleep
 * https://stackoverflow.com/a/4184493
 * https://stackoverflow.com/a/1157217
 * -----------------------------------------------------------------------------
 * Cursor position
 * https://stackoverflow.com/a/26423857
 * -----------------------------------------------------------------------------
 * C thread
 * https://openclassrooms.com/fr/courses/1513891-la-programmation-systeme-en-c-sous-unix/1514567-les-threads
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define LOG 0 // ou bien gcc -DLOG=1 progress_bar.c -lpthread
#define PRINT_LOG(X)                                                           \
  if (LOG) {                                                                   \
    printf("%s\n", X);                                                         \
  }

#define ERROR_PTHREAD                                                          \
  {                                                                            \
    perror("pthread error\n");                                                 \
    return EXIT_FAILURE;                                                       \
  }

// -----------------------------------------------------------------------------
const char TAB_SYMBOL[] = {'|', '/', '-', '|', '\\'};
char ALIVE = 0;

// -----------------------------------------------------------------------------
void *thread_timer(void *arg);
void *thread_idle(void *arg);

void idle(void);

// -----------------------------------------------------------------------------
void idle() {
  while (ALIVE) {
    printf("%c\033[1D", TAB_SYMBOL[rand() % 5]);
    usleep(500);
  }
  PRINT_LOG("End\n")
};

void *thread_timer(void *arg) {

  PRINT_LOG("INSIDE THREAD\n")
  char max = 0;
  char tab[10] = {'\0'};
  do {
    sleep(1);
    tab[max] = '.';
    printf("%d|%s\n", max, tab);
    ++max;
  } while (max < 10);
  ALIVE = 0;

  /* Pour enlever le warning */

  (void)arg;

  pthread_exit(NULL);
}

void *thread_idle(void *arg) {

  PRINT_LOG("INSIDE THREAD\n")

  /* Pour enlever le warning */

  (void)arg;

  idle();
  pthread_exit(NULL);
}

int main(void) {

  pthread_t pth_timer;
  pthread_t pth_idle;

  ALIVE = 1;

  // Create
  if (pthread_create(&pth_timer, NULL, thread_timer, NULL))
    ERROR_PTHREAD

  if (pthread_create(&pth_idle, NULL, thread_idle, NULL))
    ERROR_PTHREAD

  // Join
  if (pthread_join(pth_timer, NULL))
    ERROR_PTHREAD

  if (pthread_join(pth_idle, NULL))
    ERROR_PTHREAD

  return EXIT_SUCCESS;
}
