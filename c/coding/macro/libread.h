#ifndef _LIBREAD_H
#define _LIBREAD_H

#include <stdio.h>

/**
 */
typedef enum { CHAR = 0, LINE } e_mode;

/**
 */
typedef int (*fun_read)(FILE *);

/**
 */
int read_file_by_char(const char *);

/**
 */
int read_file_by_line(const char *);

/**
 */
int read_file(const char *, e_mode);

/**
 */
int r_file_char(FILE *);

/**
 */
int r_file_line(FILE *);

#endif
