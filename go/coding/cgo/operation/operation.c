#include "operation.h"

int op_add(int a, int b) { return a + b; }

extern int op_sub(int a, int b) { return a - b; }

int op_mul(int a, int b) { return a * b; }

int op_div(int a, int b) { return a / b; }

char* affiche(void)
{
    return "coucou fred";
}

void s_address_init(struct s_address* p)
{
    p->number = 1;
    p->street = "adresse";
    p->postal_code = 92270;
    p->s_titi.lol = 2;
}