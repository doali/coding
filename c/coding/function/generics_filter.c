#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

typedef bool (*predicate)(void *);

static void msg_err_null_pointer()
{
    errno = EFAULT;
    perror("NULL pointer");
    exit(1);
}

static void print_number(int *const p_pElement)
{
    if (p_pElement != NULL)
    {
        printf("%d", *p_pElement);
    }
    else
    {
        msg_err_null_pointer();
    }
}

static size_t filter(void **p_pDest, void *p_pSrc, size_t const p_NbElement, size_t const p_SzElement, predicate p_Predicate)
{
    size_t l_SizeDest = 0;

    if (p_pSrc == NULL)
    {
        msg_err_null_pointer();
    }
    else
    {
        void *data = malloc(sizeof(void *) * p_NbElement);
        memset(data, 0, sizeof(void *) * p_NbElement);

        for (long unsigned int l_Index = 0; l_Index < p_NbElement; ++l_Index)
        {
            if (p_Predicate(p_pSrc + (l_Index * p_SzElement)))
            {
                memcpy(data + (l_SizeDest * p_SzElement), p_pSrc + (l_Index * p_SzElement), sizeof(void *));

		//DEBUG
                // printf("%d == ", ((int*)data)[l_SizeDest]);
                // print_number((void*)(data + l_SizeDest * // p_SzElement));
                // printf(" == ");
                // print_number((void*)(// p_// pSrc + l_Index * // p_SzElement));
                // printf("\n");

                l_SizeDest++;
            }
        }

        *p_pDest = data;
    }

    return l_SizeDest;
}

static bool heaven(int * const p_Element)
{
    return *p_Element % 2 == 0;
}

static void print_list(void *const p_pArr, size_t const p_NbElement, size_t const p_SzElement, void (*p_fpPrint_element)(void *const p_pElement))
{
    long unsigned int l_Index = 0;

    if (p_pArr != NULL)
    {
        printf("[");

        if (p_NbElement > 1)
        {
            for (l_Index = 0; l_Index < p_NbElement - 1; ++l_Index)
            {
                p_fpPrint_element(p_pArr + (l_Index * p_SzElement));
                printf(" ");
            }
        }

        if (p_NbElement > 0)
        {
            p_fpPrint_element(p_pArr + (l_Index * p_SzElement));
        }

        printf("]\n");
    }
    else
    {
        msg_err_null_pointer();
    }
}

int main(int argc, char **argv)
{
    const size_t NB_ELMENT = 8;
    const size_t SZ_ELEMENT = sizeof(int);
    int l_Arr[] = {0, 1, 2, 3, 4, 5, 6, 7};

    int *p_pDest = NULL;
    size_t l_SizeDest = 0;

    print_list(l_Arr, NB_ELMENT, SZ_ELEMENT, (void (*)(void *))print_number);
    l_SizeDest = filter((void**)(&p_pDest), l_Arr, NB_ELMENT, SZ_ELEMENT, (bool (*)(void *))heaven);
    print_list(p_pDest, l_SizeDest, SZ_ELEMENT, (void (*)(void *))print_number);

    if (l_SizeDest > 0)
    {
        free(p_pDest);
    }

    return 0;
}
