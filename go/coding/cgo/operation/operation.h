#ifndef _OPERATION_H
#define _OPERATION_H

extern int op_add(int, int);
extern int op_sub(int, int);
int op_mul(int, int);
int op_div(int, int);

char* affiche(void);

struct titi
{
    int lol;
};

typedef enum status {
    STATUS_KO,
    STATUS_OK
} e_status;

typedef struct s_address {
  unsigned int number;
  const char *street;
  unsigned int postal_code;
  struct titi titi;
  enum status status;
} s_address;

void s_address_init(struct s_address* p);

#endif
