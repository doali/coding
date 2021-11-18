#include <stdio.h>
#include <stdlib.h>

static unsigned int* lst_mod_3_5(const unsigned int* const lst, const unsigned int sz, unsigned int* res_sz)
{
        if (sz == 0 || res_sz == NULL) return NULL;

        unsigned int res[sz];
        int dispo = 0;

        for (unsigned int i = 0; i < sz; i++) {
                if ((lst[i] % 3) == 0 || (lst[i] % 5) == 0) {
                        res[dispo++] = lst[i];
                };
        }

        *res_sz = dispo;
        unsigned int* r = malloc(sizeof(unsigned int) * (dispo));
        for (unsigned int i = 0; i < dispo; i++) {
                r[i] = res[i];
        }

        return r;
}

static void affiche(const unsigned int* const lst, const unsigned int sz)
{
        if (lst == NULL || sz == 0) return; 

        for(unsigned int i = 0; i < sz; i++) {
                printf("%d ", *(lst + i));
        }
        printf("\n");
}

int main(int narg, char** varg)
{
        const unsigned int SIZE = 13;
        unsigned int in[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
        unsigned int* res = NULL;
        unsigned int res_sz;

        res = lst_mod_3_5(in, SIZE, &res_sz);
        affiche(res, res_sz);

        if (res != NULL) free(res);

        return 0;
}